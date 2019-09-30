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
void addNodeAtEnd(node *head, int value){
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
	if(head != NULL){
		cout << head->value << "\n";
	}
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
	//check if list is empty
	if(head == NULL){
		cout << "List is empty\n";
		return;
	}
	//exit method when temp arrives at last node
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
	//check if list is empty
	if(head == NULL){
		return 0;
	}
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

void deleteNodeAtEnd(node *&head){
	//check if list is empty
	if(head == NULL){
		return;
	}
	//check if list contains only 1 node
	if(head->next == NULL){
		cout << head;
		cout << "deleting head \n";
		free(head);
		head = NULL;
		return;
	}
	while(head != NULL){
		if(head->next->next == NULL){
			free(head->next);
			head->next = NULL;
			return;
		}
		head = head->next;
	}
}

int main(){
	node *head = initializeList(1);
	addNodeAtEnd(head, 2);
	addNodeAtEnd(head, 3);

	traverseListRecursively(head); //1 2 3 4 5 6
	cout << "Linked list length is: " << getListLength(head) << "\n"; // 6

	deleteNodeAtEnd(head);
	cout << "After deletion: " << "\n";
	traverseListRecursively(head); //1 2 3 4 5 6

	cout << "Linked list length is: " << getListLength(head); // 6

	cout << "\n";
	return 0;
}


