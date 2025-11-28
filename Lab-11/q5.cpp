#include <iostream>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    bool isEmpty;
    Student() { isEmpty = true; }
};

class StudentHashTable {
    static const int SIZE = 15;
    Student table[SIZE];

    int hashFunc(int roll) {
        return roll % SIZE;
    }

public:
    void InsertRecord(int roll, string name) {
        int idx = hashFunc(roll);
        int attempt = 0;
        while(attempt < SIZE) {
            int newIdx = (idx + attempt * attempt) % SIZE;
            if(table[newIdx].isEmpty) {
                table[newIdx].roll = roll;
                table[newIdx].name = name;
                table[newIdx].isEmpty = false;
                return;
            }
            attempt++;
        }
        cout << "Hash table full, cannot insert " << roll << endl;
    }

    void SearchRecord(int roll) {
        int idx = hashFunc(roll);
        int attempt = 0;
        while(attempt < SIZE) {
            int newIdx = (idx + attempt * attempt) % SIZE;
            if(table[newIdx].isEmpty) {
                attempt++;
                continue;
            }
            if(table[newIdx].roll == roll) {
                cout << "Student found: " << table[newIdx].name << endl;
                return;
            }
            attempt++;
        }
        cout << "Record not found" << endl;
    }
};

int main() {
    StudentHashTable st;
    st.InsertRecord(10, "Alice");
    st.InsertRecord(25, "Bob");
    st.InsertRecord(40, "Charlie");
    st.InsertRecord(55, "David");
    st.SearchRecord(25);
    st.SearchRecord(55);
    st.SearchRecord(99);
}
