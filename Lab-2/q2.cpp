#include <iostream>
using namespace std ;

int main(){
	int row,col ;
	int **seating ;
	char ans ;
	
	cout << "Enter rows: " ;
	cin >> row ;
	cout << "Enter columns: " ;
	cin >> col ;
	seating = new int*[row] ;
	
	for(int i=0 ; i< row ; i++){
		seating[i] = new int[col] ;
	}
	
	for(int i=0 ;i<row;i++){
		for(int j=0;j<col;j++){
			seating[i][j] = 0 ;
		}
	}
	
	for(int i=0 ;i<row;i++){
		for(int j=0;j<col;j++){
			cout << "Is seat number " << j+1 << " of row number " << i+1 << " occupied(Y or N): " ;
			cin >> ans ;
			if(ans=='Y'){
				seating[i][j] = 1 ;
			}
			else{
				seating[i][j] = 0 ;
			}
        } 
    }
    cout << "ARRANGEMENT:\n" ;
    for(int i=0 ;i<row;i++){
		for(int j=0;j<col;j++){
			cout << seating[i][j] << " " ;
	    }
	    cout << endl ;
    }
    
    for(int i=0;i<row;i++){
    	delete[] seating[i] ;
	}
	delete[] seating ;
	cout << "\nArray Deallocated" ;
}