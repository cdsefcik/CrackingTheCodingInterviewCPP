/*
Given two strings, write a method to decide if one is a permutation of the other.

Questions:
1: Are the characters in both srings ASCII 128? 

Conclusion:
Will implement based on ASCII 256 and count the characters.
In this case, A != a.
Strings of different lengths can not be permutions of each other.
Consider white space, "dog" is not a permution of "god    ".

*/
#include <iostream>

bool permutation(std::string s1, std::string s2) {
	
	int characterArray[256] = { 0 };
	
	//Determine which string is the largest, use as compare string
	if (s1.length() != s2.length()) {
		return false;
	}

	//Add the values from string 1;
	for (int i = 0; i < s1.length(); i++) {
		char c1 = s1[i];
		int c1Index = c1;
		characterArray[c1Index]++;
	}

	//Subtract the values from string 2;
	for (int i = 0; i < s2.length(); i++) {
		char c2 = s2[i];
		int c2Index = c2;
		characterArray[c2Index]--;
	}

	
	//Check the array for any index with value less than zero. If less than zero, return false.
	for (int i = 0; i < 256; i++) {
		if (characterArray[i] < 0) {
			return false;
		}
	}

	return true;
}


int main() {
	std::string s1A = "RTYdffgyedh";  //No
	std::string s1B = "dffgy";

	std::string s2A = "poiuy"; //No
	std::string s2B = "poiuytrewq";

	std::string s3A = "qwertyuiop"; //No
	std::string s3B = "zxcvbnm";

	std::string s4A = "dog"; //Yes
	std::string s4B = "god";

	std::string s5A = "dog"; //No
	std::string s5B = "god   ";

	std::cout << "Test 1: " << permutation(s1A, s1B) << " " << std::endl;
	std::cout << "Test 2: " << permutation(s2A, s2B) << " " << std::endl;
	std::cout << "Test 3: " << permutation(s3A, s3B) << " " << std::endl;
	std::cout << "Test 4: " << permutation(s4A, s4B) << " " << std::endl;
	std::cout << "Test 5: " << permutation(s5A, s5B) << " " << std::endl;



	return 0;

}
