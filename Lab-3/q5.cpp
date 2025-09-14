#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(int v) {
        val = v;
        next = NULL;
        prev = NULL;
    }
};

class Singly {
public:
    Node* head;
    Singly() {
        head = NULL;
    }
    void addNode(int value) {
        Node* n = new Node(value);
        if (head == NULL) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
    }
};

Node* toDoubly(Node* head) {
    Node* curr = head;
    Node* prev = NULL;
    while (curr != NULL) {
        curr->prev = prev;
        prev = curr;
        curr = curr->next;
    }
    return head;
}

Node* toCircular(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head;
    return head;
}

int main() {
    Singly s1, s2;
    for (int i = 1; i <= 5; i++) {
        s1.addNode(i);
        s2.addNode(i);
    }

    Node* h = toDoubly(s1.head);
    cout << "Doubly: ";
    Node* temp = h;
    while (temp != NULL) {
        cout << temp->val;
        if (temp->next != NULL) {
            cout << " <-> ";
        }
        temp = temp->next;
    }
    cout << endl;

    Node* c = toCircular(s2.head);
    cout << "Circular: ";
    temp = c;
    for (int i = 0; i < 6; i++) {
        cout << temp->val;
        if (i < 5) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;
}












