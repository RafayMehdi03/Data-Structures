#include <iostream>
using namespace std;

void heapify(int arr[],int n,int i){
	int largest = i ;
	int left = 2*i + 1 ;
	int right = 2*i + 2 ;
	
	if(left < n && arr[left] > arr[largest]) largest = left ;
	if(right < n && arr[right] > arr[largest]) largest = right ;
	
	if(largest != i){
		swap(arr[largest],arr[i]) ;
		heapify(arr,n,largest) ;
	}
}

void convertMax(int arr[],int n){
	for(int x = n/2-1 ; x >= 0 ; x-- ){
		heapify(arr,n,x) ;
	}
}

int main(){
	int arr[] = {3,5,9,6,8,20,10,12,18,9} ;
	int n = sizeof(arr)/sizeof(arr[0]) ;
	
	convertMax(arr,n) ;
	cout << "Max Heap :\n{" ;
	for(int i=0;i<n;i++){
		if(i != n-1) cout << arr[i] << "," ;
		else cout << arr[i] << "}";
	}
}