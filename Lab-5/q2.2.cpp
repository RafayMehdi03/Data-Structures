#include <iostream>
using namespace std;

void functionB(int n) ;

void functionA(int n){
	if(n>=1){
		cout << n << " " ;
		functionB(n-1) ;
	}
}

void functionB(int n){
	if(n>=1){
		cout << n << " " ;
		functionA(n-1) ;
	}
}

int main(){
	cout << "enter a number greater than 0: " ;
	int num ;
	cin >> num ;
	if(num>0){
		functionA(num) ;
	}
	else{
		cout << "You entered an invalid number" ;
	}
}