/*
Write a method to replace all spaces in a string with "%20". You may assume that the string has sufficient space at the end to 
hold the additional characters, and that you are given the "true" length of the string. (Note: if implementing in java, please
use a character array so that you can perform this operation in place.)

EXAMPLE
Input: "Mr John Smith      ", 13
Output: "Mr%20John%20Smith",

*/

#include<iostream>

void URLify(char charArray[], int length, int charArrayLength) {


	for (int i = length - 1; i > 0; i--) {
		if (charArray[i] != ' ') {
			charArray[charArrayLength-1] = charArray[i];
			charArrayLength--;
		}
		else {
			charArray[charArrayLength - 1] = '0';
			charArray[charArrayLength - 2] = '2';
			charArray[charArrayLength - 3] = '%';
			charArrayLength = charArrayLength - 3;
		}

    }

}

int main() {

//Test Character Arrays
	int length = 13;
	char charArray1[17] = {'M','r',' ','J','o','h','n',' ','S','m','i','t','h',' ',' ',' ',' '};
	int charArrayLength = sizeof(charArray1) / sizeof(charArray1[0]);
	
	URLify(charArray1, length, charArrayLength);

	//std::cout << "This is the total size: " << charArrayLength << std::endl;
	for (const auto& character: charArray1) {
		std::cout << "Character: "<< character << std::endl;
	}

	return 0;
}
