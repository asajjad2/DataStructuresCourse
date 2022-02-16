#pragma once

struct Node
{
	int data;
	struct Node* next;

	Node() {
		data = 0;
		next = NULL;
	}
	Node(int x) {
		data = x;
		next = NULL;
	}
};


struct List {

	Node* last;
	static int count;
	List() {
		last = NULL;
	}

	Node* insert(int x) {

		count++;

		if (last == NULL) {
			Node* newNode = new Node;
			newNode->data = x;
			last = newNode;
			last->next = last;
			return last;
		}
		else {
			Node* newNode = new Node;
			newNode->data = x;
			newNode->next = last->next;
			last->next = newNode;
			last = newNode;
			return last;
		}

	}

	int getSize() const {
		return count;
	}

	Node* getJosephusPosition(int m) {//n is count
		Node* head = last->next;
		Node* temp1 = head;
		Node* temp2 = head;
		while (temp1->next != temp1) {

			for (int i = 0; i < m; i++) {
				temp2 = temp1;
				temp1 = temp1->next;
			}
			temp2->next = temp1->next;
			delete temp1;
			temp1 = temp2->next;

		}
		return temp1;
	}


};
int List::count = 0;