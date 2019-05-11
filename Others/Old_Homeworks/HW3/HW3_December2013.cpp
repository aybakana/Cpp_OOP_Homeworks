#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

#define MAX 20

template <class any_type>
class myset{

	public:
	int N;
	any_type array[MAX];
	void print();
	bool operator !();

};

template <class any_type>
void myset<any_type>::print(){

	int index = 0;

	for(index = 0;index<N;index++){
		cout << index << " element = " << array[index]  << endl;
	}

}

template <class any_type>
bool myset<any_type>::operator!(){
	if(0 == N){
		return true;
	}else{
		return false;
	}
}

template <class any_type>
bool operator<(myset <any_type> ob1,myset<any_type> ob2){
	int index = 0,index2 = 0;
	if(ob1.N > ob2.N){
		return false;
	}else{
		for(index = 0; index < ob1.N; index++){
			while(ob1.array[index2] != ob2.array[index]){
				index2++;
				if(index2 > ob1.N){
					return false;
				}
			}
			index2 = 0;
		}
		return true;
	}
}


template <class any_type>
bool operator==(myset <any_type> ob1,myset<any_type> ob2){
	int index = 0,index2 = 0;
	if(ob1.N != ob2.N){
		return false;
	}else{
		for(index = 0; index < ob1.N; index++){
			while(ob1.array[index2] != ob2.array[index]){
				index2++;
				if(index2 > ob1.N){
					return false;
				}
			}
			index2 = 0;
		}
		return true;
	}
}

template <class any_type>
myset<any_type> operator-(myset <any_type> ob1,myset<any_type> ob2){
	int index = 0,index2 = 0;
	myset <any_type> ob3;
	int new_array_index = 0;
		for(index = 0; index < ob1.N; index++){
			while(ob2.array[index2] != ob1.array[index]){
				index2++;
				if(index2 > ob2.N){
					ob3.array[new_array_index] = ob1.array[index];
					new_array_index++;
					break;
				}
			}
			index2 = 0;
		}
		ob3.N = new_array_index;
		return ob3;
}

template <class any_type>
myset <any_type> operator& (myset<any_type> ob1, myset<any_type> ob2){
	int index = 0, index2 = 0,break_flag = 0,new_array_index = 0;
	myset <any_type> ob3;

	for(index = 0; index < ob1.N; index++){
		while(ob1.array[index2] != ob2.array[index]){
			index2++;
			if(index2 > ob1.N){
				break_flag = 1;
				break;
			}
		}
	if((break_flag == 0) && (index2 < ob1.N)){
		ob3.array[new_array_index] = ob2.array[index];
		new_array_index++;
	}
	index2 = 0;
	break_flag = 0;
	}
	ob3.N = new_array_index;

	return ob3;

}

template <class any_type>
myset <any_type> operator|(myset <any_type> ob1,myset<any_type> ob2){
	int index = 0, index2 = 0,index3 = 0;
	myset <any_type> ob3;

	myset <any_type> ob2_ob1;
	myset <any_type> ob1_ob2;
	myset <any_type> intersect_ob1_ob2;

	ob2_ob1 = ob2 - ob1;

	ob1_ob2 = ob1 - ob2;
	
	intersect_ob1_ob2 = ob2 & ob1;

	for(index = 0; index < ob2_ob1.N; index++){
		ob3.array[index] = ob2_ob1.array[index];
	}
	for(index2 = 0; index2 < ob1_ob2.N; index2++){
		ob3.array[index+index2] = ob1_ob2.array[index2];
	}
	for(index3 = 0; index3 <intersect_ob1_ob2.N;index3++){
		ob3.array[index + index2 + index3] = intersect_ob1_ob2.array[index3];
	}

	ob3.N = ob2_ob1.N + ob1_ob2.N + intersect_ob1_ob2.N;
	
	return ob3;
}

template <class any_type>
bool operator^(myset <any_type> ob1,myset<any_type> ob2){
	myset <any_type> ob3;

	ob3 = ob1 & ob2;

	if(ob3.N == 0){
		return false;
	}else{
		return true;
	}
}

int main(){
	bool empty_set,empty_set2,subset,equality,disjoint,disjoint2;
	myset <string> x1 = {5,"Ahmet","Mehmet","Bulent","Fuat", "Cemal"};
	myset <string> x2 = {3,"Kemal","Cemal","Mehmet"};
	myset <int> y1 = {3,10,20,30};
	myset <int> y2 = {4,100,200,300,400};
	myset <string> z1;
	myset <int>	   z2;
	myset <string> u={0};

	cout<<"Is empty set"<<endl;

	empty_set = !x1;
	empty_set2 = !u; 

	cout<<empty_set<<endl;
	cout<<empty_set2<<endl;

	cout<<"end of empty set operand"<<endl;
	cout<<"\n"<<endl;

	cout<<"Is subset set"<<endl;

	subset = x1 < x2;
	cout<<subset<<endl;
	
	cout<<"end of empty set operand"<<endl;
	cout<<"\n"<<endl;

	cout<<"Is equal"<<endl;

	subset = y1 == y2;
	cout<<subset<<endl;
	
	cout<<"end of equal operand"<<endl;
	cout<<"\n"<<endl;

	cout<<"Is disjoint set"<<endl;

	disjoint = x1 ^ x2;
	disjoint2 = y1 ^ y2; 

	cout<<disjoint<<endl;
	cout<<disjoint2<<endl;

	cout<<"end of empty set operand"<<endl;
	cout<<"\n"<<endl;

	cout<<"Union"<<endl;

	z1 = x1 | x2;
	z2 = y1 | y2;

	z1.print();
	z2.print();

	cout<<"end of Union operand"<<endl;
	cout<<"\n"<<endl;

	cout<<"difference"<<endl;
	z1 = x1 - x2;
	z2 = y1 - y2;

	z1.print();
	z2.print();

	cout<<"end of difference operand"<<endl;
	cout<<"\n"<<endl;

	cout<<"Intersection"<<endl;

	z1 = x1 & x2;
	z2 = y1 & y2;

	z1.print();
	z2.print();

	cout<<"end of Intersection operand"<<endl;
	cout<<"\n"<<endl;

	getch();
}