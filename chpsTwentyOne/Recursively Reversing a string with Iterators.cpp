// 21.x: Recursively Reversing a string with Iterators
/*
		Write a recursive version of Reversing a string with Iterators.

*/


#include<iostream>
#include<string>

typedef std::string::const_iterator const_it;

void reverse_string(const_it, const const_it);

int RECURSIVELY_REVERSING_A_STRING_WITH_ITERATORS()
{
	std::string input;

	std::cout << "Sentence: ",
		std::getline(std::cin, input);

	reverse_string(input.cbegin(), input.cend());

	
	return 0;
}

void reverse_string(const_it first, const const_it last)
{

	if (first == last) {
		return;
	}
	reverse_string(++first, last);

	std::cout << *(--first);

}
