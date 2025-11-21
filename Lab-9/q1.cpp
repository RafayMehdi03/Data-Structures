#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(NULL), right(NULL) {}
};

Node* headPtr;
Node* prevPtr;

void inorderToList(Node* n) {
    if (!n) return;
    inorderToList(n->left);
    if (!headPtr) headPtr = n;
    if (prevPtr) prevPtr->right = n;
    prevPtr = n;
    n->left = NULL;
    inorderToList(n->right);
}

Node* buildAVL(int& k) {
    if (k <= 0) return NULL;
    Node* leftSub = buildAVL(--k);
    Node* root = headPtr;
    headPtr = headPtr->right;
    root->left = leftSub;
    root->right = buildAVL(k);
    return root;
}

Node* convertBSTtoAVL(Node* root) {
    headPtr = NULL;
    prevPtr = NULL;
    inorderToList(root);
    if (prevPtr) prevPtr->right = NULL;
    int count = 0;
    for (Node* p = headPtr; p; p = p->right) count++;
    int k = count;
    return buildAVL(k);
}

//The BST is first converted into a sorted linked list using headPtr and prevPtr, linking nodes via their right pointers. The buildAVL function 
//recursively picks the middle node as root, using a temporary leftSub pointer for the left subtree; this effectively balances the tree without 
//explicit rotations. Original nodes like 10, 15, 20 are reassigned as left or right children based on the middle-node selection. The function 
//finally returns the middle node of the list as the AVL root, ensuring a height-balanced tree.