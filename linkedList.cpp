#include <iostream>
using namespace std;

//Basic struct for linked list node elements
struct node{
	int value;
	node *next;
};

//Initializes a linked list
node *initializeList(int value){
	node *head = new node();
	head->value = value;
	head->next  = NULL;
	return head;
}

//Add node to the end of a linked list
void addItemAtEnd(node *head, int value){
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

//traverse linked list iteratively
void traverseList(node *head){
	//head node
	cout << head->value << "\n";
	//temporary pointer
	node *temp = head->next;
	//check if list contains only 1 node
	if(temp == NULL){
		return;
	}
	//traverse the list to the last node
	while(temp != NULL){
		cout << temp->value << "\n";
		if(temp->next == NULL){
			return;
		}
		temp = temp->next;
	}
}

//traverse linked list recursively
void traverseListRecursively(node *head){
	if(head->next == NULL){
		cout << head->value << "\n";
		return;
	}
	cout << head->value << "\n";
	return traverseListRecursively(head->next);
}

//get linked list length
int getListLength(node *head){
	int length = 1;
	node *temp = head->next;
	//check if list contains only 1 node
	if(temp == NULL){
		return length;
	}
	while(temp != NULL){
		length += 1;
		temp = temp->next;
	}
	return length;
}

int main(){
	node *head = initializeList(1);
	addItemAtEnd(head, 2);
	addItemAtEnd(head, 3);
	addItemAtEnd(head, 4);
	addItemAtEnd(head, 5);
	addItemAtEnd(head, 6);
	traverseListRecursively(head); //1 2 3 4 5 6
	cout << "Linked list length is: " << getListLength(head); // 6

	cout << "\n";
	return 0;
}


