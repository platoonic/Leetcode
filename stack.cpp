#include <iostream>

using namespace std;

//Implementing a Stack using linked lists
//Basic struct for linked list node elements
struct node{
	int value;
	node *next;
};

//Initializes a stack
node *initializeStack(int value){
	node *head = new node();
	head->value = value;
	head->next  = NULL;
	cout << "Push: " << value << "\n";
	return head;
}

void push(node *&head, int value){
	//allocate memory for the new node
	node *newNode = new node();
	newNode->value = value;
	cout << "Push: " << value << "\n";
	newNode->next = head;
	head = newNode;
}

int pop(node **head){
	node *temp = *head;
	if(temp == NULL){
		cout << "Stack is empty";
		return 0;
	}
	int value = temp->value;
	cout << "Pop: " << value << "\n";
	*head = (*head)->next;
	return value;
}

int peak(node *head){
	return head->value;
}

int main(){
	node *top = initializeStack(5);
	push(top, 4);
	push(top, 3);
	pop(&top);
	pop(&top);
	pop(&top);
	pop(&top);
	cout << "\n";
	return 0;
}



