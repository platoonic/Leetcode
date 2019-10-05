#include <iostream>

using namespace std;

// Basic struct for tree node elements
struct node{
	int value;
	node *right;
	node *left;
};

/*
	

	Binary Search Tree


*/

node* createNode(int value) {
	node* newNode = new node();
	newNode->value = value;
	return newNode;
}

void addNode(node** root, int value) {
	node* temp = *root;
	if(temp == NULL){
		*root = createNode(value);
		cout << "Added " << value << "\n";
		return;
	}
	if(value > temp->value){
		return addNode(&temp->right, value);
	}else if(value < temp->value){
		return addNode(&temp->left, value);
	}else{
		return;
	}
}

void preorederTraversal(node *root) {
	if(root == NULL){
		return;
	}
	cout << "Node: " << root->value << "\n";
	preorederTraversal(root->left);
	preorederTraversal(root->right);
}

void inorderTraversal(node *root) {
	if(root == NULL){
		return;
	}
	inorderTraversal(root->left);
	cout << root->value << "\n";
	inorderTraversal(root->right);
	return;
}

void postorderTraversal(node *root) {
	if(root == NULL){
		return;
	}
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	cout << root->value << "\n";
}

void searchTree(node *root, int value){
	if(root == NULL){
		cout << "Not Found!" << "\n";
		return;
	}else if(value == root->value){
		cout << "Found!" << "\n";
		return;
	}else if(value > root->value){
		searchTree(root->right, value);
	}else if(value < root->value){
		searchTree(root->left, value);
	}else{
		return;
	}
}

void invertedTree(node *root){
	if(root == NULL){
		return;
	}
	invertedTree(root->left);
	invertedTree(root->right);
	if(root->left != NULL || root->right != NULL){
		cout << "Inverting node: " << root->value << "\n";
		node* copy = root->left;
		root->left = root->right;
		root->right = copy;
		return;
	}
	return;
}

int main(){
	// Binary Search Tree
	node* root = createNode(4);
	cout << "Added " << 4 << "\n";
	addNode(&root, 2);
	addNode(&root, 7);
	addNode(&root, 1);
	addNode(&root, 3);
	addNode(&root, 6);
	addNode(&root, 9);

	invertedTree(root);
	inorderTraversal(root);
	return 0;
}









