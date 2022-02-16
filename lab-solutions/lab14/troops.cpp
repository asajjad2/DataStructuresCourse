#include <cstdlib>
#include <iostream>
#include <queue>
#include <string>
#include <ctime>
#include <Windows.h>

using namespace std;

class Message
{
public:
	string msg;
	int from;
	int to;

	Message()
	{
		msg = "";
		from = -1;
		to = -1;
	}

	Message(string m, int x, int y)
	{
		msg = m;
		from = x;
		to = y;
	}

	string displayMsg()
	{
		string temp = msg;
		temp += " sent FROM ";
		temp += to_string(from);
		temp += " TO ";
		temp += to_string(to);

		return temp;
	}
};

struct Person
{
	int id;
	int rank; // rank 1 for general and 2 for captian

	Person()
	{
		id = -1;
		rank = -1;
	}
};


template <class T>
class Troops
{

public:
	string name;
	Person* troops;


	queue<T> incomingMsgs;
	queue<T> outgoingMsgs;

	Troops(int t)
	{
		if (t == 0)
			name = "West";
		else if (t == 1)
			name = "East";

		troops = new Person[4];

		troops[0].id = 10;
		troops[0].rank = 1;

		for (int i = 1; i < 4; i++)
		{
			troops[i].id = rand() % 9;

			for (int j = 1; j < 4; j++)
			{
				if (troops[i].id == troops[j].id && i != j)
				{
					troops[i].id = rand() % 9;
					j = 1;
				}
			}

			troops[i].rank = 2;
		}
	}

	void sendMsg(string temp, int t1, int t2) // t1 is sending, t2 is reciver
	{
		Message tempMsg(temp, t1, t2);

		outgoingMsgs.push(tempMsg);

		ManageMsgs(*this);
	}

	void showIncomingMsg()
	{
		Message tempMsg = incomingMsgs.front();

		cout << tempMsg.displayMsg() << endl;
	}

	bool operator == (Troops const& obj)
	{
		if (obj.name == name)
			return 1;
		else
			return 0;
	}
};

Troops<Message> East(1);
Troops<Message> West(0);

template <typename T>
void ManageMsgs(Troops<T> sendingTroop)
{
	while (!East.incomingMsgs.empty())
	{
		East.incomingMsgs.pop();
	}
	while (!West.incomingMsgs.empty())
	{
		West.incomingMsgs.pop();
	}

	if (sendingTroop == East)
	{
		Message tempMsg = sendingTroop.outgoingMsgs.front();
		sendingTroop.outgoingMsgs.pop();

	

		West.incomingMsgs.push(tempMsg);
		West.showIncomingMsg();
		
		Sleep(3000); // pause for 1 second
	}

	if (sendingTroop == West)
	{
		Message tempMsg = sendingTroop.outgoingMsgs.front();
		sendingTroop.outgoingMsgs.pop();

		Sleep(3000); // pause for 1 second

		East.incomingMsgs.push(tempMsg);
		East.showIncomingMsg();
	}
}



int main()
{
	East.sendMsg("Attack", 3, 6);

	West.sendMsg("Retreat", 1, 2);


	return 0;
}
