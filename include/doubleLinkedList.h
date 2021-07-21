#pragma once
#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

/*! \class Double Linked List
	\brief A double linked list data structure using smart pointers
*/

#include <string>
#include <memory>

using namespace std;

class doubleLinkedlist
{
	private:
	struct node {
		int data; //!< the data thats held in the list
		node* next;//!< Next element on the list
		
		node* previous;//!< previous element on the list
		node(int v_) : data(v_), next(NULL), previous(NULL) {}; //!<constructor
	};
	node* head; //!< creates head pointer for the list
	node* tail; //!< creates tail pointer for the list

	public:
	doubleLinkedlist()
	{
		head = NULL; // no data in the list so head is null
		tail = NULL; // no data in the list so tail is null
	}
	


	void printFromHead() //!< Prints the list out starting from the Front
	{
		cout << "		 Double Linked list \n";
		node* temp = head;
		cout << "=======================================================";
		cout << "\n";
		cout << "                [";
		while (temp)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << "]" << endl;
		cout << "=======================================================";
		cout << "\n";
	}

	void printFromTail()//!< Prints the list out starting from the back
	{
		node* temp = tail;
		cout << "======================================================="; 
		cout << "\n";
		cout << "                [";
		
		while (temp)
		{
			cout << temp->data << " ";
			temp = temp->previous;
		}

		cout << "]" << endl;
		cout << "=======================================================";
		cout << "\n";

	};

	void addFromHead(int v_) //<! adds the element at the start of the list
	{
		if (head == NULL && tail == NULL) { // case 1, There is no nodes in the list so it creates a node and sets it as head and tail.
			head = new node(v_);
			tail = head;
		}
		else { // when there is 1 node in the list it then goes to choose from following
			node* current = head; 
			while (current && v_ > current->data) {
				current = current->next;
			}
			if (current == head) { //case 2, The new node is going infront of the existing node and becomes the head node
				current->previous = new node(v_);
				current->previous->next = head;
				head = current->previous;
			}
			else if (current) { // case 3, the new node is in middle of the list. this checks only if there is 2 or more nodes in the list
				current->previous->next = new node(v_);
				current->previous->next->next = current;
				current->previous->next->previous = current->previous;
				current->previous = current->previous->next;
			}
			else if (!current) { // case 4, the new node is put at the end of the list making it the tail.
				tail->next = new node(v_);
				tail->next->previous = tail;
				tail = tail->next;
			}
		}
	}
	void addFromTail(int v_) //!< adds the element from the back of the list
	{
		if (head == NULL && tail == NULL) {   // case 1, There is no nodes in the list so it creates a node and sets it as head and tail.
			head = new node(v_);
			tail = new node(v_);
			head = head;
		}
		else {
			node* current = tail; // when there is 1 node in the list it then goes to choose from following
			while (current && v_ <= current->data) {
				current = current->previous;
			}
			if (current == tail) { // case 2, the new node is put at the end of the list making it the tail.
				current->next = new node(v_);
				current->next->previous = tail;
				tail = current->next;
			}
			else if (current) {  // case 3, the new node is in middle of the list. this checks only if there is 2 or more nodes in the list
				current->next->previous = new node(v_);
				current->next->previous->previous = current;
				current->next->previous->next = current->next;
				current->next = current->next->previous;
			}
			else if (!current) {  // case 4, The new node is going infront of the existing node and becomes the head node
				head->previous = new node(v_);
				head->previous->next = head;
				head = head->previous;
			}
		}
	}
	void deleteNode(node** head, node* deleteNode) //!< deletes the nodes from the list
	{
		if (*head == NULL || deleteNode == NULL) // if there is no nodes in the list it doesnt delete anything
			return;
		else if (*head == deleteNode) // deletes the head node
			*head = deleteNode->next;
		else if (deleteNode->next != NULL) 
			deleteNode->next->previous = deleteNode->previous;
		else if (deleteNode->previous != NULL)
			deleteNode->previous->next = deleteNode->next;

		free(deleteNode);
		return;

	}
};
#endif // !DOUBLELINKEDLIST_H