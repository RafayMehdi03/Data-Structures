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
		void convertArr(int *arr,Node *curr,int &index){
			if(curr == nullptr) return ;
			convertArr(arr,curr->left,index) ;
			arr[index++] = curr->data ;
			convertArr(arr,curr->right,index) ;
		}
		
		public:
		void InsertNode(int val){
			root = insertNode(root,val) ;
		}
		
		void display(){
			Inorder(root) ;
		}
		AVL(){
			root = nullptr ;
		}
		void convertTo(int *arr,int &index){
			convertArr(arr,root,index) ;
		}
		int getLH(){
			return getHeight(root->left) ;
		}
		int getRH(){
			return getHeight(root->right) ;
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
	int *arr = new int[7] ;
	int index = 0 ;
	a.convertTo(arr,index) ;
	int k ;
	cin >> k ;
	if(k < 7 && k > 0){
	cout << "Kth Largest: " << arr[7-k] << endl;
	cout << "Kth Smallest: " << arr[k-1] << endl;
	}
	cout << "Left Subtree Height: " << a.getLH() << endl ;
	cout << "Right Subtree Height: " << a.getRH() << endl ;
}