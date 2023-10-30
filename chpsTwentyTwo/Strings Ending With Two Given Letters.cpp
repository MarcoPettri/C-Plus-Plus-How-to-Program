// Exercise 22.x: Strings Ending With Two Given Letters
/*
	Write a program that reads a series of strings from
	the command-line and prints only those strings that end with a two-letter combination specified by
	the user, for example "ed".

*/

#include<iostream>
#include<cstring>

bool endswith(const char*, const char[3]);

int STRINGS_ENDING_WITH_TWO_GIVEN_LETTERS(int argc, char* argv[])
{
	char key[3];
	std::cout << "key: ",
		std::cin >> key;

	for (int i{ 1 }; i < argc; ++i) {

		if (endswith(argv[i], key)) {
			std::cout << argv[i] << std::endl;
		}
	}

	return 0;
}

bool endswith(const char* str, const char key[3])
{
	std::size_t len{ std::strlen(str)};

	switch (len) {

	case 0 || 1:
		return false;

	case 2:
		return { !std::strcmp(str, key) ? true : false };

	default:
		len -= 2;
		return { !std::strcmp(&str[len], key) ? true : false };
			
	}
	
}