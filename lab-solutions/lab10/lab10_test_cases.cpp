#include "pch.h"
#include "../Sol/Header.h"
#include<iostream>
using namespace std;

TEST(TestCaseDelete, T1) {
	Node<string, int> node1("ahmad", 14);
	Node<string, int> node2("nabeel", 11);
	Node<string, int>node3("gohar", 9);
	Node<string, int>node4("Neil", 12);
	Node<string, int>node5("John", 17);
	Node<string, int>node6("Doe", 3);

	Tree<string, int> bst;
	bst.insert(node1);
	bst.insert(node2);
	bst.insert(node3);
	bst.insert(node4);
	bst.insert(node5);
	bst.insert(node6);
	bst.remove(11);
	bst.display();


}

TEST(TestCaseRetrieve, T2) {
	Node<string, int> node1("ahmad", 2);
	Node<string, int> node2("nabeel", 1);
	Node<string, int>node3("gohar", 4);
	Node<string, int>node4("Neil", 3);


	Tree<string, int> bst;
	bst.insert(node1);
	bst.insert(node2);
	bst.insert(node3);
	bst.insert(node4);
	EXPECT_TRUE(true, bst.retrieve(3));

}

TEST(TestCaseRetrieve, T3) {
	Node<string, int> node1("ahmad", 2);
	Node<string, int> node2("nabeel", 1);
	Node<string, int>node3("gohar", 4);
	Node<string, int>node4("Neil", 3);
	Tree<string, int> bst;
	bst.insert(node1);
	bst.insert(node2);
	bst.insert(node3);
	bst.insert(node4);
	EXPECT_TRUE(true, bst.retrieve(9));

}

TEST(TestCaseInOrder, T4) {
	Node<string, int> node1("ahmad", 2);
	Node<string, int> node2("nabeel", 1);
	Node<string, int>node3("gohar", 5);
	Node<string, int>node4("Neil", 3);
	Node<string, int>node5("John", 4);

	Tree<string, int> bst;
	bst.insert(node1);
	bst.insert(node2);
	bst.insert(node3);
	bst.insert(node4);
	bst.insert(node5);
	bst.displayInOrder();

}

TEST(TestCasePreOrder, T5) {
	Node<string, int> node1("ahmad", 2);
	Node<string, int> node2("nabeel", 1);
	Node<string, int>node3("gohar", 5);
	Node<string, int>node4("Neil", 3);
	Node<string, int>node5("John", 4);

	Tree<string, int> bst;
	bst.insert(node1);
	bst.insert(node2);
	bst.insert(node3);
	bst.insert(node4);
	bst.insert(node5);
	bst.displayPreOrder();
}

TEST(TestCasePostOrder, T6) {
	Node<string, int> node1("ahmad", 2);
	Node<string, int> node2("nabeel", 1);
	Node<string, int>node3("gohar", 5);
	Node<string, int>node4("Neil", 3);
	Node<string, int>node5("John", 4);

	Tree<string, int> bst;
	bst.insert(node1);
	bst.insert(node2);
	bst.insert(node3);
	bst.insert(node4);
	bst.insert(node5);
	bst.displayPostOrder();
}


TEST(TestCaseHeight, T7) {
	Node<string, int> node1("ahmad", 14);
	Node<string, int> node2("nabeel", 11);
	Node<string, int>node3("gohar", 9);
	Node<string, int>node4("Neil", 12);
	Node<string, int>node5("John", 17);
	Node<string, int>node6("Doe", 3);

	Tree<string, int> bst;
	bst.insert(node1);
	bst.insert(node2);
	bst.insert(node3);
	bst.insert(node4);
	bst.insert(node5);
	bst.insert(node6);
	EXPECT_EQ(3, bst.height());
}
TEST(TestCaseHeight, T8) {
	Node<string, int> node1("Ahmad", 14);
	Node<string, int> node2("Nabeel", 11);
	Node<string, int>node3("Gohar", 9);
	Node<string, int>node4("Neil", 12);
	Node<string, int>node5("John", 17);
	Node<string, int>node6("Doe", 18);
	Node<string, int>node7("Zee", 21);
	Node<string, int>node8("Kane", 29);

	Tree<string, int> bst;
	bst.insert(node1);
	bst.insert(node2);
	bst.insert(node3);
	bst.insert(node4);
	bst.insert(node5);
	bst.insert(node6);
	bst.insert(node7);
	bst.insert(node8);

	EXPECT_EQ(4, bst.height());
}