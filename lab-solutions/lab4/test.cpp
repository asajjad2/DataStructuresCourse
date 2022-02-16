#include "pch.h"
#include "Header.h"

////////////////////////////// Q1///////////////////////////

TEST(List, insert) {
	List<int> obj1(5);
	ASSERT_EQ(true, obj1.insert(1));
	ASSERT_EQ(true, obj1.insert(2));
	ASSERT_EQ(true, obj1.insert(3));
	ASSERT_EQ(true, obj1.insert(4));
	ASSERT_EQ(true, obj1.insert(5));
	ASSERT_EQ(false, obj1.insert(6));
	obj1.print();

}

TEST(List, insertat) {
	List<int> obj1(5);
	
	ASSERT_EQ(true, obj1.insert(1)); //0
	ASSERT_EQ(true, obj1.insert(2)); //1
	ASSERT_EQ(true, obj1.insert(3)); //2
	ASSERT_EQ(true, obj1.insert(4)); //3
	//obj1.print();
	bool f = obj1.insertAt(3, 1);
	EXPECT_EQ(3, obj1.ptr[1]);
	obj1.print();


}

TEST(List, insertafter) {
	List<int> obj1(5);
	ASSERT_EQ(true, obj1.insert(1));
	ASSERT_EQ(true, obj1.insert(2));
	ASSERT_EQ(true, obj1.insert(3));
	ASSERT_EQ(true, obj1.insert(4));

	obj1.insertAfter(5, 4);
	EXPECT_EQ(5, obj1.ptr[4]);
	obj1.print();
}

TEST(List, insertbefore) {
	List<int> obj1(5);
	ASSERT_EQ(true, obj1.insert(1));
	ASSERT_EQ(true, obj1.insert(2));
	ASSERT_EQ(true, obj1.insert(3));
	ASSERT_EQ(true, obj1.insert(5));

	obj1.insertBefore(4, 5);
	EXPECT_EQ(4, obj1.ptr[3]);
	obj1.print();
}

TEST(List, remove) {
	List<int> obj1(5);
	ASSERT_EQ(true, obj1.insert(1));
	ASSERT_EQ(true, obj1.insert(2)); //1
	ASSERT_EQ(true, obj1.insert(3));
	ASSERT_EQ(true, obj1.insert(4));
	ASSERT_EQ(true, obj1.insert(5));
	obj1.remove(1);
	int j = 2;
	for (int i = 0; i < 4; i++)
	{
		EXPECT_EQ(j++, obj1.ptr[i]);
		cout << obj1.ptr[i] << endl;
	}


	
}

TEST(List, removeafter) {
	List<int> obj1(5);
	ASSERT_EQ(true, obj1.insert(1));
	ASSERT_EQ(true, obj1.insert(2));
	ASSERT_EQ(true, obj1.insert(3));
	ASSERT_EQ(true, obj1.insert(4));
	ASSERT_EQ(true, obj1.insert(5));
	obj1.removeAfter(3);
	EXPECT_EQ(5, obj1.ptr[3]);
	obj1.print();
}

TEST(List, removebefore) {
	List<int> obj1(4);
	ASSERT_EQ(true, obj1.insert(1));
	ASSERT_EQ(true, obj1.insert(2));
	ASSERT_EQ(true, obj1.insert(3));
	ASSERT_EQ(true, obj1.insert(4));

	obj1.removeBefore(3);
	EXPECT_EQ(3, obj1.ptr[1]);
	obj1.print();
}

TEST(List, reverse) {
	List<int> obj1(5);
	ASSERT_EQ(true, obj1.insert(1));
	ASSERT_EQ(true, obj1.insert(2));
	ASSERT_EQ(true, obj1.insert(3));
	ASSERT_EQ(true, obj1.insert(4));
	ASSERT_EQ(true, obj1.insert(5));
	obj1.reverse();
	int j = 5;
	for (int i = 0; i < 5; i++)
	{
		EXPECT_EQ(j--, obj1.ptr[i]);
	}

	obj1.print();
}

TEST(PasswordValidation, T1) {
	EXPECT_EQ(false, PasswordValidation("abc123"));

}
TEST(PasswordValidation, T2) {
	EXPECT_EQ(false, PasswordValidation("abc_123"));
}
TEST(PasswordValidation, T3) {
	EXPECT_EQ(false, PasswordValidation("ab.8"));
}
TEST(PasswordValidation, T4) {
	EXPECT_EQ(false, PasswordValidation("asdfghj__12345"));
}
TEST(PasswordValidation, T5) {
	EXPECT_EQ(false, PasswordValidation("uioyi#12"));
}

TEST(EmailValidation, T1) {
	EXPECT_EQ(true, EmailValidation("abc@gmail.com"));

}
TEST(EmailValidation, T2) {
	EXPECT_EQ(true, EmailValidation("ab.c@hotmail.com"));
}
TEST(EmailValidation, T3) {
	EXPECT_EQ(false, EmailValidation("abc-@gmail.com"));

}
TEST(EmailValidation, T4) {
	EXPECT_EQ(false, EmailValidation("abcgmail.com"));
}
TEST(EmailValidation, T5) {
	EXPECT_EQ(false, EmailValidation("abc@gmail.c"));
}