//q1
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string key, value;
    Node* next;
    Node(string k, string v) : key(k), value(v), next(nullptr) {}
};

class HashTable {
    Node* arr[10];

    int h(const string& s) {
        int sum = 0;
        for(char c : s) sum += c;
        return sum % 10;
    }

public:
    HashTable() {
        for(int i = 0; i < 10; i++) arr[i] = nullptr;
    }

    void insert(string k, string v) {
        int idx = h(k);
        Node* n = new Node(k, v);
        n->next = arr[idx];
        arr[idx] = n;
    }

    void display() {
    for(int i = 0; i < 10; i++) {
        Node* p = arr[i];
        if(p != nullptr){
        while(p) {
            cout << p->key << " " << p->value << "  ";
            p = p->next;
        }
        cout << endl;
    }
    }
}

};

int main() {
    HashTable myhash;
    myhash.insert("A","aaaaa");
    myhash.insert("B","bbbbb");
    myhash.insert("C","ccccc");
    myhash.insert("A","zzzzz");
    myhash.display();
}
