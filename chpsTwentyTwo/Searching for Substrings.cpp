// Exercise 22.x: Searching for Substrings
/*
		Write a program that inputs a line of text and a search string from
		the keyboard. Using function strstr, locate the first occurrence of the search string in the line of
		text, and assign the location to variable searchPtr of type char*. If the search string is found, print
		the remainder of the line of text beginning with the search string. Then use strstr again to locate
		the next occurrence of the search string in the line of text. If a second occurrence is found, print the
		remainder of the line of text beginning with the second occurrence.
*/


#include<iostream>
#include<cstring>
#include<string>

int SEARCHING_FOR_SUBSTRINGS()
{

	std::string sentence;
	std::string key;

	std::cout << "sentence: ";
	std::getline(std::cin, sentence);

	std::cout << "search string: ";
	std::getline(std::cin, key);

	
	const char* searchPtr = std::strstr(sentence.c_str(), key.c_str());

	while (searchPtr) {
		std::cout << searchPtr++ << std::endl;
		searchPtr = std::strstr(searchPtr, key.c_str());
	}

	
	
	

	
	return 0;
}