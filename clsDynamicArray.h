#pragma once
#include<iostream>
using namespace std;
template <class T>class clsDynamicArray
{
private:
	int _size=0;
	T* tempArr = NULL;
protected:
	T * originalArr=NULL;
public:
	~clsDynamicArray()
	{
		delete[]originalArr;
		originalArr = nullptr;
	}
	clsDynamicArray(int size=0)
	{
		if (size < 0)
		{
			size = 0;
		}
		this->_size = size;
		originalArr = new T[_size];
	}
	bool setItem(int index, T value)
	{
		if (index >= size()||index<0)
		{
			return false;
		}
		*(originalArr + index) = value;
		return true;
	}
	bool isEmpty()
	{
		return _size == 0;
	}
	int size()
	{
		return _size;
	}
	void printList()
	{
		if (_size == 0)
		{
			cout << "the size is empty\n";
			return;
		}
		for (int i = 0; i < _size; i++)
		{
			cout << *(originalArr + i) << " ";
		}
		cout <<"\n";
	}
	void reSize(int size)
	{
		if (size < 0)
		{
			size = 0;
		}
		tempArr = new T[size];
		if (size < _size)
		{
			_size = size;
		}
		for (int i = 0; i<_size; i++)
		{
			tempArr[i] = originalArr[i];
		}
		_size = size;
		delete[]originalArr;
		originalArr=tempArr;
	}
	T getItem(int index)
	{
		if (index >= size() || index < 0)
		{
			return T();
		}
		return originalArr[index];
	}
	void clear()
	{
		_size = 0;
		delete[]originalArr;
		originalArr = new T[_size];
	}
	void reverse()
	{
		tempArr = new T[_size];
		if (size() <= 1)
		{
			return;
		}
		int counter = 0;
		for (int i = _size-1; i >=0 ; i--)
		{
			tempArr[counter++] = originalArr[i];
		}
		delete[]originalArr;
		originalArr = tempArr;
	}
	bool deleteItemAt(int index)
	{
		if (index >= size() || index < 0)
		{
			return false;
		}
	/*	for (int i = index; i < _size-1; i++)
		{
			originalArr[i] = originalArr[i + 1];
		}*/
		_size--;
		tempArr = new T[_size];
		for (int i = 0; i < index; i++)
		{
			tempArr[i] = originalArr[i];
		}
		for (int i = index + 1; i < _size + 1; i++)
		{
			tempArr[i - 1] = originalArr[i];
		}
		delete[]originalArr;
		originalArr = tempArr;
		return true;
	}
	bool deleteFirstItem()
	{
		return deleteItemAt(0);
	}
	bool deleteLastItem()
	{
		return deleteItemAt(_size - 1);
	}
	int find(T value)
	{
		for (int i = 0; i < _size; i++)
		{
			if (originalArr[i] == value)
			{
				return i;
			}
		}
		return -1;
	}
	bool deleteItem(T value)
	{
		int index = find(value);
		if (index == -1)
		{
			return false;
		}
		deleteItemAt(index);
		return true;
	}
	bool insertAt(int index, T value)
	{
		if (index>size()||index<0)
		{
			return false;
		}
		_size++;
		tempArr = new T[_size];
		for (int i = 0; i < index; i++)
		{
			tempArr[i] = originalArr[i];
		}
		tempArr[index] = value;
		for (int i = index; i < _size-1; i++)
		{
			tempArr[i+1] = originalArr[i];
		}
		delete[]originalArr;
		originalArr = tempArr;
		return true;
	}
	void insertAtBeginning(T value)
	{
		insertAt(0, value);
	}
	bool insertBefore(int index, T value)
	{
		if (index < 1)
		{
			return insertAt(0, value);
		}
		return insertAt(index, value);
	}
	bool insertAfter(int index, T value)
	{
		if (index >= _size)
		{
			return insertAt(_size, value);
		}
		return insertAt(index + 1, value);
	}
	bool insertAtEnd(T value)
	{
		return insertAt(_size, value);
	}
};

