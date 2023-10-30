// Exercise 22.x: Strings Beginning With A Given Letter
/*
		Write a program that reads a series of strings from
		the command-line and prints only those strings beginning with a given letter specified by the user.
		The program should ignore case.
*/

#include<iostream>
#include<cctype>


int STRINGS_BEGINNING_WITH_A_GIVEN_LETTER(int argc, char* argv[])
{
	char key;
	std::cout << "key: ",
		std::cin >> key;

	auto startswith{ 
		[&key](const char& rhs) -> bool {
			return {
				std::tolower(rhs) == key ||
				std::toupper(rhs) == key 
				? true :  false
			 };
		}
	};

	for (int i{ 1 }; i < argc; ++i) {

		if (startswith(*argv[i])) {
			std::cout << argv[i] << std::endl;
		}
	}

	return 0;
}