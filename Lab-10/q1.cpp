#include <iostream>
using namespace std;

class heaps {
    int *heap;
    int size;
    int capacity;

public:
    heaps(int s) {
        capacity = s;
        size = 0;
        heap = new int[capacity];
    }

    void insert(int value) {
        if (size == capacity) return;
        heap[size] = value;
        heapifyUp(size);
        size++;
    }

    void heapifyUp(int i) {
        while (i != 0 && heap[i] > heap[(i - 1) / 2]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void heapifyDown(int i) {
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < size && heap[left] > heap[largest]) largest = left;
            if (right < size && heap[right] > heap[largest]) largest = right;
            if (largest == i) break;

            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

    void update_key(int i, int new_val) {
        if (i < 0 || i >= size) return;

        int old = heap[i];
        heap[i] = new_val;

        if (new_val > old) heapifyUp(i);
        else heapifyDown(i);
    }

    void delete_key(int i) {
        if (i < 0 || i >= size) return;

        heap[i] = heap[size - 1];
        size--;

        heapifyUp(i);
        heapifyDown(i);
    }

    void printHeap() {
        for (int i = 0; i < size; i++) cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    heaps h(50);
    h.insert(8);
    h.insert(7);
    h.insert(6);
    h.insert(5);
    h.insert(4);
    h.update_key(2, 10);
    h.delete_key(1);
    h.printHeap();
}

