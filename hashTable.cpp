#include <iostream>

using namespace std;

// Implementing a Hash Table using linked list.

struct node {
	int value;
	node* next;
};

/*
	
	Linked list functions

*/

//Initializes a linked list
node *initializeList(int value) {
	node *head = new node();
	head->value = value;
	head->next  = NULL;
	return head;
}

//Add node to the end of a linked list
void addNodeAtEnd(node *head, int value) {
	//temporary pointer
	node *temp = head->next;
	//new node
	node *newNode  = new node();
	newNode->value = value;
	newNode->next  = NULL;

	//check if list contains only 1 node
	if(temp == NULL){
		head->next = newNode;
		return;
	}
	//traverse the list to the last node
	while(temp != NULL){
		if(temp->next == NULL){
			temp->next = newNode;
			return;
		}
		temp = temp->next;
	}
}

bool searchLinkedList(node* head, int value) {
	while(head != NULL){
		if(head->value == value){
			return true;
		}
		head = head->next;
	}
	return false;
}

/*
	
	Hash Table functions

*/

// Use array of linked list to store key's index
const int arrayLength = 100;
node* keys[arrayLength] = {NULL};

// Hashing function
int hashToIndex(int value) {
	return value % arrayLength;
}

void insertHashTable(int value) {
	int index = hashToIndex(value);
	// Check if hash index is empty
	if(keys[index] == NULL){
		keys[index] = initializeList(value);
	}else{
		addNodeAtEnd(keys[index], value);
	}
}

void searchHashTable(int value) {
	int index = hashToIndex(value);
	if(keys[index] == NULL){
		cout << "Not Found " << "\n";
		return;
	}else{
		if(searchLinkedList(keys[index], value)){
			cout << "Found" << "\n";
			return;
		}else{
			cout << "Not Found" << "\n";
			return;
		}
	}
}



int main() {
	insertHashTable(5);
	insertHashTable(3);
	insertHashTable(2);
	insertHashTable(1);

	searchHashTable(4); // Not Found

	cout << "\n";
	return 0;
}




































