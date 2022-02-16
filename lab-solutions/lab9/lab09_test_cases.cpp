#include "pch.h"
#include "../Sol/Header.h"
#include<iostream>
using namespace std;

TEST(TestCaseInsert, T1) {
	Node<string, int> node1("ahmad", 2);
	Node<string, int> node2("nabeel", 1);
	Node<string, int>node3("gohar", 3);

	Tree<string, int> bst;
	bst.insert(node1);
	bst.insert(node2);
	bst.insert(node3);
	bst.display();


}

TEST(TestCaseRetrieve, T2) {
	Node<string, int> node1("ahmad", 2);
	Node<string, int> node2("nabeel", 1);
	Node<string, int>node3("gohar", 3);

	Tree<string, int> bst;
	bst.insert(node1);
	bst.insert(node2);
	bst.insert(node3);
	EXPECT_TRUE(true, bst.retrieve(3));

}

TEST(TestCaseRetrieve, T3) {
	Node<string, int> node1("ahmad", 2);
	Node<string, int> node2("nabeel", 1);
	Node<string, int>node3("gohar", 3);

	Tree<string, int> bst;
	bst.insert(node1);
	bst.insert(node2);
	bst.insert(node3);
	EXPECT_TRUE(true, bst.retrieve(9));

}

TEST(TestCaseRetrieve, T4) {
	Node<string, int> node1("ahmad", 2);
	Node<string, int> node2("nabeel", 1);
	Node<string, int>node3("gohar", 3);

	Tree<string, int> bst;
	bst.insert(node1);
	bst.insert(node2);
	bst.insert(node3);
	bst.display();

}

TEST(TestCaseDB, T5) {
	//considering record# as key and account information as data
	//write the test case for creating Accounts DB and verify its correctness
	

}

TEST(TestCaseInorderTraversal, T6) {
	//using the T5 create an account BST, then call the below inOrderTraversal function
	//on it
	//	bst.inOrderTraversal();


}