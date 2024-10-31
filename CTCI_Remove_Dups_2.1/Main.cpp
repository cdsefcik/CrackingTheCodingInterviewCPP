#include "LinkedList.h"
#include <iostream>

/*
* Main driver program for remove duplicates.
* Code and Cracking the Coding Interview question details on the linkedList.h file.
*/


int main() {

	std::cout << "THIS IS THE DUPLICATE DELETE CHECK: " << std::endl;
	//Test the duplicate values deletion
	LinkedList* DupeCheck = new LinkedList(1);
	DupeCheck->append(1);
	DupeCheck->append(2);
	DupeCheck->append(2);
	DupeCheck->append(1);
	DupeCheck->append(3);
	DupeCheck->append(3);
	DupeCheck->append(4);
	DupeCheck->append(4);
	DupeCheck->append(5);
	DupeCheck->append(5);
	DupeCheck->append(6);
	DupeCheck->append(6);
	DupeCheck->append(6);
	DupeCheck->append(6);
	DupeCheck->append(6);
	DupeCheck->append(9);
	DupeCheck->append(9);
	DupeCheck->append(2);
	DupeCheck->append(1);
	DupeCheck->append(100);
	DupeCheck->append(1);
	DupeCheck->append(2);
	DupeCheck->append(2);
	DupeCheck->append(1);
	DupeCheck->append(3);
	DupeCheck->append(3);
	DupeCheck->append(4);
	DupeCheck->append(4);
	DupeCheck->append(5);
	DupeCheck->append(5);
	DupeCheck->append(6);
	DupeCheck->append(100);

	std::cout << "Before removal of duplicates" << std::endl;
	DupeCheck->printList();
	DupeCheck->removeDuplicates();
	std::cout << "After removal of duplicates" << std::endl;
	DupeCheck->printList();

	return 0;
}