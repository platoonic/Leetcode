#include <iostream>

using namespace std;

//Implementing a Queue using linked lists
//Basic struct for linked list node elements
struct node{
	int value;
	node* next;
};

//Initializes a queue
node *initializeQueue(int value){
	node* head = new node();
	head->value = value;
	head->next  = NULL;
	cout << "Queue: " << value << "\n";
	return head;
}

void queue(node** top, int value){
	node* head = *top;
	node* newNode = new node();
	newNode-> value = value;
	cout << "Queue: " << value << "\n";
	if(head == NULL){
		head = newNode;
		return;
	}
	if(head->next == NULL){
		head->next = newNode;
		return;
	}
	head = head->next;
	while(head != NULL){
		if(head->next == NULL){
			head->next = newNode;
			return;
		}
		head = head->next;
	}
}

void dequeue(node** top){
	node* temp = *top;
	if(temp == NULL){
		cout << "Queue is empty";
		return;
	}
	int value = temp->value;
	free(*top);
	*top = (*top)->next;
	cout << "Dequeue: " << value << "\n";
	return;
}

int main(){
	node* top = initializeQueue(1);
	queue(&top, 2);
	queue(&top, 3);
	queue(&top, 4);
	dequeue(&top);
	dequeue(&top);
	dequeue(&top);
	dequeue(&top);
	dequeue(&top);

	cout << "\n";
	return 0;
}