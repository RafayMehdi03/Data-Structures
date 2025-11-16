#include <iostream>
using namespace std;

int seedNum = 9;
int getRand() {
    seedNum = (seedNum * 31 + 17) % 1000003;
    return seedNum;
}

void swapIt(int &x, int &y) {
    int t = x;
    x = y;
    y = t;
}

int cutFirst(int arr[], int left, int right, long long &hit) {
    int piv = arr[left];
    int i = left + 1, j = right;

    while (true) {
        while (i <= right && arr[i] <= piv) { hit++; i++; }
        while (arr[j] > piv) { hit++; j--; }
        if (i >= j) break;
        swapIt(arr[i], arr[j]);
    }

    swapIt(arr[left], arr[j]);
    return j;
}

int cutMid(int arr[], int left, int right, long long &hit) {
    int mid = (left + right) / 2;
    swapIt(arr[left], arr[mid]);
    return cutFirst(arr, left, right, hit);
}

int cutRand(int arr[], int left, int right, long long &hit) {
    int pick = left + (getRand() % (right - left + 1));
    swapIt(arr[left], arr[pick]);
    return cutFirst(arr, left, right, hit);
}

int cutMed(int arr[], int left, int right, long long &hit) {
    int mid = (left + right) / 2;
    int a = arr[left], b = arr[mid], c = arr[right];
    int pos;

    if ((a <= b && b <= c) || (c <= b && b <= a)) pos = mid;
    else if ((b <= a && a <= c) || (c <= a && a <= b)) pos = left;
    else pos = right;

    swapIt(arr[left], arr[pos]);
    return cutFirst(arr, left, right, hit);
}

void quickDo(int arr[], int left, int right, long long &hit, int mode) {
    if (left >= right) return;

    int p;
    if (mode == 1) p = cutFirst(arr, left, right, hit);
    else if (mode == 2) p = cutRand(arr, left, right, hit);
    else if (mode == 3) p = cutMid(arr, left, right, hit);
    else p = cutMed(arr, left, right, hit);

    quickDo(arr, left, p - 1, hit, mode);
    quickDo(arr, p + 1, right, hit, mode);
}

void makeSorted(int arr[], int n) {
    for (int i = 0; i < n; i++) arr[i] = i + 1;
}

void makeRev(int arr[], int n) {
    for (int i = 0; i < n; i++) arr[i] = n - i;
}

void makeRand(int arr[], int n) {
    for (int i = 0; i < n; i++) arr[i] = getRand() % 1000;
}

void copyArr(int a[], int b[], int n) {
    for (int i = 0; i < n; i++) b[i] = a[i];
}

int main() {
    int n = 12;
    int base[50], temp[50];

    cout << "QuickSort Pivot Test" << endl;
    cout << "Size: " << n << endl << endl;

    for (int t = 1; t <= 3; t++) {
        if (t == 1) makeSorted(base, n);
        else if (t == 2) makeRev(base, n);
        else makeRand(base, n);

        cout << (t == 1 ? "Sorted Input" : t == 2 ? "Reverse Input" : "Random Input") << endl;

        for (int mode = 1; mode <= 4; mode++) {
            copyArr(base, temp, n);
            long long hits = 0;

            quickDo(temp, 0, n - 1, hits, mode);

            if (mode == 1) cout << "First Pivot: ";
            else if (mode == 2) cout << "Random Pivot: ";
            else if (mode == 3) cout << "Middle Pivot: ";
            else cout << "Median Pivot: ";

            cout << hits << " comparisons" << endl;
        }

        cout << endl;
    }

    return 0;
}
