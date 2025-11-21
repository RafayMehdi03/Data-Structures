#include <iostream>
using namespace std;

class Node{
   public:
	int data ;
	int height ;
	Node *left ;
	Node *right ;
	Node(int v){
		data = v ;
		left = right = nullptr ;
		height = 1 ;
	}
};

class AVL{
	Node *root ;
	public:
		AVL(){
			root = nullptr ;
		}
		
		int getHeight(Node *curr){
			if(curr == nullptr) return 0 ;
			else return curr->height ;
		}
		
		int getBalance(Node* curr){
			if(curr == nullptr) return 0 ;
			else return getHeight(curr->left) - getHeight(curr->right) ;
		}
		
		void updateHeight(Node *curr){
			int lH = getHeight(curr->left) ;
			int rH = getHeight(curr->right) ;
			curr->height = 1 + max(lH,rH) ;
		}
		
		Node* rotateRight(Node *x){
			Node *y = x->left ;
			Node *z = y->right ;
			
			y->right = x ;
			x->left = z ;
			
			updateHeight(x) ;
			updateHeight(y) ;
			
			return y ;
		}
		Node* rotateLeft(Node *x){
			Node *y = x->right ;
			Node *z = y->left ;
			
			y->left = x ;
			x->right = z ;
			
			updateHeight(x) ;
			updateHeight(y) ;
			
			return y ;
		}
		
		Node *balanceNode(Node *curr){
			int balance = getBalance(curr) ;
			if(balance > 1 && getBalance(curr->left) >= 0){
				return rotateRight(curr) ;
			}
			if(balance > 1 && getBalance(curr->left) < 0){
				curr->left = rotateLeft(curr->left) ;
				return rotateRight(curr) ;
			}
			if(balance < 1 && getBalance(curr->right) <= 0){
				return rotateLeft(curr) ;
			}
			if(balance > 1 && getBalance(curr->left) > 0){
				curr->right = rotateRight(curr->right) ;	
				return rotateLeft(curr) ;
			}
			return curr ;
		}
		
		Node *insertNode(Node *curr,int val){
			if(curr==nullptr) return new Node(val) ;
			if(val < curr->data) curr->left = insertNode(curr->left,val) ;
			else if(val > curr->data) curr->right = insertNode(curr->right,val) ;
			else return curr ;
			
			updateHeight(curr) ;
			return balanceNode(curr) ;
		}
		
		void Inorder(Node *curr){
			if(curr==nullptr) return ;
			Inorder(curr->left) ;
			cout << curr->data << " " ;
			Inorder(curr->right) ;
		}
		
		void InsertNode(int val){
			root = insertNode(root,val) ;
		}
		
		void display(){
			Inorder(root) ;
		}
};

int main(){
	AVL a;
	a.InsertNode(50) ;
	a.InsertNode(30) ;
	a.InsertNode(70) ;
	a.InsertNode(20) ;
	a.InsertNode(40) ;
	a.InsertNode(60) ;
	a.InsertNode(80) ;
	cout << "Before Inserting 55:\n" ; 
	a.display() ;
	a.InsertNode(55) ;
	cout << "\nAfter Inserting 55:\n" ;
	a.display() ;
}
