#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int size, int x) {
    int low = 0, high = size - 1;
    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high) {
            if (arr[low] == x) return low;
            return -1;
        }
        int pos = low + ((x - arr[low]) * (high - low)) / (arr[high] - arr[low]);
        if (arr[pos] == x) return pos;
        if (arr[pos] < x) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    return -1;
}

int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    int arr[size];
    cout << "Enter " << size << " sorted uniformly distributed values: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    int x;
    cout << "Enter the value to search: ";
    cin >> x;
    int index = interpolationSearch(arr, size, x);
    if (index != -1) {
        cout << "Element found at position " << index+1 << endl;
    } else {
        cout << "Element not found" << endl;
    }
}
