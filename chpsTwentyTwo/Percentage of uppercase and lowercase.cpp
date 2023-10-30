// Exercise 22.x: Percentage of uppercase and lowercase letters
/*
		Write a program that inputs a line of text using the cin member function getline (as in
		Chapter 13) into a character array s[100] and outputs the percentage of uppercase and lowercase
		letters.
*/


#include<iostream>
#include<cctype>
#include<cstring>

int PERCENTAGE_OF_UPPERCASE_AND_LOWERCASE_LETTERS()
{
	char s[100];

	std::cout << "Sentence: ";
	std::cin.getline(s, 100, '\n');
	
	
	std::size_t len{ std::strlen(s) };

	int upper{};
	int lower{};
	for (char* sPtr{ s }; *sPtr != '\0'; ++sPtr) {

		if (std::islower(*sPtr)) { ++lower; }
		else if (std::isupper(*sPtr)) { ++upper; }
	}

	std::cout.precision(3);
	std::cout << std::fixed
		<< "\nLowers: " << (float(lower) / len) * 100
		<< "\nUppers: " << (float(upper) / len) * 100
		<< std::endl;

	return 0;
}