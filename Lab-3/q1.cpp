#include <iostream>
using namespace std ;

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

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val;
            if (temp->next){
			    cout << " --> ";
			}
            temp = temp->next;
        }
        cout << endl;
    }
};


Node *mergeLists(Node *head1,Node *head2){
	Node *newHead = NULL ;
	if(head1->val<=head2->val){
		newHead = head1 ;
		head1 = head1->next ;
	}
	else{
		newHead = head2 ;
		head2 = head2->next ;
	}
	Node *newTemp = newHead ;
	while(head1!=NULL && head2!=NULL){
		if(head1->val <= head->val){
			newTemp->next = head1 ;
			head1 = head1->next ;
		}
		else{
			newTemp->next = head2 ;
			head2 = head->next ;
		}
		newTemp = newTemp->next ;
	}
	
	if (head1!=NULL){
	    curr->next = head1;
	}
    if (head2!=NULL){
	    curr->next = head2;
	}
	return newTemp ;
}


int main(){
	Singly s1 ;
	Singly s2 ;
	s1.addNode(1) ;
	s1.addNode(3) ;
	s1.addNode(5) ;
	s2.addNode(2) ;
	s2.addNode(4) ;
	s2.addNode(6) ;
	cout << "List A: " ; 
	s1.display() ;
	cout << "List B: " ;
	s2.display() ;
	cout << "Merged List: " ;
	Node *n = mergeLists(s1.head,s2.head) ;
	
	Node *temp = n ;
	while(temp!=NULL){
		cout << temp->val ;
		if(temp->next!=NULL){
			cout << " --> " ;
			temp = temp->next ;
		}
	}
}
