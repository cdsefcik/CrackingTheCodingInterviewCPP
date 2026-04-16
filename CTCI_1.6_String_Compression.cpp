/*
String Compression: Implement a method to perform basic string compression using the counts of repeated characters. For
example, the string aabccccaaa would become a2b1c5a3. If the "compressed" string would not become smaller than the 
original string, your method should return the original string. You can assume the string has only upper case and lower case
letters. (a-z)

Conclusion: Next time, make this more efficient rather than handling all cases separately.

*/

#include <iostream>
#include <string>	

std::string strCmp(std::string str1) {

	std::string strCmp = "";

	if (str1.length() <= 2) {
		return str1;
	}

	int currentCharacterCount = 0;
	char currentCharacter = '!';
	for (int i = 0; i < str1.length(); i++) {	
		if (i == 0) {
			std::cout << "If 1: " << std::endl;
			currentCharacter = str1[i];
			currentCharacterCount++;
			std::cout << strCmp << std::endl;
			continue;
		}
		else if (str1[i] == currentCharacter) {
			std::cout << "If 2: " << std::endl;
			currentCharacterCount++;
			if (i == str1.length() - 1) {
				std::cout << "If 3: " << std::endl;
				strCmp += currentCharacter;
				strCmp += std::to_string(currentCharacterCount);
				std::cout << strCmp << std::endl;
				break;
			}
		}
		else if (str1[i] != currentCharacter) {
			std::cout << "If 4: " << std::endl;
			if (i == str1.length() - 1) {
				std::cout << "If 5: " << std::endl;
				strCmp += currentCharacter;
				strCmp += std::to_string(currentCharacterCount);//std::to_string(1);

				strCmp += str1[i];
				strCmp += "1";

				std::cout << strCmp << std::endl;
				break;
			}
			else {
				std::cout << "If 6: " << std::endl;
				strCmp += currentCharacter;
				strCmp += std::to_string(currentCharacterCount);
				currentCharacter = str1[i];
				currentCharacterCount = 1;
				std::cout << strCmp << std::endl;
				continue;
			}
		}

	}

	std::cout << strCmp << std::endl;
	return (str1.length() <= strCmp.length()) ? str1 : strCmp;
}

int main() {

	std::string stringTest1 = "aabcccccaaa";
	std::string stringTest2 = "bbbbb";
	std::string stringTest3 = "ab";

	std::cout << "Test 1: " << strCmp(stringTest1) << std::endl;
	std::cout << "Test 2: " << strCmp(stringTest2) << std::endl;
	std::cout << "Test 3: " << strCmp(stringTest3) << std::endl;

	return 0;
}




