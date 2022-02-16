#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <conio.h>
#include <fstream>
using namespace std;

template <class T>
class Node {
public:
	T data ;
	Node* next; 

	Node() {
		data = 0;
		next = NULL;
	}

	Node(T x) {
		data = x;
		next = NULL;
	}

};

template <class T>
class SLinkedList {

public:
	Node<T>* head;

	SLinkedList(){
		head = NULL;
	}

	void insert(T x) {

		Node<T>* lastNode;

		lastNode = head;
		
		if (lastNode == NULL) {
			lastNode = new Node<T>;
			lastNode->data = x;
			lastNode->next = NULL;
			head = lastNode;
		}
		else {
			Node<T>* nextNode = lastNode->next;
			while (nextNode != NULL) {//locate the last node

				nextNode = lastNode->next;
				if (nextNode == NULL) {
					break;
				}
				lastNode = nextNode;


			}

			lastNode->next = new Node<T>;
			lastNode = lastNode->next;
			lastNode->data = x;
			lastNode->next = NULL;
		}
		

	}

	void insertAtHead(T x) {

		Node<T>* temp;

		temp = head;

		if (temp == NULL) {
			temp = new Node<T>;
			temp->data = x;
			temp->next = NULL;
			head = temp;
		}
		else {
			Node<T>* newNode = new Node<T>;
			newNode->data = x;
			newNode->next = head;
			head = newNode;

		}
	}

	void InsertAtIndex(T x,int index) {
		if (index < 0)
			return;
		int count = 1;
		Node<T>* temp = head;
		while (temp && index > count) {

			temp = temp->next;
			count++;

		}
		if (index > 0 && temp == NULL) {
			return;
		}
		
		Node<T>* newNode = new Node<T>;
		
		if (index == 0) {

			insertAtHead(x);

		}
		else {//inserting in middle
			newNode->data = x;
			newNode->next = temp->next;
			temp->next = newNode;

		}
		return;

	}


	bool isEmpty() {

		if (head == NULL)
			return true;
		else
			return false;

	}

	int search(T val) {
		Node<T>* temp = head;
		int count = 1;
		while (temp && temp->data != val) {

			temp = temp->next;
			count++;

		}
		if (temp) return count;

		return 0;
	}

	void update(T x,T val) {
		Node<T>* temp = head;
		
		while (temp) {

			if (temp->data == x) {
				temp->data = val;
				break;
			}
			temp = temp->next;
			

		}
	}

	void remove(T x) {

		Node<T>* temp = head;
		Node<T>* before;
		while (temp) {

			if (temp->data == x) {
				before->next = temp->next;
				delete temp;
				break;
			}
			else if (temp == NULL)
				return;

			before = temp;
			temp = temp->next;


		}
		
	}
	

	void mergeLists(SLinkedList<T> obj2) {
		Node<T>* temp = obj2.head;

		for (int i = 1; i < 8; i += 2) {
			this->InsertAtIndex(temp->data, i);
			//cout << temp->data;
			temp = temp->next;
		}
			

	}
	void print() {
		
		Node<T>* currentNode = this->head;
		int count = 0;
		while (currentNode != NULL) {
			cout << currentNode->data << endl;
			currentNode = currentNode->next;
			
		}
	}
	bool isPalindrom() {
		
		Node<T>* before = NULL;
		Node<T>* reverse = this->head;
		Node<T>* nxt = NULL;

		Node<T>* temp = head;
		
		while (reverse != NULL) {//reversing list
			
			nxt->reverse->next;
			reverse->next = before;
			before = reverse;
			reverse = before;

		}
		head = before;
		while (reverse != NULL) {
			cout << reverse->data << endl;
			reverse = reverse->next;

		}
		cout << endl;
		
		
		while (temp != NULL) {
			cout << temp->data << endl;
			temp = temp->next;

		}
		bool check=true;
		while (reverse != NULL) {
			if (temp->data != reverse->data) {
				check = false;
				break;
			}
		}
		return check;
	}

};