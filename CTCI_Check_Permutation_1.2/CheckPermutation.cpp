#include "Header.h"

/*
* Check Permutation: Given two strings, write a method to decide if one is a permutation of the other.
* 
* There are two solutions to this problem.
* 1: One that uses a hash map and the other that is in O(nlog(n)) time.
* 
* The idea behind this problem is that both strings should contain the same characters, spaces do not matter.
* Use the ascii extended encoding scheme.
* This problem is case sensitive: God is different than dog. 
* Whitespace is considered.
* The strings have to be the same size in order to be a permutation of each other.
*/

bool iSPermutationHM(std::string a, std::string b) {
	
	int characterCount[256] = {0};

	int stringaLength = a.length();
	int stringbLength = b.length();

	if (stringaLength < stringbLength) {
		
		return false;
	}
	else {
		for (int i = 0; i < stringaLength; i++) {
			char character = a[i];
			int a = character;
			characterCount[a]++;
		}


		for (int i = 0; i < stringbLength; i++) {
			char character = b[i];
			int b = character;
			if (characterCount[b] == 0) {
				return false;
			}

		}
		return true;
	}
};


std::string selectionSort(std::string a) {
	if (a.length() == 0 || a.length() == 1) {
		return a;
	}
	for (int i = 0; i <= a.length()-2; i++) {
		int lowest = i;
		for (int j = i + 1; j <= a.length()-1; j++) {
			if (a[j] < a[lowest]) {
				lowest = j;
			}
		}
		char temp = a[i];
		a[i] = a[lowest];
		a[lowest] = temp;
	}

	return a;
};


bool isPermutationDL(std::string a, std::string b) {

	int lengtha = a.length();
	int lengthb = b.length();
	//Check length
	if (lengtha != lengthb) {
		return false;
	}
	else {
	a = selectionSort(a);
	b = selectionSort(b);
		for (int i = 0; i < lengtha; i++) {
			if (a[i] == b[i]) {
				continue;
			}
			return false;
		}
	}

	return true;
};