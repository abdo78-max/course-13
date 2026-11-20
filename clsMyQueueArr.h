#pragma once
#pragma once
#include<iostream>
#include"clsDynamicArray.h"
using namespace std;
template<class T>class clsMyQueueArr
{
protected:
	clsDynamicArray<T>myDynamicArray;
public:
	void push(T item)
	{
		myDynamicArray.insertAtEnd(item);
	}
	T front()
	{
		return myDynamicArray.getItem(0);
	}
	T back()
	{
		return myDynamicArray.getItem(size() - 1);
	}
	T getItem(int index)
	{
		return myDynamicArray.getItem(index);
	}
	void reverse()
	{
		myDynamicArray.reverse();
	}
	bool updateItem(int index, T item)
	{
		return myDynamicArray.setItem(index, item);
	}
	bool insertAfter(int index, T newValue)
	{
		return myDynamicArray.insertAfter(index, newValue);
	}
	void insertAtFront(T newValue)
	{
		myDynamicArray.insertAtBeginning(newValue);
	}
	void insertAtBack(T newValue)
	{
		myDynamicArray.insertAtEnd(newValue);
	}
	void clear()
	{
		myDynamicArray.clear();
	}
	void pop()
	{
		myDynamicArray.deleteFirstItem();
	}
	void print()
	{
		myDynamicArray.printList();
	}
	int size()
	{
		return myDynamicArray.size();
	}
	bool isEmpty()
	{
		return myDynamicArray.isEmpty();
	}
};

