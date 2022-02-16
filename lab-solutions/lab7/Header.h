#pragma once
#include <iostream>
#include <string>
using namespace std;


template <class type>
struct Node {

public:
	type data;
	Node<type>* next;

	type getData() const {
		return data;
	}

	void setData(type x) {
		data = x;
	}

};


template <class type>
class Queue {

public:

	Node<type>* front;
	Node<type>* rear;

	Queue() {
		front = NULL;
		rear = NULL;
	}

	Node<type>* getRear() {
		return rear;
	}

	bool isEmpty() {
		return(front == NULL);
	}

	void enqueue(type x) {

		Node<type>* newNode = new Node<type>;
		newNode->setData(x);
		newNode->next = NULL;

		if (isEmpty()) {
			front = newNode;
			rear = newNode;
		}
		else {
			rear->next = newNode;
			rear = newNode;
		}

	}

	void dequeue() {

		if (isEmpty()) {

			cout << "cannot remove items from an empty queue\n";

		}
		else {

			Node<type>* temp = front;
			front = front->next;
			delete temp;

			if (front == NULL)
				rear = NULL;


		}

	}

	type Front() {

		if (front != NULL)
			return front->getData();
		else
			return -1;
	}



};



void roundRobin(Queue<int> q1, int timeQuantum) {

	int frontData;
	cout << endl;
	while (!(q1.isEmpty())) {

		frontData = q1.Front();

		cout << "Execution time: " << frontData << endl;
		cout << "Remaining time: " << frontData - timeQuantum << endl;

		if (frontData - timeQuantum <= 0) {

			q1.dequeue();
			cout << "Task is completed, it is removed from queue\n\n";

		}
		else if (frontData - timeQuantum > 0) {

			cout << "Task is not completed, it is being re-scheduled\n\n";
			q1.enqueue(frontData - timeQuantum);
			q1.dequeue();

		}


	}

}

Queue<char> queueConcat(string x) {


	//cout << x << endl;
	Queue<char> allQueues[5];
	int arrIndex = 0;
	int i = 0;
	while (x[i] != '\0') {
		//cout << x[i] << endl;
		while (x[i] != ' ') {

			if (x[i] == '\0')
				break;
			cout << x[i] << endl;
			allQueues[arrIndex].enqueue(x[i]);
			i++;
		}
		allQueues[arrIndex].enqueue('$');
		if (x[i] != '\0') {
			i++;
			arrIndex++;
		}
		

	}
	//cout << arrIndex << endl;
	Queue<char> result;

	for(i = 0; i == arrIndex; i++) {

		while (allQueues[i].Front() != '$') {
			result.enqueue(allQueues[i].Front());
			allQueues[i].dequeue();
		}

	}

	return result;

}