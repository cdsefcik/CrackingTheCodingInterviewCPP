#include "Header.h"


int main() {

	std::string string1;
	std::string string2;
	
	//Enter a string.
	std::cout << "Enter a string: " <<std::endl;
	std::getline(std::cin, string1);

	//Enter a second string.
	std::cout << "Enter a second string: " << std::endl;
	std::getline(std::cin, string2);

	//Print the first string.
	std::cout << "The first string is: " << string1 << std::endl;
	//Print the second string.
	std::cout << "The second string is: " << string2 << std::endl;

	//Print out the ordered result of the strings.
	std::cout << "The ordered result for string 1 is: " << selectionSort(string1) << "\n";
	std::cout << "The ordered result for string 2 is: " << selectionSort(string2) << "\n";
	
	//Print the first checkPerm method
	std::cout << "Is the second string a permutation of the first string, using data structure? " << "\n";
	std::cout << "Result: " << (iSPermutationHM(string1, string2) ? "True":"False") << "\n";
	//Print the second checkPerm method
	std::cout << "Is the second string a permutation of the first string, using ordered list? " << "\n";
	std::cout << "Result: " << (isPermutationDL(string1, string2) ? "True":"False") << "\n";

	return 0;

};