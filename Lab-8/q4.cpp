#include <iostream>
#include <string>
#include <cstdlib>

using namespace std ;

class Node{
	public:
	int value ;
	Node *left ;
	Node *right ;
	Node(int v){
		value = v ;
		left = nullptr ;
		right = nullptr ;
	}
};

class BST{
	Node* root ;
	public:
		BST(){
			root = nullptr ;
		}
		
		Node* insertBST(Node* node,int val){
			if(node==nullptr) return new Node(val) ;
			if(val < node->value) node->left = insertBST(node->left,val) ;
			if(val > node->value) node->right = insertBST(node->right,val) ;
			return node ;
		}
		void insertN(int v){
			root = insertBST(root,v) ;
		}
		
		bool searchBST(Node *node,int v){
			if(node == nullptr) return false ;
			if(node->value == v) return true ;
			else if(v < node->value) return searchBST(node->left,v) ;
			else return searchBST(node->right,v) ;
		}
		
		void searchOrinsert(int v){
			if(searchBST(root,v)){
				cout << v << " Already Present" ;
			}
			else{
				cout << v << " Is not present so after inserting tree looks like:\n" ;
				root = insertBST(root,v) ;
				inOrder(root) ;
			}
		}
		
		void inOrder(Node *node){
			if(node == nullptr) return ;
			inOrder(node->left) ;
			cout << node->value << " " ;
			inOrder(node->right) ;
		}
		void display(){
			inOrder(root) ;
		}
};

int main(){
	BST tree ;
	tree.insertN(10) ;
	tree.insertN(8) ;
	tree.insertN(5) ;
	tree.insertN(16) ;
	tree.insertN(9) ;
	tree.insertN(3) ;
	tree.insertN(15) ;
	tree.insertN(2) ;
	tree.insertN(21) ;
	tree.insertN(12) ;
	cout << "Initial Tree: \n" ;
	tree.display() ;
	cout << endl ;
	tree.searchOrinsert(4) ;
	cout << endl ;
	tree.searchOrinsert(16) ;
}