#include <iostream>
#include <cstring>
using namespace std ;

class Exam{
	char* studentName;
	string examDate;
	int examScore;
  public:
  	Exam(char* name){
  		studentName = new char[strlen(name)+1] ;
  		strcpy(studentName,name) ;
	}
	void setDate(string date){
		examDate = date ;
		cout << "Date set to : " << examDate << endl ;
	}
	void setScore(int score){
		examScore = score ;
		cout << "Score set to : " << examScore << endl ;
	}
	void getName(){
		cout << "Name : " << studentName << endl ;
	}
	void getDate(){
		cout << "Date : " << examDate << endl ;
	}
	void getScore(){
		cout << "Score : " << examScore << endl ;
	}
	~Exam() {
       delete[] studentName;
       cout << "Destructor called" << endl;
}
};

int main(){
	Exam e1("Rafay Mehdi") ;
	e1.setDate("25/08/25") ;
	e1.setScore(83) ;
	Exam e2 = e1 ;
	e2.getName() ;
	e2.getDate() ;
	e2.getScore() ;
}

//Both objects trying to delete the same data hence its showing an error that double free detected 