// Exercise 16.x: Palindrome Tester
/*
			A palindrome is a string that is spelled the same way forward and backward.
			Examples of palindromes include "radar" and "able was i ere i saw elba." Write a function
			palindromeTester that uses the reverse algorithm on an a copy of a string, then compares the
			original string and the reversed string to determine whether the original string is a palindrome.
			Like the Standard Library containers, string objects provide functions like begin and end to obtain
			iterators that point to characters in a string. Assume that the original string contains all lowercase
			letters and does not contain any punctuation. Use function palindromeTester in a program.

*/

#include<iostream>
#include<string>
#include<algorithm>
#include<iterator>


bool palindromeTester(const std::string&);

int PALINDROME_TESTER()
{
	std::string test1{ "radar" };
	std::string test2{ "able was i ere i saw elba" };
	std::string test3{ "it is not a palindrome" };

	std::cout << "Testing Palindromes\n" << std::endl;

	std::cout << test1 << ": " << std::boolalpha << palindromeTester(test1) << std::endl;
	std::cout << test3 << ": " << palindromeTester(test3) << std::endl;
	std::cout << test2 << ": " << palindromeTester(test2) << std::endl;

	return 0;
}

bool palindromeTester(const std::string& rhs)
{

	std::string reversed_string;

	std::reverse_copy(rhs.cbegin(), rhs.cend(),
		std::back_inserter(reversed_string));

	return std::equal(rhs.cbegin(), rhs.cend(),
		reversed_string.cbegin(), reversed_string.cend());
}

