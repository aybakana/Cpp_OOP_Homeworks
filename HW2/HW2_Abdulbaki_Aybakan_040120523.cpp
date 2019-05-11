/*
                	HOMEWORK II
	@NAME         	:           ABDULBAKI AYBAKAN
	@SCHOOL NUMBER	:  			040120523

*/

#include <iostream>
#include <fstream>
#include <array>
#include <sstream>
#include <ostream>
#include <string>
#include <stdio.h>

using namespace std;
class Subscriber{
    protected:
        int ID;
        string fname;
        string lname;
        int consumption_amount;
        int allowed_quota;
	public:
		Subscriber(int id,string f_name,string l_name,int consumpt_am){              // Parametered Constructor Declaration
		    ID=id;fname=f_name;lname=l_name;consumption_amount=consumpt_am;
		}
		float compute_remaining();
		virtual void print(){}
		virtual string get_subscriber_type()=0;                                       // PURE VIRTUAL FUNCTION
};
class Individual:public Subscriber{
	private:
		string option_code;
	public:
		Individual(int id, string f_name, string l_name, int consumpt_am, string opt_code):Subscriber(id,f_name,l_name,consumpt_am){     // Parametered Constructor Declaration
            option_code=opt_code;
            if(option_code=="T") allowed_quota=100;
            if(option_code=="N") allowed_quota=400;
            if(option_code=="P") allowed_quota=2000;
		}
		string get_subscriber_type();                                                 // VIRTUAL FUNCTION
		void print();
};
class Institutional:public Subscriber{
	private:
		string Institution_name;
	public:
		Institutional(int id,string f_name,string l_name,int consumpt_am,string instit_name):Subscriber(id,f_name,l_name,consumpt_am){           // Parametered Constructor Declaration
            Institution_name=instit_name;
            allowed_quota=5000;
		}
		string get_subscriber_type();                                                 // VIRTUAL FUNCTION
        void print();
};

string Institutional::get_subscriber_type(){
    return "S";
}
string Individual::get_subscriber_type(){
    string it,in,ip;
    it="IT";in="IN";ip="IP";
    if(this->option_code=="T") return it;
    if(this->option_code=="N") return in;
    if(this->option_code=="P") return ip;
}
float Subscriber::compute_remaining(){
    float remain;
    remain = allowed_quota - consumption_amount;
    return remain;
}
void Individual::print(){
    cout<<this->ID<<"  "<<this->fname<<"        "<<this->lname<<"       "<<compute_remaining()<<endl;
}
void Institutional::print(){
    cout<<this->ID<<"  "<<this->fname<<"        "<<this->lname<<"       "<<this->Institution_name<<"        "<<this->compute_remaining()<<endl;
}
int main(){
    string lineA;
    ifstream fileIN;

    Subscriber *array_of_subscriber[200];

    int m=0;
    string subs_type;
	string f_name,l_name,instit_name;
	int id,consumpt_am;

    fileIN.open("SUBSCRIBERS.txt");
    while(!fileIN.eof()){
		getline(fileIN,lineA);
		stringstream streamA(lineA);
		streamA>>subs_type;
		streamA>>id;
		streamA>>f_name;
		streamA>>l_name;
		streamA>>consumpt_am;
        if (subs_type=="S")
        {
            streamA>>instit_name;
            array_of_subscriber[m] =new Institutional(id,f_name,l_name,consumpt_am,instit_name);
        }
        else if (subs_type=="IT")
        {
            array_of_subscriber[m] =new Individual(id,f_name,l_name,consumpt_am,"T");
        }
        else if (subs_type=="IN")
        {
            array_of_subscriber[m] =new Individual(id,f_name,l_name,consumpt_am,"N");
        }
        else if (subs_type=="IP")
        {
            array_of_subscriber[m] =new Individual(id,f_name,l_name,consumpt_am,"P");
        }
        instit_name="          ";  // TO clear the institution name
        m++;
    }

    cout << "List of Institutional Subscribers: "<<endl<<endl;
    for(int m=0;m<50;m++){                          // TO CHECK IF IT IS INSTITUTIONAL
        if((array_of_subscriber[m]->get_subscriber_type())=="S") array_of_subscriber[m]->print();
    }
    cout << "List of Individual-Trial Subscribers: "<<endl<<endl;
    for(int m=0;m<50;m++){                          // TO CHECK IF IT IS INDIVIDUAL-TRIAL
        if((array_of_subscriber[m]->get_subscriber_type())=="IT") array_of_subscriber[m]->print();
    }
    cout << "List of Individual-Normal Subscribers: "<<endl<<endl;
    for(int m=0;m<50;m++){                          // TO CHECK IF IT IS INDIVIDUAL-NORMAL
        if((array_of_subscriber[m]->get_subscriber_type())=="IN") array_of_subscriber[m]->print();
    }
    cout << "List of Individual-Premium Subscribers: "<<endl<<endl;
    for(int m=0;m<50;m++){                          // TO CHECK IF IT IS INDIVIDUAL-PREMIUM
        if((array_of_subscriber[m]->get_subscriber_type())=="IP") array_of_subscriber[m]->print();
    }
    for(int m=0;m<50;m++){   // TO DELETE THE EVERY ELEMENT OF THE ARRAY
        delete array_of_subscriber[m];
    }
    return 0;

}

