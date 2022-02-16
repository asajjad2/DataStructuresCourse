#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class Type1,class Type2>
class Node {


	

public:

	Type1 EmpID;
	Type1 CNIC;
	Type1 JoiningDate;

	Type2 Salary;
	Type2 Bonus;

	Node* next;
	Node* prev;

	Node() {
		next = NULL;
		prev = NULL;
		EmpID = "";
		CNIC = "";
		JoiningDate = "";
		Salary = 0;
		Bonus = 0;
	}

	Node(Type1 v, Type1 w, Type1 x, Type2 y, Type2 z) {
		next = NULL;
		prev = NULL;
		EmpID = v;
		CNIC = w;
		JoiningDate = x;
		Salary = y;
		Bonus = z;
	}

	void insertData(Type1 v, Type1 w, Type1 x, Type2 y, Type2 z) {
		EmpID = v;
		CNIC = w;
		JoiningDate = x;
		Salary = y;
		Bonus = z;
	}

	Type1 getId() const{
		return EmpID;
	}

	Type1 getCNIC() const {
		return CNIC;
	}

	Type1 getJoinDate() const {
		return JoiningDate;
	}
	
	Type2 getSal() const {
		return Salary;
	}

	void setSal(Type2 x) {
		Salary = x;
	}

	Type2 getBonus() const {
		return Bonus;
	}

};

template <class Type1, class Type2>
class linkList {

public: 

	Node<Type1, Type2>* head;

	linkList(){
		head = NULL;
	}

	bool isEmpty() {
		return (!head);
	}

	void insert(Type1 v, Type1 w, Type1 x, Type2 y, Type2 z){

		Node<Type1, Type2>* newNode = new Node<Type1, Type2>;
		newNode->insertData(v, w, x, y, z);
		
		if (isEmpty()) {

			head = newNode;
			head->next = NULL;
			head->prev = NULL;

		}
		else {

			Node<Type1, Type2>* temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}

			newNode->prev = temp;
			newNode->next = temp->next;
			temp->next = newNode;
			temp = newNode;

		}
	}

	Node<Type1,Type2>* search(Type1 id) {

		Node<Type1, Type2>* temp = head;
		while (temp->next != NULL) {

			if (temp->getId() == id)
				return temp;
			else
				temp = temp->next;

		}
		return temp;

	}

	bool remove(Type1 id) {

		bool x = false;
		Node<Type1, Type2>* temp = head;
		while (temp->next != NULL) {



			if (temp->getId() == id) {
				Node<Type1, Type2>* oldNode = temp;
				oldNode->prev->next = oldNode->next;
				oldNode->next->prev = oldNode->prev;
				temp = oldNode->prev;
				delete oldNode;
				//cout << x;
				x = !x;
				return x;
			}
			else
				temp = temp->next;
				
		}
		//cout << x;
		return x;

	}

	Type2 UpdateSalary(Type1 id, Type2 newSal) {

		Node<Type1, Type2>* temp = head;
		while (temp->next != NULL) {



			if (temp->getId() == id) {
				temp->setSal(newSal);
				break;
			}
			else
				temp = temp->next;

		}
		//cout << x;
		return temp->getSal();

	}

	Type2 MaxSalary() {

		Node<Type1, Type2>* temp = head;
		Type2 max = temp->getSal();

		while (temp->next != NULL) {



			if (temp->getSal() > max) {
				max = temp->getSal();
			}
			else
				temp = temp->next;

		}

		return max;
	}

	
};





