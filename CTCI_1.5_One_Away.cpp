/*
There are three types of edits that can be performed on strings: insert a character, remove a character, or replace a
character. Given two strings, write a function to check if they are one edit (or zero edits) away.
EXAMPLE
pale, ple -> true
pales, pale -> true
pale, bale -> true
pale, bake -> false

Conclusion, took a few tries. 

*/

#include<iostream>
#include<cmath>

bool oneAway(std::string str1, std::string str2) {

	if ((str1.length() == 0 && str2.length() == 0) || (str1.length() == 1 && str2.length() == 1) ||
		(str1.length() == 1 && str2.length() == 0) || (str1.length() == 0 && str2.length() == 1)) {
		std::cout << "IF 1" << std::endl;
		return true;
	}
	else if (std::abs((int)str1.length() - (int)str2.length()) > 1) {
		std::cout << "IF 2" << std::endl;
		return false;
	}
	else if (std::abs((int)str1.length() - (int)str2.length()) == 1) {
		std::cout << "IF 3" << std::endl;
		std::string strShort = ((str1.length() - str2.length()) <= 0) ? str1 : str2;
		std::string strLong = ((str1.length() - str2.length()) > 0) ? str1 : str2;

		int strShortCount = 0;
		int strLongCount = 0;

		bool differenceCount = false;
		while ((strShortCount < strShort.length()) && (strLongCount < strLong.length())) {

			if (strShort[strShortCount] == strLong[strLongCount]) {
				strShortCount++;
				strLongCount++;
				continue;
			}

			else if ((strShort[strShortCount] != strLong[strLongCount]) && differenceCount == false) {
				strLongCount++;
				differenceCount = true;
			}

			else if ((strShort[strShortCount] != strLong[strLongCount]) && differenceCount == true) {
				return false;
			}
			
		}
		return true;
	}

	else if (std::abs((int)str1.length() - (int)str2.length()) == 0) {
		std::cout << "IF 4" << std::endl;
		int diffCount = 0;
		for (int i = 0; i < str1.length(); i++) {
			if (str1[i] != str2[i]) {
				diffCount++;
				if (diffCount > 1) {
					return false;
				}
				continue;
			}
			else {
				continue;
			}
		}
		return true;
	}

	return false;

}


int main() {

	//Examples
	std::string str1 = "pale", str2 = "ple";
	std::string str3 = "pales", str4 = "pale";
	std::string str5 = "pale", str6 = "bale";
	std::string str7 = "pale", str8 = "bake";

	std::cout << "Test 1: " << oneAway(str1, str2) << " " << std::endl;
	std::cout << "Test 2: " << oneAway(str3, str4) << " " << std::endl;
	std::cout << "Test 3: " << oneAway(str5, str6) << " " << std::endl;
	std::cout << "Test 4: " << oneAway(str7, str8) << " " << std::endl;


	return 0;
}
