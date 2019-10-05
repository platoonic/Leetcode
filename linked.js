/* Linked list in JS */

function Node(value, next){
	this.value = value;
	this.next  = next;
}

class LinkedList{
	constructor(value){
		this.head = new Node(value, null);
	}
	addNodeAtEnd(value){
		let node = new Node(value, null);
		let temp = this.head;
		while(temp.next != null){
			temp = temp.next;
		}
		temp.next = node;
	}
	traverseList(){
		while(this.head != null){
			console.log(this.head.value);
			this.head = this.head.next;
		}
		console.log("\n");
	}
	reverseList(){
		let prev = null;
		let current = this.head;
		while(current.next != null){
			let next = {...current.next};
			current.next = prev;
			prev = current;
			current = next;
		}
		this.head = current;
	}
}

let linkedList = new LinkedList(1);

linkedList.addNodeAtEnd(2);
linkedList.addNodeAtEnd(3);
linkedList.addNodeAtEnd(4);
linkedList.reverseList();
linkedList.traverseList();






