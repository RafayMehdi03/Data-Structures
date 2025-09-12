#include <iostream>
using namespace std ;

int interpolationSearch(int arr[],int size,int x){
	int low = 0 ;
	int high = size - 1 ;
	while(low<=high&&x>=arr[low]&&x<=arr[high]){
		if(low==high){
			if(arr[low]==x){
				return low ;
			}
			return -1 ;
		}
		int pos = low + ((x-arr[low])*(high-low)) / (arr[high]-arr[low]) ;
		if(arr[pos] == x) return pos ;
		if(arr[pos]<x) low = pos + 1 ;
		else high = pos - 1 ;
	}
	return -1 ; 
}

int main(){
	int *array ;
	int e ;
	cout << "Enter number of elements: " ;
	cin >> e ;
	array = new int[e] ;
	for(int i=0;i<e;i++){
		cout << "Enter element: " ;
		cin >> array[i] ;
	}
	int temp ;
	for(int i=0;i<e;i++){
		for(int j=0;j<e-1;j++){
			if(array[j]>array[j+1]){
				temp = array[j] ;
				array[j] = array[j+1] ;
				array[j+1] = temp ;
			}
		}
	}
	int diff = array[1]-array[0] ;
	for(int i=1;i<e-1;i++){
		if((array[i+1]-array[i])!=diff){
			cout << "Error! Intepolation sort cannot be applied" << endl ;
			return 0 ;
		}
	}
	int val ;
	cout << "Enter value to search: " ;
	cin >> val ;
	int p = interpolationSearch(array,e,val) ;
	if(p!=-1){
	cout << "Found at position: " << p+1 ;
    }
	else{
		cout << "Not Found" ;
	}	
	delete []array ;
}