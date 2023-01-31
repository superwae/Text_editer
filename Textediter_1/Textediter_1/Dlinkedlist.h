#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H
#include "Node.h"
#include<iostream>
using namespace std;
int line = 0;
int line2 = 0;

template <class T>
class dLinkedList
{
public:
	Node<T>* head;
	Node<T>* tail;

	dLinkedList()
	{

	}

	void add(T item) {
		Node<T>* newNode = new Node<T>[1];
		newNode->data = item;
		if (head == NULL) {
			head = newNode;
			tail = newNode;
			newNode->next = NULL;
			newNode->prev = NULL;
		}
		else {
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
			newNode->next = NULL;
		}

		return;
	}
	void displayAll() {
	
	
		Node<T>* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	
	}
	void display() {
		line = 0;
		line2 = 0;
		if (head == NULL) {
			cout << "linked list is empty" << endl;
			return;
		}

		Node<T>* temp = head;
	
		while (temp != NULL) {
			temp->data.displayAll();
			cout << endl;
			temp = temp->next;
		}

	}
	void del(string theword) {
		if (head == NULL) {
			cout << "linked list is empty" << endl;
			return;
		}

		Node<T>* temp = head;
		line = 0;
		line2 = -1;

		while (temp != NULL) {
			temp->data.remove(theword);
			temp = temp->next;
		}

	}

	void remove(T ReMove) {
		int count = 0;
		line2 = line2 + 1;
		Node<T>* temp = head;
		Node<T>* before = head;
		while (temp != NULL) {
			if (head->data == ReMove)
			{
				head->data = "";
				head = head->next;
				//head->prev = NULL;
				//free (temp);
				cout << "word got deleted from line : " << line2 << " postion : " << count + 1 << endl;	
				//delete temp;
			}
			else if  (temp->data == ReMove) {
				before->next = temp->next;
				if (temp->next == NULL)
				{
				}
				else{
				temp->next->prev = before; 
				}
				cout << "word got deleted from line : " << line2 << " postion : " << count + 1 << endl;
				//delete temp;
				temp->next = NULL;
				temp->prev = NULL;
			}
			count++;
			before = temp;
			temp = temp->next;	
		}
	}
	void FInd(string theword) {
		line = -1;
		line2 = 0;
		if (head == NULL) {
			cout << "linked list is empty" << endl;
			return;
		}

		Node<T>* temp = head;

		while (temp != NULL) {
			temp->data.FindWord(theword);
			cout << endl;
			temp = temp->next;
		}

	}
	void FindWord(T Word) {
		int count = 0;
		line ++;
		Node<T>* temp = head;
			while (temp != NULL) {
				if (temp->data == Word) {
					cout << "word found on line : "<<line<<" postion : " << count + 1 << endl;	
				}
				count++;
				temp = temp->next;
			}	
	}
};

#endif 
