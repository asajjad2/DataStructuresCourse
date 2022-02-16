#include "pch.h"
#include "Header.h"
using namespace std;

stack<int> s1; 

TEST(task1, T1) {
	s1.push(1);
	s1.push(2);
	s1.push(3);
	node<int>* top = s1.Peek();
	EXPECT_EQ(3, top->val);
}

TEST(task1, T2) {
	s1.pop();
	node<int>* top = s1.Peek();
	EXPECT_EQ(2, top->val);
	s1.pop();
	top = s1.Peek();
	EXPECT_EQ(1, top->val);

}
TEST(task1, T3) {
	s1.push(3);
	s1.push(4);
	EXPECT_EQ(3, s1.sizeofstack());
}

TEST(task2, T4) {
	char str[] = "M A%! DAm#";
	EXPECT_TRUE(checkPal(str));
}

TEST(task2, T5) {
	char str[] = "% Universi ty % ";
	EXPECT_FALSE(checkPal(str));
}