#pragma once
#include <iostream>
#include<queue>
#include<stack>
#include"clsDate.h"
using namespace std;
class clsQueueLine
{
private:
	class clsTicket
	{
	private:
		int number;
		string perfix;
		int waitingClients;
		string ticketDate;
		int servingAverageTime;
	public:
		clsTicket(string perfix, int number, int waitingClients, int servingAverageTime)
		{
			this->perfix = perfix;
			this->number = number;
			this->waitingClients = waitingClients;
			ticketDate = clsDate::getSystemDateTimeString();
			this->servingAverageTime = servingAverageTime;
		}
		int getNumber()
		{
			return number;
		}
		string getPerfix()
		{
			return perfix;
		}
		string fullNumber()
		{
			return perfix + to_string(number);
		}
		string getTicketDate()
		{
			return ticketDate;
		}
		int getServingAverageTime()
		{
			return servingAverageTime;
		}
		int getExpectedAverageTime()
		{
			return servingAverageTime * waitingClients;
		}
		int getNumberOfWaitingClients()
		{
			return waitingClients;
		}
		void print()
		{
			cout << "\t\t\t\t\t\t\t--------------------------------------\n";
			cout << "\t\t\t\t\t\t\t\t\t" << fullNumber() << endl;
			cout << "\t\t\t\t\t\t\t\t" << getTicketDate() << endl;
			cout << "\t\t\t\t\t\t\t\twaiting clients = " << getNumberOfWaitingClients() << endl;
			cout << "\t\t\t\t\t\t\t\tserve time in " << getExpectedAverageTime() << " minutes " << endl;
			cout << "\t\t\t\t\t\t\t--------------------------------------\n";
		}
	};
	queue<clsTicket>queueTicket;
	string prefix;
	int servingAverageTime;
	int totalTickets;
public:
	clsQueueLine(string prefix, int servingTime)
	{
		this->prefix = prefix;
		totalTickets = 0;
		if (servingTime > 0)
			this->servingAverageTime = servingTime;
		else
			this->servingAverageTime = 5;
	}
	void issueTicket()
	{
		totalTickets++;
		clsTicket ticket(prefix, totalTickets, waitingClient(), servingAverageTime);
		queueTicket.push(ticket);
	}
	void printInfo()
	{
		cout << "\t\t\t\t\t\t--------------------------------------\n";
		cout << "\t\t\t\t\t\t\t\tqueue info\n";
		cout << "\t\t\t\t\t\t--------------------------------------\n";
		cout << "\t\t\t\t\t\t\t\tprefix =" << prefix << endl;
		cout << "\t\t\t\t\t\t\t\ttotal tickets =" << totalTickets << endl;
		cout << "\t\t\t\t\t\t\t\tserved clients=" << servingClient() << endl;
		cout << "\t\t\t\t\t\t\t\twaiting clients =" << waitingClient() << endl;
		cout << "\t\t\t\t\t\t--------------------------------------\n";
	}
	void printTicketsLineRTL()
	{
		cout << "\t\t\t\t\t\ttickets:";
		queue<clsTicket>tempQueue = queueTicket;
		while (!tempQueue.empty())
		{
			cout << tempQueue.front().fullNumber() <<"<--";
			tempQueue.pop();
		}
		cout << "\n";
	}
	void printTicketsLineLTR()
	{
		cout << "\t\t\t\t\t\ttickets:";
		queue<clsTicket>tempQueue = queueTicket;
		stack<clsTicket>tempStack;
		while (!tempQueue.empty())
		{
			tempStack.push(tempQueue.front());	
			tempQueue.pop();
		}
		while (!tempStack.empty())
		{
			cout << tempStack.top().fullNumber() << "-->";
			tempStack.pop();
		}
		cout << "\n";
	}
	void printAllTickets()
	{
		if (queueTicket.empty())
		{
			cout << "\t\t\t\t\t\t\t\t   ---no tickets---\n";
			return;
		}
		cout << "\t\t\t\t\t\t\t\t   ---tickets---\n";
		queue<clsTicket>tempQueue = queueTicket;
		while (!tempQueue.empty())
		{
			tempQueue.front().print();
			tempQueue.pop();
		}
	}
	int waitingClient()
	{
		return queueTicket.size();
	}
	string whoIsNext()
	{
		if (queueTicket.empty())
		{
			return "";
		}
		return queueTicket.front().fullNumber();
	}
	int servingClient()
	{
		return totalTickets-waitingClient();
	}
	bool serveNextClient()
	{
		if (!queueTicket.empty())
		{
			queueTicket.pop();
			return true;
		}
		else
		{
			return false;
		}
	}
};

