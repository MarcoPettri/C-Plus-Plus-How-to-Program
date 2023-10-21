// Exercise 16.x: Enhanced Palindrome Tester
/*
		Enhance Exercise 16.12's palindromeTester function to allow strings containing
		uppercase and lowercase letters and punctuation. 
		Before testing whether the original string is a palindrome, function palindromeTester 
		should convert the string to lowercase letters and eliminate any punctuation.
		For simplicity, assume the only punctuations characters can be

									. , ! ; : ()

		You can use the copy_if algorithm and a back_inserter to make a copy of the original string,
		eliminate the punctuation characters and place the characters into a new string object.

*/

#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>
#include<iterator>


bool palindromeTester2(const std::string&);

int ENHANCED_PALINDROME_TESTER()
{
	std::string test1{ "Ra-dAr" };
	std::string test2{ "(Able was i ere i saw elba!)" };
	std::string test3{ "It is not a Palindrome" };

	std::cout << "Testing Palindromes\n" << std::endl;

	std::cout << test1 << ": " << std::boolalpha << palindromeTester2(test1) << std::endl;
	std::cout << test3 << ": " << palindromeTester2(test3) << std::endl;
	std::cout << test2 << ": " << palindromeTester2(test2) << std::endl;

	return 0;
}

bool palindromeTester2(const std::string& rhs)
{
	std::string original_string;
	std::string reversed_string;

	
	std::copy_if(rhs.cbegin(), rhs.cend(),
				 std::back_inserter(original_string),
				 [](auto str) ->bool {return std::isalpha(str); });

	std::transform(original_string.begin(), original_string.end(),
					original_string.begin(),
					[](auto str) {return std::tolower(str); });

	std::reverse_copy(original_string.cbegin(), original_string.cend(),
						std::back_inserter(reversed_string));

	return std::equal(original_string.cbegin(), original_string.cend(),
						reversed_string.cbegin(), reversed_string.cend());
}

