#include <iostream>
#include <string>
#include <list>
using namespace std;

class Hash {
    list<pair<string,string>> table[100];

    int hashFunc(const string &s) {
        int sum = 0;
        for(char c : s) sum += c;
        return sum % 100;
    }

public:
    void insert(string key, string value) {
        int idx = hashFunc(key);
        table[idx].push_back({key, value});
    }

    void search(string key) {
        int idx = hashFunc(key);
        for(auto &p : table[idx]) {
            if(p.first == key) {
                cout << p.second;
                return;
            }
        }
        cout << "Error: Word not found";
    }

    void delete_key(string key) {
        int idx = hashFunc(key);
        for(auto it = table[idx].begin(); it != table[idx].end(); it++) {
            if(it->first == key) {
                table[idx].erase(it);
                cout << "key " << key << " deleted successfully !";
                return;
            }
        }
        cout << "Error: Word not found";
    }

    void display() {
        for(int i = 0; i < 100; i++) {
            if(!table[i].empty()) {
                cout << "index " << i << ": ";
                for(auto &p : table[i])
                    cout << "(" << p.first << ", " << p.second << ") ";
                cout << endl;
            }
        }
    }
};

int main() {
    Hash h;
    h.insert("XY","Math");
    h.insert("LM","Physics");
    h.insert("PQ","Chemistry");
    h.insert("XY","Algebra");
    cout << "search key XY: ";
    h.search("XY");
    cout << endl ;
    h.delete_key("LM");
    cout << endl;
    h.display();
}
