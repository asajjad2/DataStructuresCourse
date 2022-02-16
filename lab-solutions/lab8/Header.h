#pragma once
#include <iostream>
#include <string>
using namespace std;



//Task1


template <class T>
struct node
{
	T val;
	node<T>* next;
};


template <class T>
class stack {

private:
	node<T>* top;
	int currentSize;

public:
	stack() {
		top = NULL;
		currentSize = 0;
	}

	bool isEmpty() {

		return(top == NULL);

	}

	void clear() {

		node<T>* temp = new node<T>;

		while (top != NULL) {

			temp = top;
			top = top->next;
			delete temp;

		}

	}

	void push(T x) {

		node<T>* newnode = new node<T>;
		newnode->val = x;
		newnode->next = top;
		top = newnode;
		currentSize++;

	}

	node<T>* Peek() {

		return top;

	}

	void pop() {

		if (!isEmpty()) {
			node<T>* temp = new node<T>;
			temp = top;
			top = top->next;
			delete temp;
		}

		currentSize--;

	}

	int sizeofstack() {

		return currentSize;

	}

};

//Task2

template <class T>
class stackA {//array based stack implementation

private:

	int top;
	int maxSize;
	T* arr;

public:

	stackA(int size = 50) {

		maxSize = size;
		top = 0;

		arr = new T[maxSize];

	}

	bool isEmpty() {
		return(top == 0);
	}

	bool isFull() {
		return(maxSize == top);
	}

	T returnTop() {//returns value on top

		return arr[top - 1];


	}

	void push(T x) {

		if (!isFull())
			arr[top++] = x;
		else
			cout << "stack full\n";

	}

	void pop() {

		if (!isEmpty())
			top--;
		else
			cout << "stack already empty\n";
	}

};

template <class T>
class queueA {//array based queue implementation

private:

	T* arr;
	int maxSize;
	int front;
	int rear;
	int currentSize;

public:

	queueA(int x = 100) {

		if (x < 0)
			maxSize = 100;
		else
			maxSize = x;

		currentSize = 0;
		front = 0;
		rear = maxSize - 1;
		arr = new T[maxSize];

	}

	// ~queueA(){

	//     delete [] arr;

	// }

	bool isEmpty(void) {

		return(currentSize == 0);

	}

	bool isFull(void) {

		return(currentSize == maxSize);

	}

	void enqueue(T x) {

		if (!isFull()) {

			rear = (rear + 1) % maxSize;
			arr[rear] = x;
			currentSize++;

		}
		else {
			cout << "Queue full\n";
		}

	}

	void dequeue() {

		if (!isEmpty()) {

			front = (front + 1) % maxSize;
			currentSize--;

		}
		else {
			cout << "Queue empty\n";

		}


	}

	T returnFront() {

		if (isEmpty()) {
			cout << "empty queue\n";
		}

		return arr[front];

	}
};

queueA<char> q1;
stackA<char> s2;

bool checkPal(char* str) {

	int size = 0;
	while (str[size] != '\0') {//get size
		size++;
	}
	/*cout << str << endl;
	cout << size << endl;*/

	int count = 0;
	for (int i = 0; i < size; i++) {//removes spaces

		if (str[i] == ' ' && (i != size - 1)) {
			int j = i;
			while (str[j] != '\0') {
				str[j] = str[j + 1];
				j++;
			}
			str[j] = '\0';
			size--;
		}

	}

	/*cout << str << endl;
	cout << size << endl;*/
	char x;

	for (int i = 0; i < size; i++) {//removes non-alphabets

		x = str[i];

		if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)) {}
		else {
			int j = i;
			while (str[j] != '\0') {
				str[j] = str[j + 1];
				j++;
			}
			str[j] = '\0';
			size--;
			i--;
		}

	}

	/*cout << str << endl;
	cout << size << endl;*/

	for (int i = 0; i < size; i++) {

		if (str[i] >= 65 && str[i] <= 90) {
			str[i] = str[i] + 32;
		}

		s2.push(str[i]);
		q1.enqueue(str[i]);
	}

	/*cout << str << endl;*/
	bool y = true;


	for (int i = 0; i < size; i++) {

		if (s2.returnTop() == q1.returnFront()) {

			// cout << s.returnTop() << "&&" <<q.returnFront() << endl;
			s2.pop();
			q1.dequeue();

		}
		else {
			y = false;
			break;
		}



	}

	return y;

}