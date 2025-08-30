#include <iostream>
using namespace std;

int main(){
	int numDep,numEmp ;
	cout << "Enter the number of departments: " ;
	cin >> numDep ;
	int *size = new int[numDep] ;
	int **salaries = new int *[numDep] ;
	for(int i=0;i<numDep;i++){
		cout << "Enter the number of employees in department " << i+1 << ":" ;
		cin >> size[i] ;
		salaries[i] = new int[numEmp] ;
	}
	for(int i=0;i<numDep;i++){
		for(int j=0;j<size[i];j++){
			cout << "Enter the salary of employee " << j+1 << " of department " << i+1 << " :" ;
			cin >> salaries[i][j] ;
		}
	}
	int max ;
	for(int i=0;i<numDep;i++){
		max = salaries[i][0] ;
		for(int j=1;j<size[i];j++){
			if(salaries[i][j]>max){
				max = salaries[i][j] ;
			}
		}
		cout << "Maximum salary for department " << i+1 << " is " << max << endl ;
	}
	int total ;
	double maxSal = 0 ;
	int depNum ;
	for(int i=0;i<numDep;i++){
		total = 0 ;
		for(int j=0;j<size[i];j++){
			total += salaries[i][j] ;
		}
		if(total/size[i]>maxSal){
			maxSal = total/size[i] ;
			depNum = i+1 ;
		}
	}
	cout << "The department with max average salary is department number " << depNum << endl ;
	for(int i=0;i<numDep;i++){
		delete[] salaries[i] ;
	}
	delete[] salaries ;
	delete[] size ;
}