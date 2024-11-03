#ifndef HEADER_H
#define HEADER_H
#pragma once

#include <iostream>

/*
Implement a linked list
*/

class Node {
public:
	Node* next;
	int value;

	Node(int value) {
		this->value = value;
		next = nullptr;
	}

};


class LinkedList {
private:
	Node* head;
	Node* tail;
	int length;

	//Constructor
public:
	LinkedList(int value) {
		Node* newNode = new Node(value);
		head = newNode;
		tail = newNode;
		length = 1;
	}


	//Destructor
	~LinkedList() {
		Node *temp = head;
		while (head) {
			head = temp->next;
			delete temp;
			temp = head;
		}

	}

	//printList
	void printList() {
		Node* temp = head;
		while (temp) {
			std::cout << "Node value: "<< temp->value<< "\n";
			temp = temp->next;
		}
	}

	//Get Head

	void getHead() {
		if (head == nullptr) {
			std::cout << "The linked list is empty. " << std::endl;
		}
		else {
			std::cout << "The head is: " << head->value << std::endl;
		}

	}

	//Get Tail
	void getTail() {
		if (head == nullptr) {
		std::cout << "The linked list is empty. " << std::endl;
		}
		else {
			std::cout << "The tail is: " << tail->value << std::endl;
		}
	}

	//Get length

	void getLength() {
		std::cout << "The length is: " << length << std::endl;
	}

	//Get
	Node* get(int index) {
		if(index < 0 || index >=length){
			return nullptr;
		}
		else {
			Node* temp = head;
			for (int i = 0; i < index; i++) {
				temp = temp->next;
			}
			return temp;
		}
	}

	//Append
	void append(int value) {
		Node* newNode = new Node(value);
		if (length == 0) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
		length++;
	}

	//Prepend
	void prePend(int value) {
		Node* newNode = new Node(value);
		if (length == 0) {
			head = newNode;
			tail = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
		length++;
	}

	//Insert
	bool insert(int index, int value) {
		if (index < 0 || index > length) {
			return false;
		}
		if (index == 0) {
			prePend(value);
			return true;
		}
		if (index == length) {
			append(value);
			return true;
		}
		else {
			Node *preNode = get(index - 1);
			Node *newNode = new Node(value);
			newNode->next = preNode->next;
			preNode->next = newNode;
			length++;
			return true;
		}
	}

	//Deletefirst
	void deleteFirst() {
		if (length == 0) {
			return;
		}
		Node* temp = head;
		if (length == 1) {

			head = nullptr;
			tail = nullptr;
		}
		else {
			head = temp->next;
		}
		delete temp;
		length--;
		return;
	}

	//Deletelast
	void deleteLast() {
		if (length == 0) {
			return;
		}
		Node* temp = head;
		if (length == 1) {
			head = nullptr;
			tail = nullptr;
		}
		else {
			Node* pre = head;
			while (temp->next) {
				pre = temp;
				temp = temp->next;
			}
			tail = pre;
			tail->next = nullptr;
		}
		delete temp;
		length--;
	}

	//DeleteNode
	void DeleteNode(int index) {
		if (index < 0 || index >= length) {
			return;
		}
		if (index == 0) {
			
			return deleteFirst();
		}
		if (index == length - 1) {
			
			return deleteLast();
		}

		else {
			Node *pre = get(index - 1);
			Node *temp = pre->next;
			pre->next = temp->next;
			delete temp;
			length--;
			return;
		}
	}

	//Set
	bool set(int index, int value) {
		Node *temp = get(index);
		if (temp) {
			temp->value = value;
			return true;
		}
		return false;
	}

	//Reverse
	void reverse() {
		Node* temp = head;
		head = tail;
		tail = temp;

		Node* after = temp->next;
		Node* before = nullptr;

		for (int i = 0; i < length; ++i) {
			after = temp->next;
			temp->next = before;
			before = temp;
			temp = after;
		}

	}

	/*
    Write code to remove duplicates from an unsorted linked list.
    FOLLOW UP
    How would you solve this problem if a temporary buffer is not allowed.

	Development Notes:
	1: Implemented the deletion of the duplicate node directly in the code.
    */

	void removeDuplicates() {
		Node* first = head;
		if (first == nullptr) {
			return;
		}
		if (first->next == nullptr) {
			return;
		}

		while (first) {

			Node* second = first;
			Node* third = first->next;

			while (third) {
				if (first->value != third->value) {
					second = second->next;
					third = third->next;
					continue;
				}
				else {
					second->next = third->next;
					delete third;
					third = second->next;
					continue;
				}
				
			}
            
			first = first->next;
		}

	}
};
#endif

