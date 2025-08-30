#include<iostream>
using namespace std;
int main(){
    int r,c ;
    cout << "Enter the number of categories: " ;
    cin >> r ;
    int **library = new int *[r] ;
    int *size = new int[r] ;
    for(int i=0;i<r;i++){
    	cout << "Enter the number of books of category " << i+1 << ": " ;
    	cin >> c ;
    	size[i] = c ;
    	library[i] = new int [c] ;
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<size[i];j++){
			cout << "Enter Book ID of book number " << j+1 << " of category " << i+1 << ": " ;
			cin >> library[i][j] ; 
		}
	}
	int searchId ;
	cout << "Enter a id to search: " ;
	cin >> searchId ;
	bool found = false ;
	for(int i=0;i<r;i++){
		for(int j=0;j<size[i];j++){
			if(library[i][j]==searchId){
				cout << "Book found in category " << i+1 << endl ;
				found = true ;
				break ;
			}
		}
		if(found){
			break ;
		}
	}
	if(!found){
		cout << "Id not found" ;
	}
	for(int i=0;i<r;i++){
		delete[]library[i] ;
	}
	delete[]library ;
	delete[]size ;
}

