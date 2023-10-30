//Exercise 22.x: Searching for Substrings
/*

	Write a program based Exercise 22.17 that inputs a line of text
	and a search string, then uses function subStr to determine the total number of occurrences of the
	string in the line of text. Print the result.

*/

#include<iostream>
#include<cstring>
#include<string>

int SEARCHING_FOR_SUBSTRINGS2()
{

	std::string sentence;
	std::string key;

	std::cout << "sentence: ";
	std::getline(std::cin, sentence);

	std::cout << "search string: ";
	std::getline(std::cin, key);

	int occurence{0};
	const char* searchPtr = std::strstr(sentence.c_str(), key.c_str());

	while (searchPtr) {

		++occurence;
		searchPtr = std::strstr(searchPtr, key.c_str());
	}


	std::cout << "Occurrences: " << occurence << std::endl;



	return 0;
}