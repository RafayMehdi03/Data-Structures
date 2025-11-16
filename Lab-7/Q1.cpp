#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    int score;
    Node* next;
    Node(string n, int s) {
        name = n;
        score = s;
        next = NULL;
    }
};

void addNode(Node*& head, string n, int s) {
    Node* t = new Node(n, s);
    if (!head) {
        head = t;
        return;
    }
    Node* p = head;
    while (p->next) p = p->next;
    p->next = t;
}

int getMaxScore(Node* head) {
    int m = 0;
    while (head) {
        if (head->score > m) m = head->score;
        head = head->next;
    }
    return m;
}

void countSort(Node*& head, int exp) {
    Node* b[10] = { NULL };
    Node* e[10] = { NULL };

    Node* p = head;
    while (p) {
        int d = (p->score / exp) % 10;
        Node* nn = new Node(p->name, p->score);

        if (!b[d]) {
            b[d] = nn;
            e[d] = nn;
        } else {
            e[d]->next = nn;
            e[d] = nn;
        }
        p = p->next;
    }

    Node* nh = NULL;
    Node* last = NULL;

    for (int i = 0; i < 10; i++) {
        if (b[i]) {
            if (!nh) {
                nh = b[i];
                last = e[i];
            } else {
                last->next = b[i];
                last = e[i];
            }
        }
    }

    head = nh;
}

void radixSort(Node*& head) {
    int mx = getMaxScore(head);
    for (int exp = 1; mx / exp > 0; exp *= 10)
        countSort(head, exp);
}

void show(Node* head) {
    while (head) {
        cout << head->name << " " << head->score << endl;
        head = head->next;
    }
}

Node* findNode(Node* head, string x) {
    while (head) {
        if (head->name == x) return head;
        head = head->next;
    }
    return NULL;
}

void deleteNode(Node*& head, string x) {
    if (!head) return;

    if (head->name == x) {
        Node* d = head;
        head = head->next;
        delete d;
        return;
    }

    Node* p = head;
    while (p->next) {
        if (p->next->name == x) {
            Node* d = p->next;
            p->next = p->next->next;
            delete d;
            return;
        }
        p = p->next;
    }
}

int main() {
    Node* head = NULL;

    addNode(head, "Ayan", 90);
    addNode(head, "Zameer", 60);
    addNode(head, "Sara", 70);
    addNode(head, "Sohail", 30);
    addNode(head, "Ahmed", 20);

    radixSort(head);

    cout << "Sorted List:" << endl;
    show(head);

    string x;
    cout << "Enter name to delete: ";
    cin >> x;

    Node* res = findNode(head, x);

    if (res) {
        deleteNode(head, x);
    }

    cout << "Updated List:" << endl;
    show(head);

    return 0;
}
