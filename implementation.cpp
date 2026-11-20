#include<iostream>
#include"clsDblLinkedList.h"
#include "clsMyQueue.h"
#include "clsMyStack.h"
#include"clsDynamicArray.h"
#include"clsMyQueueArr.h"
#include"clsMyStackArr.h"
#include"clsMyString.h"
#include "clsMyQueue.h"
#include "clsQueueLine.h"
using namespace std;
int main()
{
	//clsDblLinkedList<int>myDblLinkedList;
	//myDblLinkedList.insertAtBeginning(5);
	//myDblLinkedList.insertAtBeginning(4);
	//myDblLinkedList.insertAtBeginning(3);
	//myDblLinkedList.insertAtBeginning(2);
	//myDblLinkedList.insertAtBeginning(1);
	//clsDblLinkedList<int>::Node* n1 = myDblLinkedList.getNode(2);
	//cout << "my linked list content\n";
	//myDblLinkedList.printList();
	//cout << "the size of linked list is " << myDblLinkedList.size() << endl;
	//clsDblLinkedList<int>::Node*n1= myDblLinkedList.find(2);
	//if (n1 != NULL)
	//	cout << "the node is found\n";
	//else
	//	cout << "the node is not found\n";
	//myDblLinkedList.insertAfter(n1, 500);
	//cout << "After inserting in linked list\n";
	//myDblLinkedList.printList();
	//cout << "the size of linked list is " << myDblLinkedList.size() << endl;
	//cout << "After inserting in linked list\n";
	//myDblLinkedList.insertAtEnd(700);
	//myDblLinkedList.printList();
	//cout << "the size of linked list is " << myDblLinkedList.size() << endl;
	//clsDblLinkedList<int>::Node* n2 = myDblLinkedList.find(4);
	//cout << "after deleting n2:\n";
	//myDblLinkedList.deleteNode(n2);
	//myDblLinkedList.printList();
	//cout << "the size of linked list is " << myDblLinkedList.size() << endl;
	//cout << "after deleting first node\n";
	//myDblLinkedList.deleteFirstNode();
	//myDblLinkedList.printList();
	//cout << "the size of linked list is " << myDblLinkedList.size() << endl;
	//cout << "after deleting last Node\n";
	//myDblLinkedList.deleteLastNode();
	//myDblLinkedList.printList();
	//cout<<"the size of linked list is " << myDblLinkedList.size()<<endl;
	//myDblLinkedList.reverse();
	//cout << "my linked list content after reverse\n";
	//myDblLinkedList.printList();
	//myDblLinkedList.insertAfter(3, 500);
	//myDblLinkedList.printList();
	//clsMyStack<int>myStack;
	//myStack.push(10);
	//myStack.push(20);
	//myStack.push(30);
	//myStack.push(40);
	//myStack.push(50);
	//cout << "Stack\n";
	//myStack.print();
	//cout << "Stack size: " << myStack.size()<<"\n";
	//cout << "Stack top:" << myStack.Top() << "\n";
	//cout << "Stack bottom:" << myStack.bottom() << "\n";
	//myStack.pop();
	//cout << "Stack after pop\n";
	//myStack.print();
	//cout << "item :" << myStack.getItem(2)<<"\n";
	//myStack.reverse();
	//cout << "Stack after reverse\n";
	//myStack.print();
	//myStack.updateItem(2, 600);
	//cout << "Stack after updateing item\n";
	//myStack.print();
	//myStack.insertAfter(2, 800);
	//cout << "Stack after inserting 800  :\n";
	//myStack.print();
	//myStack.insertAtFront(1000);
	//cout << "Stack after inserting 1000  :\n";
	//myStack.print();
	//myStack.insertAtBack(2000);
	//cout << "Stack after inserting 2000  :\n";
	//myStack.print();
	//cout << "Stack after clear :\n";
	//myStack.clear();
	//myStack.print();
	//clsDynamicArray<int>myDynamicArray(5);
	//myDynamicArray.setItem(0, 10);
	//myDynamicArray.setItem(1, 20);
	//myDynamicArray.setItem(2, 30);
	//myDynamicArray.setItem(3, 40);
	//myDynamicArray.setItem(4, 50);
	//cout << "is empty?: " << myDynamicArray.isEmpty() << endl;
	//cout << "array size: " << myDynamicArray.size()<< endl;
	//myDynamicArray.printList();
	//myDynamicArray.reSize(2);
	//cout << "Array size:" << myDynamicArray.size() << "\n";
	//cout << "array items after resize\n";
	//myDynamicArray.printList();
	//myDynamicArray.reSize(10);
	//cout << "Array size: " << myDynamicArray.size() << "\n";
	//cout << "array items after resize\n";
	//myDynamicArray.printList();
	//cout << "item :" << myDynamicArray.getItem(2) << endl;
	//myDynamicArray.deleteFirstItem();
	//cout << "Array after delete\n";
	//myDynamicArray.printList();
	//myDynamicArray.deleteLastItem();
	//cout << "Array after delete\n";
	//myDynamicArray.printList();
	//int index = myDynamicArray.find(90);
	//cout << "30 found at " << index<<endl;
	//myDynamicArray.deleteItem(90);
	//myDynamicArray.insertAtBeginning( 400);
	//cout << "array size: " << myDynamicArray.size() << endl;
	//myDynamicArray.printList();
	//myDynamicArray.insertBefore(2,500);
	//cout << "array size: " << myDynamicArray.size() << endl;
	//myDynamicArray.printList();
	//myDynamicArray.insertAfter(2,600);
	//cout << "array size: " << myDynamicArray.size() << endl;
	//myDynamicArray.printList();
	//myDynamicArray.insertAtEnd(800);
	//cout << "array size: " << myDynamicArray.size() << endl;
	//myDynamicArray.printList();
	//clsMyStackArr<int>myQueueArr;
	//myQueueArr.push(10);
	//myQueueArr.push(20);
	//myQueueArr.push(30);
	//myQueueArr.push(40);
	//cout << "queue: ";
	//myQueueArr.print();
	//cout << "queue size : " << myQueueArr.size()<<endl;
	//cout << "queue top : " << myQueueArr.Top() << endl;
	//cout << "queue bottom : " << myQueueArr.bottom()<<endl;
	//myQueueArr.pop();
	//cout << "queue after pop():";
	//myQueueArr.print();
	//cout << "item (2): " << myQueueArr.getItem(2)<<endl;
	//myQueueArr.reverse();
	//cout << "queue after reverse\n";
	//myQueueArr.print();
	//myQueueArr.updateItem(2,600);
	//cout << "queue after update:";
	//myQueueArr.print();
	//myQueueArr.insertAfter(2, 800);
	//cout << "queue after insert:";
	//myQueueArr.print();
	//myQueueArr.insertAtFront( 1000);
	//cout << "queue after insert:";
	//myQueueArr.print();
	//myQueueArr.insertAtBack(2000);
	//cout << "queue after insert:";
	//myQueueArr.print();
	//myQueueArr.clear();
	//myQueueArr.print();
//clsMyString s1;
//cout<<" s1 = "  << s1.valueProperty << endl;
//s1.valueProperty = "Mohammed";
//cout << " s1 = " << s1.valueProperty << endl;
//s1.valueProperty = "Mohammed2";
//cout << " s1 = " << s1.valueProperty << endl;
//s1.valueProperty = "Mohammed3";
//cout << " s1 = " << s1.valueProperty<< endl;
//cout << "undo\n";
//cout << "-----\n";
//s1.undo();
//cout << " after undo " << s1.valueProperty << "\n";
//s1.undo();
//cout << " after undo " << s1.valueProperty << "\n";
//s1.undo();
//cout << " after undo " << s1.valueProperty << "\n";
//cout << "redo\n";
//cout << "-----\n";
//s1.redo();
//cout << " after redo " << s1.valueProperty << "\n";
//s1.redo();
//cout << " after redo " << s1.valueProperty << "\n";
//s1.redo();
//cout << " after redo " << s1.valueProperty << "\n";
//clsMyString s2;
//cout << " s2 = " << s2.valueProperty << endl;
//s2.valueProperty = "Mohammed";
//cout << " s2 = " << s2.valueProperty << endl;
//s2.valueProperty = "Mohammed2";
//cout << " s2 = " << s2.valueProperty << endl;
//s2.valueProperty = "Mohammed3";
//cout << " s2 = " << s2.valueProperty << endl;
//cout << "undo\n";
//cout << "-----\n";
//s2.undo();
//cout << " after undo " << s2.valueProperty << "\n";
//s2.undo();
//cout << " after undo " << s2.valueProperty << "\n";
//s2.undo();
//cout << " after undo " << s2.valueProperty << "\n";
//cout << "redo\n";
//cout << "-----\n";
//s2.redo();
//cout << " after redo " << s2.valueProperty << "\n";
//s2.redo();
//cout << " after redo " << s2.valueProperty << "\n";
//s2.redo();
//cout << " after redo " << s2.valueProperty << "\n";
//
//clsMyString str("A");
//
//str.valueProperty = "B";
//str.valueProperty = "C";
//
//// ÊÑÇÌÚ ãÑÊíä
//str.undo();
//str.undo();
//
//cout << "Current Value: " << str.getValue() << endl;
//
//// ÊÚÏíá ÌÏíÏ ÈÚÏ ÇáÊÑÇÌÚ
//str.valueProperty = "D";
//
//// äÌÑÈ Redo
//str.redo();
//
//cout << "After Redo: " << str.getValue() << endl;
	clsQueueLine PayBillsQueue("A0", 10);
	clsQueueLine subscriptionsQueue("B0", 5);
	PayBillsQueue.issueTicket();
	PayBillsQueue.issueTicket();
	PayBillsQueue.issueTicket();
	PayBillsQueue.issueTicket();
	PayBillsQueue.issueTicket();
	cout << "pay Bills queue info:\n";
	PayBillsQueue.printInfo();
	PayBillsQueue.printTicketsLineRTL();
	PayBillsQueue.printTicketsLineLTR();
	PayBillsQueue.printAllTickets();
	PayBillsQueue.serveNextClient();
	PayBillsQueue.issueTicket();
	PayBillsQueue.printAllTickets();

	cout << "paybills after serving one client\n";
	PayBillsQueue.printInfo();
	cout << "subscripation queue info\n";
	subscriptionsQueue.issueTicket();
	subscriptionsQueue.issueTicket();
	subscriptionsQueue.issueTicket();
	subscriptionsQueue.printInfo();
	subscriptionsQueue.printTicketsLineLTR();
	subscriptionsQueue.printTicketsLineRTL();
	subscriptionsQueue.printAllTickets();
	subscriptionsQueue.serveNextClient();
	subscriptionsQueue.printInfo();
	subscriptionsQueue.printAllTickets();
}