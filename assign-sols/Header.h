#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;


template<typename T>
struct QueueNode {
	T value;
	QueueNode* next;

};

template <class T>
struct Stack {
	T* array;
	int stackTop;
	int stackSize;

	Stack(int s = 6) // 40 is just a random big number for the array to store data into
	{
		array = NULL;
		stackTop = -1;
		stackSize = s;
		array = new T[stackSize]{ 0 };
	}

	~Stack()
	{
		delete array;
	}

	void push(T item) // pushes items into the array stack
	{
		if (stackTop == -1)
		{
			array[0] = item;
			stackTop = 0;
		}
		else
		{
			if (!isFull())
			{
				array[++stackTop] = item;
			}
		}
	}

	bool isEmpty()
	{
		if (stackTop == -1)
			return 1;
		else
			return 0;
	}

	T pop() // remove top element from the stack
	{
		if (stackTop > 0)
		{
			T temp = array[stackTop];
			array[stackTop] = 0;
			stackTop--;
			return temp;
		}
		else if (stackTop == 0)
			stackTop == -1;
	}

	bool isFull()
	{
		if (stackTop == stackSize - 1)
			return 1;
		else
			return 0;
	}

	T showTop() // displays the top element of the stack, if empty returns -1
	{
		if (stackTop != -1)
			return array[stackTop];
		else
			return -1;
	}

	void showStack()
	{
		for (int i = 0; i < stackSize; i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;
	}
};

//use linked list base implementation 
template <class T>
struct Queue
{
	QueueNode<T>* front;
	QueueNode<T>* rear;

	// functions

	Queue()
	{
		front = NULL;
		rear = NULL;
	}

	~Queue()
	{
		clearQueue();
	}

	void enQueue(T dataItem) // adds element at the end
	{
		if (isEmpty()) // for very first entry
		{
			front = new QueueNode<T>(); // new item created

			front->value = dataItem;
			front->next = NULL;

			rear = front; // only one item so front and rear both point to it
		}
		else
		{
			rear->next = new QueueNode<T>();

			rear->next->value = dataItem;
			rear->next->next = NULL;

			rear = rear->next;
		}
	}

	T deQueue() // removes front element
	{
		T temp11 = 0;
		if (!isEmpty())
		{
			QueueNode<T>* temp = front->next; // saving next value

			temp11 = front->value;
			delete front; // deleting data of front item

			front = temp; // updating front with new front
		}

		return temp11;
	}

	T showFront()
	{
		if (!isEmpty())
		{
			return front->value;
		}
		else
			return NULL;
	}

	bool isEmpty()
	{
		if (front == NULL || rear == NULL)
			return 1;
		else
			return 0;
	}

	void showQueue() // shows all elements of the queue
	{
		QueueNode<T>* temp = front;

		while (temp != NULL)
		{
			cout << temp->value << " ";
			temp = temp->next;
		}
	}

	void clearQueue() // clears entire queue
	{
		while (!isEmpty())
		{
			deQueue();
		}
		front = NULL;
		rear = NULL;
	}
};

//A linked list of Variables can be use for finding the variable and associated value 
template <typename T>
struct Variables {
	T value;
	string Name;
	Variables<T>* next;

};

template <class T>
class VariablesLL
{
public:
	Variables<T>* vHead;
	Variables<T>* vCurrent;

	VariablesLL()
	{
		vHead = NULL;
		vCurrent = NULL;
	}

	void insert(string dataItem)
	{
		Variables<T>* temp = vHead;
		if (vHead == NULL)
		{
			temp = new Variables<T>;

			temp->value = dataItem;

			temp->next = NULL;

			vCurrent = temp;
			vHead = temp;
		}
		else if (vHead != NULL)
		{
			while (1)
			{
				if (temp->next == NULL)
				{
					temp->next = new Variables<T>;

					temp = temp->next;

					temp->data = dataItem;

					temp->next = NULL;
					break;
				}
				temp = temp->next;
			}
		}
	}

	void print()
	{
		Variables<T>* temp = vHead;
		while (1)
		{
			if (temp == NULL)
				break;

			cout << temp->data << " ";

			temp = temp->next;
		}
		cout << endl;
	}

	bool isEmpty()
	{
		if (vHead == NULL)
			return 1;
		else
			return 0;
	}

};

template<typename T>
struct ListNode {
	T data;
	ListNode* next;

};

template<typename T>
class LinkedList {

public:

	ListNode<T>* head;
	ListNode<T>* current;
	int listSize;

	LinkedList()
	{
		head = NULL;
		listSize = 0;
	}

	void insert(T dataItem)
	{
		ListNode<T>* temp = head;
		if (head == NULL)
		{
			temp = new ListNode<T>;
			temp->data = dataItem;
			temp->next = NULL;
			current = temp;
			head = temp;
		}
		else if (head != NULL)
		{
			while (1)
			{
				if (temp->next == NULL)
				{
					temp->next = new ListNode<T>;
					temp = temp->next;
					temp->data = dataItem;
					temp->next = NULL;
					break;
				}
				temp = temp->next;
			}
		}
	}

	void print()
	{
		ListNode<T>* temp = head;
		while (1)
		{
			if (temp == NULL)
				break;

			cout << temp->data << " ";

			temp = temp->next;
		}
		cout << endl;
	}

	bool isEmpty()
	{
		if (head == NULL)
			return 1;
		else
			return 0;
	}

	T returnAtIndex(int index)
	{
		int i = 0;
		ListNode<T>* temp = head;

		T returnData;
		while (1)
		{
			if (temp == NULL)
				break;

			//cout << temp->data << " ";
			if (i == index)
			{
				returnData = temp->data;
				return returnData;
			}

			temp = temp->next;
			i++;
		}
		return NULL;
	}
};

template <class T>
class SpecialStack {
public:
	Queue<T> queue1;
	Queue<T> queue2;

	SpecialStack()
	{}

	void pushToSS(T data) // inserting an item into the special stack
	{
		// to add an item into SS
		// first move all items from 1st Q to 2nd Q
		// then enqueue item into 1st Q
		// then move all items from 2nd Q to 1st Q

		if (queue1.isEmpty()) // returns true if it is empty, and simply adds the item
		{
			queue1.enQueue(data);
		}
		else
		{
			while (1) // moving all items from 1st to 2nd Q
			{
				if (queue1.isEmpty())
					break;

				queue2.clearQueue(); // clearing queue 2

				T temp = queue1.deQueue(); // stores dequeued value into temp

				queue2.enQueue(temp); // enqueues value dequeued into 2nd Q
			}

			queue1.clearQueue(); // just incase clearing 1st Q
			queue1.enQueue(data); // adding data into queue at front

			while (1) // moving all items from 2nd to 1st Q
			{
				if (queue2.isEmpty())
					break;

				T temp = queue2.deQueue(); // stores dequeued value into temp

				queue1.enQueue(temp); // enqueues value dequeued into 1nd Q
			}
		}
	}

	T popFromSS()
	{
		// simply pop front item from 1st Q

		return queue1.deQueue();
	}

	T topItem() // returns front item of 1st Q
	{
		return queue1.showFront();
	}

	void displaySS()
	{
		queue1.showQueue();
	}
};

// Simply just read the file
// Use '\n' to sperate each line of code
string readFile(string a = "Files/code.txt") {
	ifstream infile(a);

	string str = "";
	string temp;

	while (!infile.eof())
	{
		getline(infile, temp);
		str += temp;

		//if (!infile.eof())
		str += "\n";

	}
	return str;
}

// Remove useless lines so line addressing is done properly
string removeLines(string str)
{
	string temp = "";

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '\n') // if new line is found
		{
			int j = i + 1;
			while (1)
			{
				if (str[j] == '\n')
				{
					i = j - 1; // start concatinating from where new line ends
					break;
				}
				else if (str[j] != ' ')
				{
					// incase there is no new line
					temp += str[i];
					break;
				}

				j++;
			}
		}
		else
		{
			temp += str[i]; // concatination
		}
	}

	return temp;
}

// Use this for checking indentations (function, loops, if conditions, etc.)
string checkIndentationErrors(string str)
{
	Stack<char> stkObj(20);

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(' || str[i] == '{')
		{
			stkObj.push(str[i]);
		}

		if (str[i] == ')' && stkObj.showTop() == '(')
		{
			stkObj.pop();
		}
		else if (str[i] == '}' && stkObj.showTop() == '{')
		{
			stkObj.pop();
		}

	}

	cout << stkObj.isEmpty() << endl;

	if (stkObj.isEmpty() == 0)
	{
		return "Indentation error detected";
	}
	else
	{
		return "No error detected";
	}

}

int checkSubString(string str, string substr)
{
	if (str.length() < substr.length())
		return 0;
	//cout << "inside\n";
	for (int i = 0; i < str.length(); i++)
	{
		//cout << "54\n";
		if (str[i] == substr[0]) // first character matches
		{
			for (int j = 0; j < substr.length(); j++) // check if full string matches
			{
				//cout << "87\n";
				if (str[i + j] != substr[j])
					return 0;
			}
			return i; // returns starting address of that substring in str
		}
	}
	//cout << "ending string sub\n";
	return 0;
}

// Check if the function calls itself indefinitely
string checkInfiniteLoop(string code)
{
	// one way is to check if there is recusrion and no if statment in code

	// for each space, check for (), should handle parameters 
	// this is then considered as a function
	// inside that function if we have a call on that function and no conditions
	// it is an infinite loop

	// do regular function calling and see how much it fills the stack
	// if it has a value higher than 1000 it means it is an infinite loop

	/*  check for function name
		check if that function is being called inside that function
		check if there is an if condition in that function
	*/

	string functionName = "";
	string functionCode = "";

	int i = 0;
	if (code[0] == 'C')
		i = 4;

	for (; i < code.length(); i++)
	{
		if (code[i] == ' ')
			continue;
		else
		{
			//cout << "1\n";
			if (functionName == "")
			{
				for (int j = i; j < code.length(); j++) // to find function name
				{
					//cout << "2\n";
					if (code[j] == '(')// means function name is finished
					{
						i = j;
						break;
					}
					else
						functionName += code[j]; // writing function name to variable
				}
			}
			else
			{
				//cout << "3\n";
				if (code[i] == '{')
				{
					for (int j = i; i < code.length(); j++) // when it breaks from this it'll copy full code of that function onto the functionCode string
					{
						//cout << "4\n";
						if (code[j] == '}')
							break;
						functionCode += code[j];
					}
					//cout << "99\n";


					string tempStr = "";

					int m = 0;

					if (functionName[0] == 'i')
						m = 4;
					else if (functionName[0] == 'f')
						m = 5;

					for (int n = 0; m < functionName.length(); m++)
					{
						tempStr += functionName[m];
					}

					//cout << endl << functionCode << endl;
					//cout << endl<< functionName << endl;
					//cout << endl<< tempStr << endl;

					if (checkSubString(functionCode, tempStr) && !(checkSubString(functionCode, "if")))
					{
						//cout << "5\n";
						// means the function is being called recusively and there is no break condition
						return "Infinite loop detected";
						//int temp = checkSubString(functionCode, "print");


						// there's actually no need for the following code lol
						/*if(temp != 0) // if there is a print command inside the function, it copies it onto the output function
						{
							string output = "";
							int i = temp;
							while(1)
							{
								if(functionCode[i] == '"')
								{
									i++; // to not include the "
									for(;i<functionCode.length();i++)
									{
										if(functionCode[i] == '"') // to make sure the " is not included in the string
										{
											break;
										}
										output += functionCode[i]; // copying output into this vairbale
									}
									break;
								}
							}
							i++;
						}*/
					}
					break;

				}

			}
		}
	}
}

// This prepends a line address to every single line in program
string prependLineAddress(string code)
{
	int i = 100;
	string line = "C" + to_string(i) + "    ";

	string temp = "";

	for (int j = 0; j < code.length(); j++)
	{
		if (j == 0)
		{
			temp = line + code[i];
			i++;
			line = "C" + to_string(i) + "    ";

			continue;
		}
		if (code[j + 1] == '\0')
		{
			temp += '\n';
			break;
		}
		else if (code[j] == '\n') // adding a line
		{
			temp += code[j];
			temp += line;
			i++;
			line = "C" + to_string(i) + "    ";
		}
		else
		{
			temp += code[j];
		}
	}
	temp[8] = code[0];
	return temp;
}

void CreateRunTimeStack(string filename, string outputFile) {
	return;
}

// Start execution from the main function and use outputFile to print the output
// Must use CreateRunTimeStack() for execution of the code
void ExecuteCode(string filename, string outputFile) {

}

int prcdType(char a)
{
	int val = -1;

	switch (a)
	{
	case '+':
	case '-':
		val = 1;
		break;
	case '*':
	case '/':
	case '%':
		val = 2;
		break;
	case '$':
	case '^':
		val = 3;
		break;
	}

	return val;
}

bool checkPrcd(char a, char b)
{
	// For Braces
	if (b == '(')
		return 0;

	if (a == '(')
		return 0;

	//if( prcdType(a)<3 && b == '/')
		//return true;

	if (prcdType(a) == prcdType(b) && a != '$')
		return true;

	// These Conditions are for the Operators of Equal precedence
	if (prcdType(a) == prcdType(b) && a == '$')
		return false;

	if (prcdType(a) > prcdType(b))
		return true;

	if (prcdType(a) < prcdType(b))
		return false;



}



string infixToPostfix(string str)
{
	string postfixStr = "";

	SpecialStack<char> operatorStack;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
			continue;

		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
		{
			postfixStr += str[i];
		}
		else
		{
			while (!operatorStack.queue1.isEmpty() && checkPrcd(operatorStack.topItem(), str[i]))
			{
				char topSym = operatorStack.popFromSS();
				postfixStr += topSym;
			}
			if (str[i] == ')')
				operatorStack.popFromSS();
			else
				operatorStack.pushToSS(str[i]);
		}
	}

	while (!operatorStack.queue1.isEmpty())
		postfixStr += operatorStack.popFromSS();

	return postfixStr;
}

int solveMath(int x, int y, char op)
{
	// doesnt deal with %, $, ^
	switch (op)
	{
	case '+':
		return (x + y);
		break;
	case '-':
		return (x - y);
		break;
	case '/':
		return (x / y);
		break;
	case '*':
		return (x * y);
		break;
	default:
		break;
	}
}

template<typename T>
T Solving_PostfixExpression(string expression, LinkedList<T> values)
{
	Stack<int> oprandStk;
	int k = 0;

	for (int i = 0; i < expression.length(); i++)
	{
		char sym = expression[i];

		if (sym >= 'a' && sym <= 'z' || sym >= 'A' && sym <= 'Z')
		{

			oprandStk.push(values.returnAtIndex(k)); // pushes value of oprand into stack
			//cout << sym << " : " << values.returnAtIndex(k) << endl;
			k++;
		}
		else
		{
			//oprandStk.showStack();

			int opd1 = oprandStk.pop();
			//cout << "OPD1 : " << opd1 << endl;
			int opd2 = oprandStk.pop();
			//cout << "OPD2 : " << opd2 << endl;

			if (i == expression.length() - 1)
			{
				opd2 = values.returnAtIndex(0);
			}

			int res = solveMath(opd2, opd1, sym);

			//cout << opd2 << " " << sym << " " << opd1 << " = " << res << endl;

			oprandStk.push(res);
		}

	}

	return oprandStk.pop();
}


// Code should be templatized
template <class T>
class RuntimeNode
{
public:
	//int/datatype data;
	RuntimeNode* nodeAddress; 	//same will be stored in ESP and EBP
								//You may modify the above line
	RuntimeNode* next;
	VariablesLL<T> variablesList; // this will store values and and it's names
	string functionName; // saves the function name of the function this stack is of
	string returnAddress; // stores C1XX, the address of the line it has to return back to

	RuntimeNode()
	{}

	void insertRuntimeNode(string str)
	{
		for (int i = 0; i < 4; i++)
		{
			returnAddress[i] = str[i]; // copies C1XX
		}

		for (int i = 4; str[i + 1] != ';'; i++) // will start from where address ends and search till it gets a column, doesn't include the ';'
		{
			if (str[i] == ' ')
				continue;
			else if (str[i] == '(') // start of parameters
			{
				if (str[i + 1] == ')') // means there r no parameters
				{
					variablesList = NULL;
				}
				else // i'll do this later when it comes to that
				{
					/*i++; // to see data type of parameter

					if(str[i] == 'i') // int type variable
					{
						variablesList->insert()
					}*/
				}
			}
			else {
				functionName = str[i];
			}
		}
	}
};

template <class T>
class RunTimeStack
{
	RuntimeNode<T>* EBP;
	RuntimeNode<T>* ESP; // just like top pointer

};