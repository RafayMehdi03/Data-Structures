#include <iostream>
using namespace std;

int* resizeArr(int* oldArr, int oldSize, int newSize) {
    if (oldSize == newSize) {
        return oldArr;
    }
    int* newArr = new int[newSize];

    int lim = (oldSize < newSize) ? oldSize : newSize;

    for (int i = 0; i < lim; i++) {
        newArr[i] = oldArr[i];
    }

    for (int i = lim; i < newSize; i++) {
        newArr[i] = 0;
    }

    delete[] oldArr;
    return newArr;
}

int main() {
    int* expenses;
    int size;
    char ans;
    int newSize;

    cout << "Enter number of months: ";
    cin >> size;

    expenses = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter expense for month " << i + 1 << ": ";
        cin >> expenses[i];
    }

    cout << "Do you want to resize the array? (Y or N): ";
    cin >> ans;

    if (ans == 'Y' || ans == 'y') {
        cout << "Enter new size: ";
        cin >> newSize;

        expenses = resizeArr(expenses, size, newSize);

        if (newSize > size) {
            for (int i = size; i < newSize; i++) {
                cout << "Enter expense for month " << i + 1 << ": ";
                cin >> expenses[i];
            }
        }

        size = newSize;
    }

    int total = 0;
    for (int i = 0; i < size; i++) {
        total += expenses[i];
    }

    double average = total / size ;

    cout << "\nTotal expenses: " << total << endl;
    cout << "Average monthly expense: " << average << endl;

    delete[] expenses;
    return 0;
}