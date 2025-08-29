#include <iostream>
using namespace std ;

int main(){
	int numStudents;
	int *courses ;
	int **marks ;
	
	cout << "Enter the number of students: " ;
	cin >> numStudents ;
	marks = new int* [numStudents] ;
	courses = new int [numStudents] ;
	
	for(int i=0;i<numStudents;i++){
		cout << "Enter number of courses for student " << i+1 << ": " ;
		cin >> courses[i] ;
	}
	for(int i=0;i<numStudents;i++){
		marks[i] = new int[courses[i]] ;
	}
	
	for(int i=0;i<numStudents;i++){
		for(int j=0;j<courses[i];j++){
		    cout << "Enter marks of student " << i+1 << " in course " << j+1 << ": " ;
		    cin >> marks[i][j] ;
		}
	}
    int totalMarks = 0 ;
    double avg ;
    cout << "Averages:\n" ; 
	for(int i=0;i<numStudents;i++){
		cout << "Student " << i+1 << " Average: ";
		for(int j=0;j<courses[i];j++){
		    totalMarks += marks[i][j] ;
	    }
	    avg = totalMarks / courses[i] ;
	    cout << avg << endl ;
	    totalMarks = 0 ;
    }
	
	for(int i=0;i<numStudents;i++){
		delete[] marks[i] ;
	}
	delete[] marks ;
	delete[] courses ;   
}