#include <iostream>
using namespace std ;

int main(){
	int array[] = {8,13,25,41,54,56,60,67,78,82} ;
	int left = 0 ;
	int right = 9 ;
	while(left <=right){
		int mid = (left+right)/2 ;
		if(array[mid]==66){
			cout << "Value found on position " << mid+1 << endl ;
			return 0 ;
		}
		else if(array[mid]<66){
			left = mid + 1 ;
		}
		else{
			right = mid - 1 ; 
		}
	}
	cout << "ID not found" << endl ;
	int pos ;
	for(int i=0;i<10;i++){
		if(array[i]>66){
			pos = i ;
			break;
		}
	}
	for(int j=11;j>pos;j--){
		array[j]=array[j-1] ;
	}
	array[pos] = 66 ;
	cout << "New Array After Insertion : " ;
	for(int i=0;i<11;i++){
		cout << array[i] << " " ;
	}
}