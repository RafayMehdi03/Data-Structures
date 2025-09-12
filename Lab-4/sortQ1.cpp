#include <iostream>
using namespace std ;

int main(){
	int temp ;
	int array[10] = {5,1,3,6,2,9,7,4,8,10} ;
	for(int i=0;i<10;i++){
		for(int j=0;j<9;j++){
			if(array[j]<array[j+1]){
				temp = array[j] ;
				array[j] = array[j+1] ;
				array[j+1] = temp ;
			}
		}
	}
	cout << "Sorted Array : " ;
	for(int i=0;i<10;i++){
		cout << array[i] << " " ;
	}
}