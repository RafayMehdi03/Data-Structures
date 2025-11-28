#include <iostream>
#include <string>
using namespace std;

struct Node {
    string key, value;
    Node* next;
    Node(string k, string v) : key(k), value(v), next(nullptr) {}
};

class Dictionary {
    Node* table[100];

    int hash(const string& s) {
        int sum = 0;
        for(char c : s) sum += c;
        return sum % 100;
    }

public:
    Dictionary() {
        for(int i = 0; i < 100; i++) table[i] = nullptr;
    }

    void Add_Record(string key, string value) {
        int idx = hash(key);
        Node* n = new Node(key, value);
        n->next = table[idx];
        table[idx] = n;
    }

    void Word_Search(string key) {
        int idx = hash(key);
        Node* p = table[idx];
        while(p) {
            if(p->key == key) {
                cout << p->value;
                return;
            }
            p = p->next;
        }
        cout << "Error: Word not found";
    }

    void Delete_Word(string key) {
        int idx = hash(key);
        Node* p = table[idx];
        Node* prev = nullptr;

        while(p) {
            if(p->key == key) {
                if(prev) prev->next = p->next;
                else table[idx] = p->next;
                delete p;
                cout << "key " << key << " deleted successfully !";
                return;
            }
            prev = p;
            p = p->next;
        }
        cout << "Error: Word not found";
    }

    void Print_Dictionary() {
        for(int i = 0; i < 100; i++) {
            Node* p = table[i];
            if(p) {
                cout << "index " << i << ": ";
                while(p) {
                    cout << "(" << p->key << ", " << p->value << ") ";
                    p = p->next;
                }
                cout << endl;
            }
        }
    }
};

int main() {
    Dictionary d;
    d.Add_Record("AB", "FASTNU");
    d.Add_Record("CD", "CS");
    d.Add_Record("EF", "Islamabad");
    cout << "search key AB: ";
    d.Word_Search("AB");
    cout << endl;
    d.Delete_Word("EF");
    cout << endl;
    d.Print_Dictionary();
}
