#include <iostream>
using namespace std;

int sumTail(int n,int total=0){
	if(n==0){
		return total ;
	}
	else{
		total = total + n ;
		return sumTail(n-1,total);
	}
}

int main(){
	cout << "enter a number greater than 0: " ;
	int num ;
	cin >> num ;
	if(num >= 0){
		cout << "Sum of all numbers is: " << sumTail(num);
	}
	else{
		cout << "You entered an invalid number" ;
	}
}