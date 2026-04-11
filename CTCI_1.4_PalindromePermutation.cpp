/*
Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palindrome. A palindrome is a word
or phrase that is the same forwards and backwards. A permutation is a rearrangement of letters. The palindrome does not need
to be limited to just dictionary words. You can ignore casing and non-letter characters.

EXAMPLE:
input: Tact Coa
Output: true (permutations: "taco cat", "atco cta", etc.)

Conclusion: This is a bit overengineered but it is logically correct. Will work on refining as I work through problems.

*/

#include<iostream>
#include<string>

std::string strToLower(std::string str1) {
	
	if (str1.length() == 0) {
		return "";
	}

	char charCheckLower[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	char charCheckUpper[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };

	for (int i = 0; i < str1.length(); i++) {
		for (int j = 0; j < 26; j++) {
			if (str1[i] == charCheckUpper[j]) {
				str1[i] = charCheckLower[j];
			}
		}
	}

	return str1;
}

bool palperm(std::string str1) {

	int map[128] = { 0 };
	str1 = strToLower(str1);
	int CharacterCount = 0;

	char charCheckLower[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	for (int i = 0; i < str1.length(); i++) {
		for (int j = 0; j < 26; j++) {
			if (str1[i] == charCheckLower[j]) {
				int mapChar = str1[i];
				map[mapChar]++;
				CharacterCount++;
			}
		}
	}

	if (CharacterCount % 2 == 1) {
		int evenCount = 0;
		int oddCount = 0;
		for (int i = 0; i < 128; i++) {
			if ((map[i] != 0) && (map[i] % 2 == 0)) {
				evenCount++;
			}
			if ((map[i] != 0) && (map[i] % 2 == 1)) {
				oddCount++;
			}
			else {
				continue;
			}
		}
		if (oddCount > 1) {
			return false;
		}
	}

	else if (CharacterCount % 2 == 0) {
		int evenCount = 0;
		int oddCount = 0;
		for (int i = 0; i < 128; i++) {
			if ((map[i] != 0) && (map[i] % 2 == 0)) {
				evenCount++;
			}
			if ((map[i] != 0) && (map[i] % 2 == 1)) {
				oddCount++;
			}
			else {
				continue;
			}
		}
		if (oddCount > 0) {
			return false;
		}
	}
		return true;

	
}


int main() {

	std::string test1 = "Tact Coa";

	std::cout << "String test 1 =: " << palperm("Tact Coa") << " " << std::endl;

	return 0;
}
