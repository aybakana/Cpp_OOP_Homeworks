/*
   @SUBJECT:    HOMEWORK-3
   @NAME:       ABDULBAKI AYBAKAN
   @NUMBER:     040120523

*/
  #include <iostream>
  #include <fstream>
  #include <string>
  #include <sstream>
  #include <iomanip>
  #include <stdio.h>
  #include <vector>
  #include <map>
  #include <time.h>

  using namespace std;

  class Line{
  public:
    int line_code;
    string line_name;
    string line_craft_type;

    struct CityDistance{
      int city_code;
      int city_distance;
    };
    vector<CityDistance> line_cities;
    int average_speed;
    // Constructor of Line class
    Line(int l_code,string l_name,string l_cr_type,vector<CityDistance> line_city_vector):line_code(l_code),line_name(l_name),line_craft_type(l_cr_type),line_cities(line_city_vector){
        if (line_craft_type=="Boeing") average_speed=600;
        else if (line_craft_type=="Airbus") average_speed=750;
        else if (line_craft_type=="Jetfly") average_speed=700;
        else if (line_craft_type=="Lockheed") average_speed=650;
        else throw "No avaliable craft type!";

    }
    void print_schedule(int st_c_code,int e_c_code){   //  I HAVE PROBLEM ONLY WITH PRINT_SCHEDULE FUNCTION
        cout<<"Departure_City    Departure_Time    Arrival_City    Arrival_Time    Distance(Km)    Travel Duration(Hours)"<<endl;
        cout<<"==============    ==============    ============    ============    ============    ======================"<<endl;
        /*
        tm time_calculation(tm time,float a){
            while(a>1){
                tm.tm_hour++;
                a--;
            }
            tm.tm_min+=a*60;
        }
        tm current_time; // OBJECT OF THE TIME STRUCT
        current_time.hour=7;
        current_time.minute=0;
        */
        for (vector<Line::CityDistance>::iterator m = line_cities.begin();
                                                  m!= line_cities.end();
                                                  ++m)          // ITERATOR FOR STRUCTS // line_cities is the name of vector
        {

        }
        }

  };



int main(){

  try{
  // CITIES MAP CONSTRUCTION
  typedef map<int,string> Cities;  // MAP OF CITIES
  Cities C_map;                      // OBJECT OF CITIES IS NAMED AS C_map

  string lineC;
  ifstream fileIN1;
  fileIN1.open("CITIES.txt");
  if(!fileIN1) throw "No file avaliable!!";

  int c_code;
  string c_name;

  while(!fileIN1.eof()){
    getline(fileIN1,lineC);
    stringstream in(lineC);

    in>>c_code;
    in>>c_name;
    C_map[c_code]=c_name;
    }
    // LINES CONSTRUCTION
    vector<Line> lines;         // VECTOR DEFINITION
    int l_code;
    string l_name;
    string l_c_type;
    vector<Line::CityDistance> l_cities;
    Line::CityDistance c_distance_struct;
    int number_of_cities;

    string lineA;
    ifstream fileIN;

    fileIN.open("LINES.txt");
    if(!fileIN) throw "No file avaliable!!";    // If there is an error, throw the message!
    int k=0;
    cout << "LINES MENU "<<endl<<endl;
    cout << "Line_code   Line_name  Line_craft_type"<<endl;

    while(!fileIN.eof()){

        getline(fileIN,lineA);

        stringstream in(lineA);

        in>>l_code>>l_name>>l_c_type>>number_of_cities;

        for(int i=0;i<number_of_cities;i++){
          in>>c_distance_struct.city_code>>c_distance_struct.city_distance;
          l_cities.push_back(c_distance_struct);
        }
        Line lines_example(l_code,l_name,l_c_type,l_cities);
        lines.push_back(lines_example);
        cout << l_code<< "    "<<l_name<<"    " <<l_c_type<<"    "<< endl;
        k++;
    }
    int line_code_to_enter;
    cout<< "Enter Line Code: ";           //ASKING FOR USER INPUT
    cin>>line_code_to_enter;

    for (vector<Line>::iterator i = lines.begin();
                              i != lines.end();
                              ++i)                  // ITERATOR FOR LINES // lines is the name of vector
    {
        if(i->line_code==line_code_to_enter){
                cout<<" CITIES ON THE SELECTED LINE"<<endl<<endl;
                cout<<"City_code"<<"    "<<"City_name"<<"   "<<"Distance"<<endl;
                for (vector<Line::CityDistance>::iterator k = i->line_cities.begin();
                                                          k!= i->line_cities.end();
                                                          ++k)          // ITERATOR FOR STRUCTS // i->line_cities is the name of vector
                {
                    cout<< k->city_code<<"           "<<C_map[k->city_code] <<"            "<<k->city_distance<<endl;
                }
        int st_c_code,e_c_code;
        cout<<"Enter Start City code and End City code :";
        cin>>st_c_code>>e_c_code;
        i->print_schedule(st_c_code,e_c_code);
      }

    }


    }   // END OF TRY BLOCK
    catch (const char* e){
        cout << e;
    }

    return 0;
  }
