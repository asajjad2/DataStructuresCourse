#include "pch.h"
#include "../AVL/Header.h"
TEST(TestCaseInsertion, T1) {
	Node<int> node1(10);
	Node<int> node2(11);
	Node<int> node3(12);
	Node<int> node4(13);
	Node<int> node5(14);
	Node<int> node6(16);
	Node<int> node7(17);

	AVLTree<int> avl;
	avl.insert(node1);
	avl.insert(node2);
	avl.insert(node3);
	avl.insert(node4);
	avl.insert(node5);
	avl.insert(node6);
	avl.insert(node7);
	EXPECT_EQ(2, avl.height());
}
TEST(TestCaseInsertion, T2) {
	Node<int> node1(10);
	Node<int> node2(11);
	Node<int> node3(12);
	Node<int> node4(13);
	Node<int> node5(14);
	Node<int> node6(16);
	Node<int> node7(17);

	AVLTree<int> avl;
	avl.insert(node1);
	avl.insert(node2);
	avl.insert(node3);
	avl.insert(node4);
	avl.insert(node5);
	avl.insert(node6);
	avl.insert(node7);
	EXPECT_TRUE(true, avl.isBalance());
}
TEST(TestCaseInsertion, T3) {
	Node<int> node1(63);
	Node<int> node2(9);
	Node<int> node3(19);
	Node<int> node4(27);
	Node<int> node5(18);
	Node<int> node6(108);
	Node<int> node7(99);
	Node<int> node8(81);

	AVLTree<int> avl;
	avl.insert(node1);
	avl.insert(node2);
	avl.insert(node3);
	avl.insert(node4);
	avl.insert(node5);
	avl.insert(node6);
	avl.insert(node7);
	avl.insert(node8);
	EXPECT_EQ(3, avl.height());

}
TEST(TestCaseInsertion, T4) {
	Node<int> node1(63);
	Node<int> node2(9);
	Node<int> node3(19);
	Node<int> node4(27);
	Node<int> node5(18);
	Node<int> node6(108);
	Node<int> node7(99);
	Node<int> node8(81);

	AVLTree<int> avl;
	avl.insert(node1);
	avl.insert(node2);
	avl.insert(node3);
	avl.insert(node4);
	avl.insert(node5);
	avl.insert(node6);
	avl.insert(node7);
	avl.insert(node8);
	EXPECT_TRUE(true, avl.isBalance());
}