#include <iostream>
using namespace std;

class SafePointer{
    int* ptr;
public:
    SafePointer(){
        ptr = new int;
    }
    void setValue(int val){
        *ptr = val;
    }
    int getValue(){
        return *ptr;
    }
    void release(){
        delete ptr;
        ptr = nullptr;
    }
};

int main() {
    SafePointer marks[5];
    for (int i = 0; i < 5; i++){
        int x;
        cout << "Enter mark for student " << i + 1 << ": ";
        cin >> x;
        marks[i].setValue(x);
    }
    cout << "Marks entered" << endl;
    for (int i = 0; i < 5; i++){
        cout << marks[i].getValue() << endl;
    }
    for (int i = 0; i < 5; i++){
        marks[i].release();
    }
}
