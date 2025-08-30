#include <iostream>
using namespace std;

int main() {
    int row1, col1, row2, col2;
    cout << "Enter row of matrix 1: " ;
    cin >> row1 ;
    cout << "Enter col of matrix 1: " ;
    cin >> col1 ;
    int** arr1 = new int*[row1];
    for (int i = 0; i < row1; i++){
        arr1[i] = new int[col1];
    }
    for (int i = 0; i < row1; i++){
        for (int j = 0; j < col1; j++){
        	cout << "Enter element: " ;
            cin >> arr1[i][j];}
    }
    cout << "Enter row of matrix 2: " ;
    cin >> row2 ;
    cout << "Enter col of matrix 2: " ;
    cin >> col2 ;
    int** arr2 = new int*[row2];
    for (int i = 0; i < row2; i++){
        arr2[i] = new int[col2];
    }
    for (int i = 0; i < row2; i++){
        for (int j = 0; j < col2; j++){
            cout << "Enter element: " ;
            cin >> arr2[i][j];}
    }

    if (row1 == row2 && col1 == col2){
        int** sum = new int*[row1];
        int** diff = new int*[row1];
        for (int i = 0; i < row1; i++){
            sum[i] = new int[col1];
            diff[i] = new int[col1];
        }

        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < col1; j++) {
                sum[i][j] = arr1[i][j] + arr2[i][j];
                diff[i][j] = arr1[i][j] - arr2[i][j];
            }
        }
        cout << "Addition Matrix" << endl ;
        for (int i = 0; i < row1; i++){
            for (int j = 0; j < col1; j++)
                cout << sum[i][j] << " ";
            cout << endl;
        }
        cout << "Subtraction Matrix" << endl ;
        for (int i = 0; i < row1; i++){
            for (int j = 0; j < col1; j++)
                cout << diff[i][j] << " ";
            cout << endl;
        }

        for (int i = 0; i < row1; i++){
            delete[] sum[i];
            delete[] diff[i];
        }
        delete[] sum;
        delete[] diff;
    } else {
        cout << "Matrix sizes do not match" << endl;
    }

    for (int i = 0; i < row1; i++)
        delete[] arr1[i];
    delete[] arr1;

    for (int i = 0; i < row2; i++)
        delete[] arr2[i];
    delete[] arr2;

}