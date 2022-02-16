#include "pch.h"
#include "Header.h"


TEST(getJosephusPosition, T1) {
	Node* last;
	List circular;
	int num = 0;

	int n = 6, m = 2;
	for (int i = 1; i <= n; i++) {
		last = circular.insert(i);
	}
	last = circular.getJosephusPosition(m);
	EXPECT_EQ(1, last->data);

}

TEST(getJosephusPosition, T2) {
	Node* last;
	List circular;
	int num = 0;

	int n = 5, m = 1;
	for (int i = 1; i <= n; i++) {
		last = circular.insert(i);
	}
	last = circular.getJosephusPosition(m);
	EXPECT_EQ(3, last->data);

}

TEST(getJosephusPosition, T3) {
	Node* last;
	List circular;
	int num = 0;

	int n = 9, m = 3;
	for (int i = 1; i <= n; i++) {
		last = circular.insert(i);
	}
	last = circular.getJosephusPosition(m);
	EXPECT_EQ(1, last->data);

}