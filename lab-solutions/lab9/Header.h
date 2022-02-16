#pragma once

#include <iostream>
#include <string>

using namespace std;

template<class t1, class t2>
class Node{

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
				root = new Node<t1,t2>(x);
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

		void display() {

			/*current = root;

			stack s1<Node<t1, t2>>;

			while (current) {

				if (current) {

					s1.push(current);

					current = current->left;

				}
				else {

					current = s1.top();

				}

			}*/

			cout << "Root node::" << root->name << root->key << endl;
			cout << "Left node::" << root->left->name << root->left->key << endl;
			cout << "Right node::" << root->right->name << root->right->key << endl;

		}

};