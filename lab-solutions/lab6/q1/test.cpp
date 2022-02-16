#include "pch.h"
#include "Header.h"
using namespace std;

linkList<string, int> obj;
string id = "01";
string c = "45678-4535676-0";
string j = "18/10/2021";
int k = 50000;
int b = 5000;
string id2 = "02";
string c2 = "45778-4535676-0";
string j2 = "18/10/2020";
int k2 = 10000;
int b2 = 5000;
string id3 = "03";
string c3 = "45878-4535676-0";
string j3 = "18/10/2019";
int k3 = 20000;
int b3 = 5000;
TEST(Insert, T1) {
	obj.insert(id, c, j, k, b);
	Node<string, int>* emp = new Node<string, int>(id, c, j, k, b);
	EXPECT_EQ(emp->getId(), "01");
	EXPECT_EQ(emp->getCNIC(), "45678-4535676-0");
	EXPECT_EQ(emp->getJoinDate(), "18/10/2021");
	EXPECT_EQ(emp->getSal(), 50000);
	EXPECT_EQ(emp->getBonus(), 5000);
}

TEST(InsertAfterSearch, T1) {

	Node<string, int>* s = obj.search("01");
	cout << s->getId();
	EXPECT_EQ("01", s->getId());

}

TEST(Remove, T1) {
	linkList<string, int> obj;
	string chk = "01";
	//cout << obj.remove(chk) << endl;
	ASSERT_TRUE(true, obj.remove(chk));
	string chk1 = "02";
	//cout << obj.remove(chk1) << endl;
	ASSERT_FALSE(false, obj.remove(chk1));
}

TEST(Update, T1) {
	obj.insert(id, c, j, k, b);
	string i = "01";
	EXPECT_EQ(100000, obj.UpdateSalary(i, 100000));

}

TEST(Max, T1) {
	obj.insert(id2, c2, j2, k2, b2);
	obj.insert(id3, c3, j3, k3, b3);
	int a = obj.MaxSalary();
	EXPECT_EQ(100000, a);
}

