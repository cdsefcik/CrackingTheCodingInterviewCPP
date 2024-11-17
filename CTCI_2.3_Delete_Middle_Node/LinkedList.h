#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#pragma once

#include <iostream>

/*
*Linked List header file.
*/

class Node {
public:
	int value;
	Node* next;

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

public:
	//Constructor
	LinkedList(int value) {
		Node* newNode = new Node(value);
		head = newNode;
		tail = newNode;
		length = 1;
	}

	//Destructor

	~LinkedList() {
		Node* temp = head;
		while (head) {
			head = head->next;
			delete temp;
			temp = head;
		}
	}

	//Print List
	void printList() {
		Node* temp = head;
		while (temp) {
			std::cout << temp->value << std::endl;
			temp = temp->next;
		}
	}

	//Get Head
	void getHead() {
		if (head == nullptr) {
			std::cout << "The list is empty: " << std::endl;
		}
		else {
			std::cout << "The head is: " << head->value << std::endl;
		}
	}

	//Get Tail
	void getTail() {
		if (tail == nullptr) {
			std::cout << "The list is empty: " << std::endl;
		}
		else {
			std::cout << "The tail is: " << tail->value << std::endl;
		}
	}

	//Get length
	int getLength() {
		return length;
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
	void prepend(int value) {
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
			prepend(value);
			return true;
		}
		if (index == length) {
			append(value);
			return true;
		}
		else {
			Node* newNode = new Node(value);
			Node* temp = get(index - 1);
			newNode->next = temp->next;
			temp->next = newNode;
			length++;
			return true;
		}
	}

	//Delete First
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
			head = head->next;
		}
		delete temp;
		length--;
	}

	//Delete Last
	void deleteLast() {
		if (length == 0) return;
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

	//Delete
	void deleteNode(int index) {
		if (index < 0 || index > length - 1) {
			return;
		}
		if (index == 0) {
			deleteFirst();
			return;
		}
		if (index == length - 1) {
			deleteLast();
			return;
		}
		else {
			Node* pre = get(index - 1);
			Node* temp = pre->next;
			pre->next = temp->next;
			delete temp;
			length--;
		}
	}


	//Update
	bool set(int index, int value) {
		Node* temp = get(index);
		if (temp == nullptr) {
			return false;
		}
		else {
			temp->value = value;
			return true;
		}
	}

	//Get
	Node* get(int index) {
		if (index < 0 || index >= length) {
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

	//Reverse List
	void reverseList() {
		if (length == 0 || length == 1) {
			return;
		}
		else {
			Node* temp = head;
			head = tail;
			tail = temp;

			Node* pre = nullptr;
			Node* post = temp->next;

			for (int i = 0; i < length; ++i) {
				post = temp->next;
				temp->next = pre;
				pre = temp;
				temp = post;
			}

		}
	}

	bool deleteMiddleNode() {
		if (length == 0) {
			return false;
		}
		else {
			if (length % 2 == 0) {
				int index = (length / 2) - 1;
				deleteNode(index);
			}
			else if (length % 2 == 1) {
				int index = (length / 2);
				deleteNode(index);
			}
			return true;
		}
	}

};

#endif