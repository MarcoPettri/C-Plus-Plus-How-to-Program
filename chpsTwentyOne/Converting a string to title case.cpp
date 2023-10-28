// Exercise 21.x: Converting a string to title case
/*
		Write a program that converts a string to title case, that
		is, every letter that starts a word should be capitalized.
*/

#include<iostream>
#include<string>
#include<map>

int CONVERTING_A_STRING_TO_TITLE_CASE()
{

	std::map<char, char> alphabet{
		{'a', 'A'}, {'b', 'B'}, {'c', 'C'},
		{'d', 'D'}, {'e', 'E'}, {'f', 'F'},
		{'g', 'G'}, {'h', 'H'}, {'i', 'I'},
		{'j', 'J'}, {'k', 'K'}, {'l', 'L'},
		{'m', 'M'}, {'n', 'N'}, {'o', 'O'},
		{'p', 'P'}, {'q', 'Q'}, {'r', 'R'},
		{'s', 'S'}, {'t', 'T'}, {'u', 'U'},
		{'v', 'V'}, {'w', 'W'}, {'x', 'X'},
		{'y', 'Y'}, {'z', 'Z'}
	};

	std::string str;
	std::cout << "Enter a string: ";
	std::getline(std::cin, str, '\n');

	for (auto& chr : str) {

		if (chr == str.front() ||
			' ' == *(&chr - 1)) {

			if (auto key = alphabet.find(chr);
				key != alphabet.end()) {
				chr = alphabet[chr];
			}
		}
	}

	std::cout << str << std::endl;


	return 0;
}