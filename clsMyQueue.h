#pragma once
#include<iostream>
#include"clsDblLinkedList.h"
using namespace std;
template<class T>class clsMyQueue
{
protected:
	clsDblLinkedList<T>myDblLinkedList;
public:
	void push(T item)
	{
		myDblLinkedList.insertAtEnd(item);
	}
	T front()
	{
		return myDblLinkedList.getItem(0);
	}
	T back()
	{
		return myDblLinkedList.getItem(size()-1);
	}
	T getItem(int index)
	{
		return myDblLinkedList.getItem(index);
	}
	void reverse()
	{
		myDblLinkedList.reverse();
	}
	bool updateItem(int index, T item)
	{
		return myDblLinkedList.updateItem(index, item);
	}
	bool insertAfter(int index, T newValue)
	{
		return myDblLinkedList.insertAfter(index, newValue);
	}
	void insertAtFront(T newValue)
	{
		myDblLinkedList.insertAtBeginning(newValue);
	}
	void insertAtBack(T newValue)
	{
		myDblLinkedList.insertAtEnd(newValue);
	}
	void clear()
	{
		myDblLinkedList.clear();
	}
	void pop()
	{
		myDblLinkedList.deleteFirstNode();
	}
	void print()
	{
		myDblLinkedList.printList();
	}
	int size()
	{
		return myDblLinkedList.size();
	}
	bool isEmpty()
	{
		return myDblLinkedList.isEmpty();
	}
};

