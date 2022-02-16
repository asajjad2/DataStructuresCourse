#pragma once
#include <iostream>
#include <string>

using namespace std;




template<class t1, class t2>
class Node {

public:

	t2 key;
	t1 name;
	Node* left;
	Node* right;

	Node(t1 x, t2 y) {
		key = y;
		name = x;
		left = NULL;
		right = NULL;
	}

	Node() {
		left = NULL;
		right = NULL;
	}



};





template<class t1, class t2>
class Tree {

public:

	Node<t1, t2>* root;
	Node<t1, t2>* current;
	Node<t1, t2>* parentCurrent;

	Tree() {
		root = NULL;
		current = NULL;
		parentCurrent = NULL;
	}

	void insert(Node<t1, t2> x) {

		if (root == NULL) {
			root = new Node<t1, t2>(x);
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
				parentCurrent->left = new Node<t1, t2>(x);
			else
				parentCurrent->right = new Node<t1, t2>(x);
		}

	}

	void helpDisplayIn(Node<t1, t2>* x) {

		if (x == NULL)
			return;
		
		helpDisplayIn(x->left);
		cout << x->key << " " << x->name <<  endl;
		helpDisplayIn(x->right);

	}

	void displayInOrder() {

		cout << "Inorder displayy\n";
		Node<t1, t2>* temp = root;
		helpDisplayIn(temp);

	}

	void helpDisplayPre(Node<t1, t2>* x) {

		if (x == NULL)
			return;

		cout << x->key << " " << x->name << endl;
		helpDisplayIn(x->left);
		helpDisplayIn(x->right);

	}

	void displayPreOrder() {

		cout << "Preorder displayy\n";
		Node<t1, t2>* temp = root;
		helpDisplayPre(temp);

	}

	void helpDisplayPost(Node<t1, t2>* x) {

		if (x == NULL)
			return;

		
		helpDisplayIn(x->left);
		helpDisplayIn(x->right);
		cout << x->key << " " << x->name << endl;

	}

	void displayPostOrder() {

		cout << "Postorder displayy\n";
		Node<t1, t2>* temp = root;
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

	void deleteFromTree(Node<t1, t2>* toBeRemoved) {

		Node<t1, t2>* temp;
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

		if(current == NULL)
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

	int helpHeight(Node<t1, t2>* x) {

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