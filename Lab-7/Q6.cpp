#include <iostream>
using namespace std;

int getMax(int a[], int n) {
    int mx = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > mx) mx = a[i];
    return mx;
}

void countSort(int a[], int n, int exp) {
    int out[20];
    int cnt[10] = {0};

    for (int i = 0; i < n; i++)
        cnt[(a[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        cnt[i] += cnt[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        out[cnt[(a[i] / exp) % 10] - 1] = a[i];
        cnt[(a[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = out[i];
}

void radixSort(int a[], int n) {
    int mx = getMax(a, n);
    for (int exp = 1; mx / exp > 0; exp *= 10)
        countSort(a, n, exp);
}

void mergeArr(int a[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[20], R[20];

    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = a[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }

    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        mergeArr(a, l, m, r);
    }
}

int main() {
    int arr1[10] = {12, 45, 2, 9, 33, 19, 87, 5, 23, 50};
    int arr2[10] = {7, 90, 11, 3, 44, 15, 66, 8, 31, 20};

    int all[20];

    for (int i = 0; i < 10; i++) all[i] = arr1[i];
    for (int i = 0; i < 10; i++) all[i + 10] = arr2[i];

    int choice;
    cout << "Choose sorting method:" << endl;
    cout << "1 - Radix Sort" << endl;
    cout << "2 - Merge Sort" << endl;
    cin >> choice;

    if (choice == 1) {
        radixSort(all, 20);
        cout << "Sorted using Radix Sort: " << endl;
    }
    else {
        mergeSort(all, 0, 19);
        cout << "Sorted using Merge Sort: " << endl;
    }

    for (int i = 0; i < 20; i++)
        cout << all[i] << " ";
    cout << endl;

    return 0;
}
