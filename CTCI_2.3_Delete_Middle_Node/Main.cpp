#include<iostream>
#include"LinkedList.h"

/*
*Delete Middle Node: Implement an algoririthm to delete a node in the middle (i.e., any node but the first and last node, not necessarily the exact middle)
* of a singly linked list, given only access to that node.
* Example Input: The node c from the linked list a -> b -> c -> d -> e -> f
* Result: Nothing is returned, but the new linked list looks like a -> b -> d -> e -> f
*/

int main() {

	//Test LL
	LinkedList* LL = new LinkedList(0);
	
	for (int i = 1; i < 11; i++) {
		LL->append(i);
	}

	LL->printList();

	LL->deleteMiddleNode();
	
	LL->printList();

	return EXIT_SUCCESS;
};