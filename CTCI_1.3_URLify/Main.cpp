#include<iostream>
#include<string>

/*
*Write a method to replace all spaces in a string with "%20". You may assume that the string has sufficient space at the end to hold the additional
* characters, and that you are given the "true" length of the string. (Note: if implementing in java, please use a character array so that you can perform
* this operation in place.)
* EXAMPLE
* Input: "Mr John Smith       ", 13
* Output: "Mr%20John%20Simth"
*/


int main() {
	//Request the string from the user.
	std::string input;
	std::cout << "Enter a string: ";
	getline(std::cin,input);

	//Request the string length from the user.
	std::cout << "Enter the string length: " ;
	int length = 0;
	std::cin >> length;

	//If the string length is less than or equal to 0, exit the program.
	if (length <= 0) {
		std::cout << "The length is less than 0";
		return 0;
	}

	std::cout << "Here is the string entered: " << input << std::endl;

	//Count spaces.
	int spaceCount = 0;
	for (int i = 0; i < length; i++) {
		if (input.at(i) == ' ') {
			spaceCount++;
	    }
	}

	//Initialize the array.
	char* inputArray = new char[length + (spaceCount*2)];

	//Fill the array with the characters.
	for (int i = 0; i < length; i++) {
		inputArray[i] = input.at(i);
	}

	//Logic to add the %20.
	for (int i = (length + (spaceCount * 2) - 1), j = (length - 1); j >= 0; i--, j--) {
		if (inputArray[j] != ' ') {
			inputArray[i] = inputArray[j];
			continue;
		}
		else {
			inputArray[i] = '0';
			inputArray[i - 1] = '2';
			inputArray[i - 2] = '%';
			i = i - 2;
			continue;
		}
		
	}
	
	//Print out the array.
	for (int i = 0; i < length + (spaceCount * 2); i++) {
		std::cout << inputArray[i] << " ";
	}
	return EXIT_SUCCESS;
};