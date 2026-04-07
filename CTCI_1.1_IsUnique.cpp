/*
Problem: Is unique: Implement an algorithm to determine if a string has all unique characters. What if you can not use
additional data structures?

Questions:
1: This is a string, every character appears only once?
2: Are all characters considered?
3: Is A = a or are these considered unique?
4: How is white space considered?

Analysis:
1: Will proceed with yes, every character appears only once.
2: Will only use the string as the data structure. Will determine in place.
3: A != a. Every character will be as is.
4: Assume no white space.

Conclusion:
Will assume, white space is not counted, every character is what the character is, A != a.
1: because I can not use another data structure, will operate on the string in place. 
2: Return type is true or false
*/

#include<iostream>
#include<string>


bool isUnique(std::string str) {

	int length = str.length();

	for (int i = 0; i < length; i++) {
		char val1 = str[i];
		if (val1 == ' ') {
			continue;
		}
		
		for (int j = i + 1; j < length; j++) {
			char val2 = str[j];
			
			if (val1 == val2) {
				
				return false;
			}
		}

	}


	return true;
}


int main() {
	std::string Test1 = "This is a test string"; //Should return false
	std::string Test2 = "abcdef"; //Should return true
	std::string Test3 = "Ansfga"; //Should return true
	std::string Test4 = "Ans fg a"; //Should return true

	std::cout << "Test1 is: " << isUnique(Test1) << std::endl;
	std::cout << "Test2 is: " << isUnique(Test2) << std::endl;
	std::cout << "Test3 is: " << isUnique(Test3) << std::endl;
	std::cout << "Test4 is: " << isUnique(Test4) << std::endl;

	return 0;
}
