#pragma once
#include<iostream>
using namespace std;
template<class T>class clsDblLinkedList
{
public:
	class Node
	{
	public:
		T data;
		Node* next=nullptr;
		Node* prev=nullptr;
	};
private:
	Node* head = nullptr;
	void swap(T&i,T&j)
	{
		T temp = i;
		i = j;
		j = temp;
	}
protected:
	int length = 0;
public:
	void clear()
	{
		while (length>0)
		{
			deleteFirstNode();
		}
	}
	bool isEmpty()
	{
		return length==0;
	}
	int size()
	{
		return length;
	}
	void swap(Node* head)
	{
		Node* temp = head->next;
		head->next = head->prev;
		head->prev = temp;
	}
	Node* getNode(int index)
	{
		if (isEmpty())
		{
			cout << "the list is empty\n";
			return nullptr;
		}
		if (index >= size()||index<0)
		{
			cout << "the index exceeds the size or index is less than zero\n";
			return nullptr;
		}
		Node* temp = head;
		int counter = 0;
		while (temp != NULL)
		{
			if (counter == index)
			{
				return temp;
			}
			temp = temp->next;
			counter++;
		}
		return temp;
	}
    T getItem(int index)
	{
		Node* node = getNode(index);
		if (node == NULL)
		{
			return T{};
		}
		return node->data;
	}
	bool updateItem(int index,T item)
	{
		Node* node = getNode(index);
		if (node == NULL)
		{
			return false;
		}
		node->data = item;
		return true;
	}
	void reverse()
	{
		if (isEmpty())
		{
			cout << "the list is empty";
			return;
		}
		if (head->next == NULL)
		{
			cout << "the list has only one element\n";
			return;
		}
		Node* current = head;
		Node* temp = nullptr;
		while (current != nullptr)
		{
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;
			current = current->prev;
		}
		if(temp!=nullptr)
		head = temp->prev;
	}
	void insertAtBeginning(T value)
	{
		Node* newNode = nullptr;
		newNode = new Node();
		newNode->next = head;
		newNode->data = value;
		newNode->prev = nullptr;
		if (head != nullptr)
		{
			head->prev = newNode;
		}
		head = newNode;
		length++;
	}
	void printList()
	{
		if (head == NULL)
		{
			cout << "the list is empty\n";
			return;
		}
		Node* start = head;
		while (start != nullptr)
		{
			cout << start->data << " ";
			start = start->next;
		}
		cout << endl;
	}
	Node* find(T x)
	{
		Node* start = head;
		while (start != nullptr)
		{
			if (start->data == x)
			{
				return start;
			}
			start = start->next;
		}
		return nullptr;
	}
	void insertAfter(Node* current, T newValue)
	{
		if (current == nullptr)
		{
			return;
		}
		Node* newNode = new Node();
		newNode->data = newValue;
		newNode->next = current->next;
		newNode->prev = current;
		if (current->next != nullptr)
		{
			current->next->prev = newNode;
		}
		current->next = newNode;
		length++;
	}
	bool insertAfter(int index, T newValue)
	{
		//Node* newNode = new Node();
		//newNode->data = newValue;
		Node* temp = getNode(index);
	/*	newNode->next = temp->next;
		newNode->prev = temp;
		temp->next->prev = newNode;
		temp->next = newNode;*/
		if (temp != nullptr)
		{
			insertAfter(temp, newValue);
			return true;
		}
		return false;
	}
	void insertAtEnd(T newValue)
	{
		if (head == NULL)
		{
			insertAtBeginning(newValue);
			return;
		}
		Node*lastNode = head;
		while (lastNode->next != nullptr)
		{
			lastNode = lastNode->next;
		}
		Node* newNode = new Node();
		newNode->data = newValue;
		lastNode->next = newNode;
		newNode->next = nullptr;
		newNode->prev = lastNode;
		length++;
	}
	void deleteNode(Node*&nodeToDelete)
	{
		if (head == nullptr || nodeToDelete == nullptr)
		{
			cout << "the list is empty\n";
			return;
		}
		if (head == nodeToDelete)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
			length--;
			return;
		}
		if (nodeToDelete->next != NULL)
		{
			nodeToDelete->next->prev = nodeToDelete->prev;
		}
		if (nodeToDelete->prev != NULL)
		{
			nodeToDelete->prev->next = nodeToDelete->next;
		}
		delete nodeToDelete;
		length--;
	}

	void deleteFirstNode()
	{
		if (head == nullptr)
		{
			cout << "the list is empty";
			return;
		}
		/*if (Head->next == nullptr)
		{
			delete Head;
			Head = nullptr;
		}
		else
		{
			Node<int>* ptr = Head;
			Head->next->prev = nullptr;
			Head = Head->next;
			ptr->next = nullptr;
			delete ptr;
		}*/
		Node* temp = head;
		head = head->next;
		if (head != NULL)
		{
			head->prev = NULL;
		}
		delete temp;
		length--;
	}
	void deleteLastNode()
	{
		if (head == nullptr)
		{
			cout << "the list is empty";
			return;
		}
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			Node* currentNode = head;
			while (currentNode->next->next != nullptr)
			{
				currentNode = currentNode->next;
			}
			Node* temp = currentNode->next;
			currentNode->next = NULL;
			delete temp;
		}
		length--;
	}
};

