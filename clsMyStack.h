#pragma once
#include<iostream>
#include"clsDblLinkedList.h"
using namespace std;
template<class T>class clsMyStack:public clsMyQueue<T>
{
public:
	void push(T item)
	{
		clsMyQueue<T>::insertAtFront(item);
	}
	T Top()
	{
		return clsMyQueue<T>::front();
	}
	T bottom()
	{
		return  clsMyQueue<T>::back();
	}
};

