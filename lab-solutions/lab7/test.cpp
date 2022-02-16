#include "pch.h"
#include "Header.h"

TEST(TestEnqueue, T1) {
	Queue < int> obj;
	for (int i = 2; i <= 10; i = i + 2) {
		obj.enqueue(i);
		EXPECT_EQ(i, obj.getRear()->getData());
	}

}
TEST(TestDequeue, T2) {
	Queue < int> obj;
	for (int i = 2; i <= 10; i = i + 2) {
		obj.enqueue(i);

	}
	for (int i = 10; i <= 2; i = i - 2) {
		obj.dequeue();
		EXPECT_EQ(i, obj.Front());
	}

}
TEST(TestIsEmpty, T3) {
	Queue < int> obj;
	obj.enqueue(3);
	EXPECT_EQ(false, obj.isEmpty());

	obj.dequeue();
	EXPECT_EQ(true, obj.isEmpty());

}
TEST(TestRoundRobin, T4) {

	Queue < int> obj;
	obj.enqueue(50);
	obj.enqueue(30);
	obj.enqueue(80);
	obj.enqueue(100);
	roundRobin(obj, 30);


}
TEST(TestQueueConcat, T5) {

	string str = "Data Structures and Algorithms";
	Queue<char>obj = queueConcat(str);
	int i = 0;
	while (!obj.isEmpty() && i != str.length()) {
		if (str[i] != ' ') {
			EXPECT_EQ(str[i], obj.Front());
			obj.dequeue();

		}i++;
	}


}