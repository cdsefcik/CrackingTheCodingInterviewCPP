#include "Header.h"


/*Implememt an algorithm to determine if a string has all unique characters. What if you cannot use additional data structurs?
Note1: Whitespace does not matter.
Note2: Using an ascii extended 256 encoding check.

*/


	/*Is Unique using a hashmap*/
	bool isUnique(std::string a) {
		int checkList[256] = {0};

		//Note: the string length test where the length of the string is greater than 128 or 256 would fail if spaces existed.

		//Loop through, update checklist with count, check count, if count exceeds 1, then return false.
		for (int i = 0; i < a.length(); i++) {
			if (a[i] == ' ') {continue;}
			int character = a[i];
			checkList[character]++;
			if (checkList[character] > 1) { return false;}
		}

		return true;
	}


	/*Is Unique using no additional data structurs*/

	bool isUniqueNoDS(std::string a) {

		for (int i = 0; i < a.length()-1; i++) {
			if (a[i] == ' ') {
				continue;
			}
			char character = a[i];
			for (int j = i + 1; j < a.length(); j++) {
				if (character == a[j]) { return false;}
			}

		}
		
		return true;
	}

