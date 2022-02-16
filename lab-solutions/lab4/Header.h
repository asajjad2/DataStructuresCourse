#pragma once
#include <iostream>
#include <string>
using namespace std;
template <class T>

class List{

private:

	
	int capacity;
	int counter;

public:
	T* ptr;

	List(int size) {
		ptr = new T[size];
		capacity = size;
		counter = 0;
	}

	bool isEmpty() {
		if (counter == 0) {
			return true;
		}
		else
			return false;
	}

	bool isFull() {
		if (counter == capacity)
			return true;
		else
			return false;
	}

	bool insert(T item) {
		if (!isFull()) {
			ptr[counter] = item;
			counter++;
			return true;
		}
		else
			return false;
	}

	void print() {
		for (int i = 0; i < capacity; i++) {
			cout << ptr[i] << endl;
		}
	}

	bool insertAt(T item, int index) {

		T temp;
		
		if (index < capacity) {

			if (index == counter) {
				bool temp = insert(item);
			}
			else if (index > counter) {
				ptr[index] = item;
			}
			/*T temp = ptr[index],temp2;*/
			/*ptr[index] = item;
			ptr[index + 1] = temp;*/
			else {

				for (int i = counter; i > index-1; i--) {

					ptr[i + 1] = ptr[i];
			
					//cout << ptr[i];
				}

				ptr[index] = item;
			}
			counter++;
			return true;

		}
		else
			return false;

	}

	bool insertAfter(T itemTobeInserted, T item) {


		int indA;
		for (int i = 0; i < capacity; i++) {
			if (item == ptr[i]) {
				indA = i;
				break;
			}
		}
		bool x = insertAt(itemTobeInserted, indA + 1);
		return x;
	}

	bool insertBefore(T itemTobeInserted, T item) {
		int indB;
		for (int i = 0; i < capacity; i++) {
			if (item == ptr[i]) {
				indB = i;
				break;
			}
		}
	
		bool x = insertAt(itemTobeInserted, indB );
		return x;
	}

	bool remove(T item) {

		int indR=-100;
		for (int i = 0; i < capacity; i++) {
			if (item == ptr[i]) {
				indR = i;
				break;
			}
		}
		
		if (indR == -100) {
			return false;

		}
		/*else {
			for (int i = counter; i > indR; i--) {
				cout << ptr[i];
				ptr[i - 1] = ptr[i];
			}
			ptr[counter] = 0;
			counter--;
			print();
			return true;
		}*/
		else {
			for (int i = indR; i < counter; i++) {

				ptr[i] = ptr[i+1];
			}
			ptr[counter-1] = 0;
			counter--;
			return true;
		}
		
		
	}

	void removeBefore(T item) {

		T before;
		for (int i = 0; i < capacity; i++) {
			if (item == ptr[i]) {
				before = ptr[i - 1];
				break;
			}

		}

		bool x = remove(before);
	}

	void removeAfter(T item) {

		T after;
		for (int i = 0; i < capacity; i++) {
			if (item == ptr[i]) {
				after = ptr[i + 1];
				break;
			}

		}

		bool x = remove(after);
	}

	void reverse() {

		T arr1[5] = { 0,0,0,0,0 };
		for (int i = 0, j = counter; i < counter; i++,j--) {
			arr1[i] = ptr[j-1];
			
		}
		
		for (int i = 0; i < counter; i++) {
			
			ptr[i] = arr1[i];
		}

		
	}

};


bool PasswordValidation(string x) {

	if (x.length() < 11 && x.length() > 5) {
		bool c, s, d;
		c = s = d = false;
		for (int i = 0; i < x.length() + 1; i++) {
			if (x[i] >= 65 && x[i] <= 90)
				c = true;
			if (x[i] >= 48 && x[i] <= 57)
				d = true;
			if ((x[i] >= 91 && x[i] <= 96) || (x[i] >= 33 && x[i] <= 47))
				s = true;
		}

		if (s && d && c)
			return true;
		else
			return false;
	}
	else
		return false;

}


bool EmailValidation(string x)
{
	string p, d, l;
	p = d = l = "";

	int length;
	for (length = 0; x[length] != '\0'; length++);

	int i;
	for (i = 0;x[i] != '@' && i < length; i++)
		p += x[i];

	if (i == length)
		return false;

	for (i++; x[i] != '.' && i < length; i++)
		d += x[i];

	if (i == length)
		return false;

	for (i++; x[i] != '\0'; i++)
		l += x[i];

	if (l != "com")
		return false;

	if (!((p[0] > 64 && p[0] < 91) || (p[0] > 96 && p[0] < 123)))
		return false;

	int special = 0;
	for (int i = 0; p[i] != '\0'; i++)
	{
		if (!((p[i] > 64 && p[i] < 91) || (p[i] > 96 && p[i] < 123) || p[i] == '-' || p[i] == '.' || p[i] == '_'))
			return false;
		if (p[i] == '-' || p[i] == '.' || p[i] == '_')
			if (p[i + 1] == '-' || p[i + 1] == '.' || p[i + 1] == '_')
				return false;
		if (p[i + 1] == '\0')
			if (p[i] == '-' || p[i] == '.' || p[i] == '_')
				return false;
	}
	if (!(d == "gmail" || d == "hotmail" || d == "yahoo"))
		return false;

	return true;
}