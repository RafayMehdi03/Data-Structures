#include <iostream>
using namespace std;

struct Pair {
    int first;
    int second;
};

void findPairs(int arr[], int n) {
    int maxPairs = n * (n-1)/2;
    int sums[maxPairs];
    Pair pairs[maxPairs];
    int k = 0;

    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            int s = arr[i] + arr[j];
            bool found = false;
            for(int p=0; p<k; p++) {
                if(sums[p] == s) {
                    Pair prev = pairs[p];
                    if(prev.first != i && prev.second != i && prev.first != j && prev.second != j) {
                        cout << "(" << arr[prev.first] << ", " << arr[prev.second] << ") and ("
                             << arr[i] << ", " << arr[j] << ")\n";
                        return;
                    }
                }
            }
            sums[k] = s;
            pairs[k] = {i,j};
            k++;
        }
    }
    cout << "No pairs found\n";
}

int main() {
    int arr1[] = {3, 4, 7, 1, 2, 9, 8};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    findPairs(arr1, n1);

    int arr2[] = {3, 4, 7, 1, 12, 9};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    findPairs(arr2, n2);

    int arr3[] = {65, 30, 7, 90, 1, 9, 8};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    findPairs(arr3, n3);
}
