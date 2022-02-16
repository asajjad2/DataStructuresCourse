#include <iostream>
#include <string>
using namespace std;

template <class type>
struct Node1 {

public:
	type data;
	Node1<type>* next;

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

	Node1<type>* front;
	Node1<type>* rear;

	Queue() {
		front = NULL;
		rear = NULL;
	}

	bool isEmpty() {
		return(front == NULL);
	}

	void enqueue(type x) {

		Node1<type>* newNode = new Node1<type>;
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

			Node1<type>* temp = front;
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
			return NULL;
	}



};

template<class t2>
class Node {

public:

	t2 key;
	Node* left;
	Node* right;

	Node(t2 y) {
		key = y;
		left = NULL;
		right = NULL;
	}

	Node() {
		left = NULL;
		right = NULL;
	}



};

template<class t2>
class AVLTree {

public:

	Node<t2>* root;
	Node<t2>* current;
	Node<t2>* parentCurrent;

	AVLTree() {
		root = NULL;
		current = NULL;
		parentCurrent = NULL;
	}

	void insert(Node<t2> x) {

		if (root == NULL) {
			root = new Node<t2>(x);
		}
		else {
			current = root;
			while (current) {
				parentCurrent = current;

				if (current->key == x.key) {
					cout << "same keys, cannot repeat\n";
					break;
				}
				else {

					if (current->key > x.key)
						current = current->left;
					else
						current = current->right;

				}


			}


			if (parentCurrent->key > x.key)
				parentCurrent->left = new Node<t2>(x);
			else
				parentCurrent->right = new Node<t2>(x);
		}

	}

	void helpDisplayIn(Node<t2>* x) {

		if (x == NULL)
			return;

		helpDisplayIn(x->left);
		cout << x->key << " " << x->name << endl;
		helpDisplayIn(x->right);

	}

	void displayInOrder() {

		cout << "Inorder displayy\n";
		Node<t2>* temp = root;
		helpDisplayIn(temp);

	}

	void helpDisplayPre(Node<t2>* x) {

		if (x == NULL)
			return;

		cout << x->key << " " << x->name << endl;
		helpDisplayIn(x->left);
		helpDisplayIn(x->right);

	}

	void displayPreOrder() {

		cout << "Preorder displayy\n";
		Node<t2>* temp = root;
		helpDisplayPre(temp);

	}

	void helpDisplayPost(Node<t2>* x) {

		if (x == NULL)
			return;


		helpDisplayIn(x->left);
		helpDisplayIn(x->right);
		cout << x->key << " " << x->name << endl;

	}

	void displayPostOrder() {

		cout << "Postorder displayy\n";
		Node<t2>* temp = root;
		helpDisplayPost(temp);

	}

	void display() {

		displayInOrder();

	}



	bool retrieve(t2 searchKey) {


		bool check = false;

		if (!root) {
			cout << "root is empty, cannot retrieve anything\n";
			return check;
		}
		else {

			current = root;
			while (current) {

				if (current->key == searchKey) {
					check = true;
					break;
				}
				else if (current->key > searchKey)
					current = current->left;
				else
					current = current->right;

			}

		}

		return check;

	}

	void deleteFromTree(Node<t2>* toBeRemoved) {

		Node<t2>* temp;
		if (toBeRemoved == NULL)
			cout << "cannot delete a NULL node\n";
		else if (toBeRemoved->left == NULL && toBeRemoved->right == NULL) {

			temp = toBeRemoved;
			toBeRemoved = NULL;
			delete temp;

		}
		else if (toBeRemoved->left == NULL) {

			temp = toBeRemoved;
			toBeRemoved = temp->right;
			delete temp;

		}
		else if (toBeRemoved->right == NULL) {

			temp = toBeRemoved;
			toBeRemoved = temp->left;
			delete temp;

		}
		else {

			current = toBeRemoved->left;
			parentCurrent = NULL;

			while (current->right) {

				parentCurrent = current;
				current = current->right;

			}

			toBeRemoved->key = current->key;
			toBeRemoved->name = current->name;

			if (!parentCurrent)
				toBeRemoved->left = current->left;
			else
				toBeRemoved->right = current->right;

			delete current;
		}
	}

	void remove(t2 searchKey) {

		bool check = false;

		if (!root) {
			cout << "root is empty, cannot retrieve anything\n";
		}
		else {

			current = root;
			while (current) {

				if (current->key == searchKey) {
					check = true;
					break;
				}
				else {

					parentCurrent = current;

					if (current->key > searchKey)
						current = current->left;
					else
						current = current->right;

				}


			}

		}

		if (current == NULL)
			cout << "no item exits with such a key, cannot be deleted\n";
		else if (check) {

			if (current == root)
				deleteFromTree(root);
			else if (parentCurrent->key > searchKey)
				deleteFromTree(parentCurrent->left);
			else
				deleteFromTree(parentCurrent->right);

		}
		else
			cout << "no item exits with such a key, cannot be deleted\n";

	}

	int helpHeight(Node<t2>* x) {

		if (!x)
			return -1;
		else {

			int leftHeight = helpHeight(x->left);
			int rightHeight = helpHeight(x->right);

			if (leftHeight > rightHeight) {
				return (leftHeight + 1);
			}
			else {
				return (rightHeight + 1);
			}


		}

	}

	int height() {

		current = root;
		return helpHeight(current);


	}

};

