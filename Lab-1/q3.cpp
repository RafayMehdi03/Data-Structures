#include <iostream>
using namespace std;

class Box {
    int* numbers;
    int size;

public:
    Box(int size) {
        this->size = size;
        numbers = new int[size];
        for (int i = 0; i < size; i++) {
            cout << "Enter number: ";
            cin >> numbers[i];
        }
    }
    Box(const Box& other) {
        size = other.size;
        numbers = new int[size];
        for (int i = 0; i < size; i++) {
            numbers[i] = other.numbers[i];
        }
        cout << "Object Created Using Copy Constructor\n";
    }

    Box& operator=(const Box& other) {
        size = other.size;
        numbers = new int[size];
        for (int i = 0; i < size; i++) {
            numbers[i] = other.numbers[i];
        }
        cout << "Object Created Using Copy Assignment Operator\n";
        return *this;
    }

    ~Box() {
        delete[] numbers;
        cout << "Destructor called\n";
    }

    void display() {
        cout << "Box contents: ";
        for (int i = 0; i < size; i++) {
            cout << numbers[i] << " ";
        }
        cout << endl;
    }

    void set(int index, int value) {
        if (index >= 0 && index < size) {
            numbers[index] = value;
        }
    }
};

int main() {
    Box b1(3);
    b1.display();
    Box b2 = b1; 
    b2.set(0, 999); 
    b2.display();
    b1.display();
    cout << "Here You Can See That 1st object remains same when object 2 changes one of its value\n" ;
    Box b3(3); 
    b3 = b1;
    b3.set(1, 888); 
    b3.display();
    b1.display();

}

//In this program, we use dynamic memory for storing numbers in Box class. We make copy constructor and assignment operator for deep copy. When we copy the object, new memory is made and data is copied. So, changing one object does not change the other. This shows that deep copy is working. Shallow copy leads to same memory for different objects which creates data inconsistency