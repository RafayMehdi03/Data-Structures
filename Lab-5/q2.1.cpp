#include <iostream>
using namespace std;

void printNumbers(int n){
	if(n>=1){
		cout << n << " " ;
		printNumbers(n-1) ;
	}
}

int main(){
	cout << "enter a number greater than 0: " ;
	int num ;
	cin >> num ;
	if(num>0){
		printNumbers(num) ;
	}
	else{
		cout << "You entered an invalid number" ;
	}
}