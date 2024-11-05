#include<iostream>
#include<string>
#include"LinkedList.h"


/*
*Implement an algorithm to find the kth to last element of a singly linked list. 
*/

Node* returnKthLast(LinkedList *LL, int kthLast) {
	int length = LL->getLength();
	if (((length - 1) - kthLast < 0) || (kthLast < 0) ) {
		return nullptr;
	}
	Node* kthLastNode = LL->get((length - 1) - kthLast);

	return kthLastNode;
}

int main(){

	LinkedList* LL = new LinkedList(1);

	LL->append(2);
	LL->append(3);
	LL->append(4);
	LL->append(5);
	LL->append(6);
	LL->append(7);
	LL->append(8);
	LL->append(9);
	LL->append(10);
	LL->append(11);
	LL->append(12);
	LL->append(13);
	LL->append(14);

	LL->printList();


	int kthLast;
	std::cout << "Enter the kth last element you would like to retreive: ";
	std::cin >> kthLast;

	try {

		Node* value = returnKthLast(LL, kthLast);
		if (value == nullptr) {
			std::string err = "Error Occured: ";
			throw err;
		}
		else {
			std::cout << "The value of the kth last element is: " << value->value << std::endl;
		}
	}
	catch(...){
		std::cout << "Error Occured: ";
	}

	std::cout << "THESE ARE THE LINKED LIST TEST FUNCTIONS: " << std::endl;
	LL->printList();
	//Linked List Test functions:
	LL->getHead();
	LL->getTail();
	LL->printList();
	LL->deleteFirst();
	LL->printList();
	LL->deleteLast();
	LL->printList();
	LL->deleteNode(10);
	LL->printList();
	LL->insert(5, 600);
	LL->printList();
	LL->prepend(1000);
	LL->printList();
	LL->set(3, 10000);
	LL->printList();
	LL->reverseList();
	LL->printList();

	return EXIT_SUCCESS;
};