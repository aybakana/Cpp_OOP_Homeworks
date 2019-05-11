#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#define N 20 // Maximum number of words
#define LEN 15 // Maximum length of a word
using namespace std;


class CourseCatalog{
	public:
	string course_code;
	string course_title;
	float credits;
};


class CourseSection{

	public:
				int enrolled_student_number ;

	int CRN;
	string Course_Code;
	string AllowedMajors[N];
	int Student_IDs[N];
	CourseSection();
	bool AddStudent(int) ;
	bool RemoveStudent(int) const;
	bool PrintStudentsEnrolled() const;

};



class Student{
public:
	Student();
	int ID;

	int CourseCRNs[N];
	int enrolled_class;
	string FirstName;
	string LastName;
	string MajorCode;

	void AddCourse(int) const;
	void DropCourse(int) const;
	void PrintCoursesEnrolled() const;
	int CalculateTotalCredits() ;
};


int counter_section = 0;
int counter_student = 0;
	CourseSection *sections;
	CourseCatalog *courses;


CourseSection::CourseSection(){
	int line_count = 0,a = 0;
	enrolled_student_number = 0;
	string line[100];
	ifstream infile("SECTIONS.txt");

		while(!infile.eof()){
		while (getline(infile, line[counter_section], '\n'))
		{
			istringstream iss(line[counter_section]);
			int a, b;
			if (!(iss >> a >> b)) { break; } // error
		}
		counter_section++;


	}
		infile.close();
	enrolled_student_number++;
};


Student::Student(){
	int line_count = 0,a = 0;

	string line[500];

	ifstream infile("STUDENTS.txt");

		while(!infile.eof()){
		while (getline(infile, line[counter_student], '\n'))
		{
			istringstream iss(line[counter_student]);
			int a, b;
			if (!(iss >> a >> b)) { break; } // error
		}
		counter_student++;


	}
		counter_student = 0;
		infile.close();

};

void tokenlara_ayir( char * cumle, char dizi[N][LEN])
// Input : cumle
// Output : dizi
{
	int i=0;
	char *tokenPtr; // Define word pointer
	tokenPtr = strtok( cumle, " " ); // Begin tokenizing sentence.
	// Continue tokenizing sentence until tokenPtr becomes NULL.
	while ( tokenPtr != NULL ) {
		strcpy(dizi[i] , tokenPtr );
		i++;
		tokenPtr = strtok( NULL, " " ); // Get next token
	}
}


ifstream infile("CATALOG.txt");

void read_catalog(){
	char str[10];
	char tab2[200];
	char kelimeler[N][LEN];

	string line[100];
	int counter = 0, line_count = 0,i,a = 0,section_count = counter_section;

	while(!infile.eof()){
		while (getline(infile, line[line_count], '\n'))
		{
			istringstream iss(line[a]);
			int a, b;
			if (!(iss >> a >> b)) { break; } // error
		}
		counter++;
	}
	courses = new CourseCatalog[counter];
ifstream infile("CATALOG.txt");

	while(!infile.eof()){
		while (getline(infile, line[a], '\n'))
		{
			istringstream iss(line[a]);
			int a, b;
			if (!(iss >> a >> b)) { break; } // error
			a++;


		}

		strcpy(tab2, line[a].c_str());

		for (i=0; i< N; i++)
		strcpy(kelimeler[i] , "");
		tokenlara_ayir(tab2, kelimeler);

		for (i=0; i< N; i++)
		if (strcmp(kelimeler[i], "") != 0 )
		//cout << i+1 << " = " << kelimeler[i]<< endl;

		courses[line_count].course_code = atoi(kelimeler[0]);
		courses[line_count].course_title = kelimeler[1];
		courses[line_count].credits =atof(kelimeler[2]) ;
		line_count++;
	}
	infile.close();


};

void read_sections(){
	char str[10];
	char tab2[200];
	char kelimeler[N][LEN];
	int counter = 0, line_count = 0,i,a = 0,section_count = counter_section;

	string line[100];
	CourseSection s1;
		ifstream infile2("SECTIONS.txt");
		sections = new CourseSection[counter_section];
		while(!infile2.eof()){
		while (getline(infile2, line[a], '\n'))
		{
			istringstream iss(line[a]);
			int a, b;
			if (!(iss >> a >> b)) { break; } // error
			a++;


		}

		strcpy(tab2, line[a].c_str());

		for (i=0; i< N; i++)
		strcpy(kelimeler[i] , "");
		tokenlara_ayir(tab2, kelimeler);
		//cout<<kelimeler[0]<<endl;

		sections[line_count].CRN = atoi(kelimeler[0]);
		sections[line_count].Course_Code = kelimeler[1];
		for(i = 0;i<N;i++){
			sections[line_count].AllowedMajors[i] = kelimeler[i+2];
		}

		line_count++;
	}
}
	Student *reg_students;


void read_students(){
	char str[10];
	char tab2[200];
	char kelimeler[N][LEN];
	int counter = 0, line_count = 0,i,a = 0,student_count = counter_student;

	string line[500];
	Student s1;
	ifstream infile2("STUDENTS.txt");
	reg_students = new Student[134];

	while(!infile2.eof()){
	while (getline(infile2, line[a], '\n'))
	{
		istringstream iss(line[a]);
		int a, b;
		if (!(iss >> a >> b)) { break; } // error
		a++;


	}

	strcpy(tab2, line[a].c_str());

	for (i=0; i< N; i++)
	strcpy(kelimeler[i] , "");
	tokenlara_ayir(tab2, kelimeler);


	reg_students[line_count].ID = atoi(kelimeler[0]);
	reg_students[line_count].MajorCode = kelimeler[3];
	reg_students[line_count].enrolled_class = 0;
	line_count++;
	}

}
int Student::CalculateTotalCredits(){
	int value = 0;
	return value;
}
int enrolled_student = 0;
bool CourseSection::AddStudent(int Students_id){
	int counter,counter2;
	for(counter = 0; counter< 134; counter++){
		if((Students_id == reg_students[counter].ID)){
			for(counter2= 0;counter2<N;counter2++){
				if(AllowedMajors[counter2] == reg_students[counter].MajorCode){
				//	if(10 <  reg_students[counter].CalculateTotalCredits()){
						Student_IDs[enrolled_student_number - 1] = reg_students[counter].ID;
						reg_students[counter].CourseCRNs[reg_students[counter].enrolled_class] = CRN;
						reg_students[counter].enrolled_class++;
						enrolled_student_number++;
				//	}
				}
			}

		}
	}
	return 0;
}
int main() {
	char str[10];
	char tab2[200];
	char kelimeler[N][LEN];
	string line[100];
	string transaction;
	read_catalog();
	read_sections();
	read_students();


	int counter = 0, line_count = 0,i,a = 0,section_count = counter_section,counter2,counter3,counter4;

	while(!infile.eof()){
		while (getline(infile, line[line_count], '\n'))
		{
			istringstream iss(line[a]);
			int a, b;
			if (!(iss >> a >> b)) { break; } // error
		}
		counter++;
	}
ifstream infile("TRANSACTIONS.txt");

	while(!infile.eof()){
		while (getline(infile, line[a], '\n'))
		{
			istringstream iss(line[a]);
			int a, b;
			if (!(iss >> a >> b)) { break; } // error
			a++;


		}

		strcpy(tab2, line[a].c_str());

		for (i=0; i< N; i++)
		strcpy(kelimeler[i] , "");
		tokenlara_ayir(tab2, kelimeler);

		for (i=0; i< N; i++)
		if (strcmp(kelimeler[i], "") != 0 )
		//cout << i+1 << " = " << kelimeler[i]<< endl;
		transaction = kelimeler[0];
		if(transaction == "ENROLL"){


		}else if(transaction =="ADD"){
			for(counter2=0;counter2<8;counter2++){
				if(sections[counter2].CRN == atoi(kelimeler[1])){
					sections[counter2].AddStudent(atoi(kelimeler[2]));
				}
			}
		}else if(transaction == "DROP"){

		}else if(transaction == "PRINT_SECTION"){

			for(counter3=0;counter3<counter_section;counter3++){
					if(sections[counter3].CRN == atoi(kelimeler[1])){
													cout<<"\n"<<endl;

						cout<<sections[counter3].CRN;
						for(counter4=0;counter4<sections[counter3].enrolled_student_number-1;counter4++){
																				cout<<"\n"<<endl;

							cout<<sections[counter3].Student_IDs[counter4];

						}
				}
			}
		}else if(transaction == "PRINT_STUDENT"){

		}

		line_count++;
	}
	infile.close();

	return 0;
}
