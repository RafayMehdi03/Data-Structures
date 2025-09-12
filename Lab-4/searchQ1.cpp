#include <iostream>
using namespace std ;

int main(){
	int *array ;
	int n ;
	cout  << "Enter how many elements you want to enter: " ;
	cin >> n ;
	array = new int[n] ;
	for(int i=0;i<n;i++){
		cout << "Enter element " << i+1 << " : " ;
		cin >> array[i] ;
	}
	int target ;
	cout << "Enter the target element: " ;
	cin >> target ;
	for(int i=0;i<n;i++){
		if(array[i]==target){
			cout << "Target Found On Position " << i+1 << endl ;
			return 0;
		}
	}
	cout << "Target Not Found" ;
	delete []array ;
}