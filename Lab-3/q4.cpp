#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int v) {
        val = v;
        next = NULL;
    }
};

class Circular{
public:
    Node* head;

    Circular() {
        head = NULL;
    }

    void addNode(int value) {
        Node* n = new Node(value);
        if (head == NULL) {
            head = n;
            n->next = head ;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = n;
        n->next = head ;
    }

    void display() {
        if (head == NULL){
		    return;
	    }
        Node* temp = head;
        do{
            cout << temp->val;
            temp = temp->next;
            if (temp != head) cout << " -> ";
        } while (temp != head);
        cout << endl;
    }
};

int JosephusProblem(Node *head,int k){
	Node *temp = head ;
	Node* pre = NULL ;
	while(temp->next!=temp){
    	for(int i=1;i<k;i++){
    		pre = temp ;
    		temp = temp->next ;
    	}
    	Node* nextNode = temp->next;
        pre->next = nextNode ;
        delete temp;
        temp = nextNode;
    }
    return temp->val ;
}

int main(){
	int n,k ;
	Circular c1 ;
	cout << "Enter N: " ;
	cin >> n ;
	for(int i=0;i<n;i++){
		c1.addNode(i+1) ;
	}
	cout << "Enter K: " ;
	cin >> k ;
	int pos = JosephusProblem(c1.head,k) ;
	cout << "Position is " << pos << endl ;
}




















