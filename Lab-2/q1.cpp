#include <iostream>
using namespace std ;

int main(){
	int size ;
	cout << "Enter the size of your array: " ;
	cin >> size ;
	int *arr = new int[size] ;
	for(int i=0;i<size;i++){
		arr[i] = 0 ;
	}
	for(int i=0;i<size;i++){
		cout << "Enter element " << i+1 << " : " ;
		cin >> arr[i] ;
	}
	cout << "Elements: " ;
	for(int i=0;i<size;i++){
		cout << arr[i] << "  " ;
	}
	delete []arr ;
	cout << "\nArray Deallocated." ;
}