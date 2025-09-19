#include <iostream>
using namespace std;

int calculateFactorial(int n){
	if(n==1){
		return 1 ;
	}
	return n * calculateFactorial(n-1) ; 
}

int main(){
	cout << "Enter Number: " ;
	int num ;
	cin >> num ;
	if(num>0){
	    cout << "Factorial of this number is: " << calculateFactorial(num) ;	
	}
	else{
		cout << "Invalid Number" ;
	}	
}