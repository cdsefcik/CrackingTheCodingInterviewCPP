#include "Header.h"
//#include "Header.h"

using namespace std;


int main() {

	string string1 = "abcDefg    hijklmnopqrstuvwxYz";

	bool value = isUnique(string1);
	std::cout << "The string is unique? " << (value ? "true" : "false") << '\n';

	bool value2 = isUniqueNoDS(string1);
	std::cout << "The string is unique? " << (value2 ? "true" : "false") << '\n';

	return 0;
}	