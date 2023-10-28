// Exercise 21.x: Counting Palindromes
/*

		Write a program that inputs a sentence and counts the number of
		palindromes in it. A palindrome is a word that reads the same backward and forward. For example,
		"tree" is not a palindrome, but "noon" is
*/


#include<iostream>
#include<string>
#include<algorithm>
#include<iterator>
#include<cctype>
#include <regex>

bool isPalindrome(const std::string&);

int COUNTING_PALINDROMES()
{
	std::string sentence;;

	std::cout << "Sentence: ";
	std::getline(std::cin, sentence, '\n'); // In this sentence there are 3 palindromes: Radar, level, Aibohphobia

	int nPalindromes{};

	const std::regex PATTERN{ "(\\w)+\\W?" }; // Split the string
	auto it_words = std::sregex_iterator(sentence.cbegin(), sentence.cend(), PATTERN);
	auto it_end = std::sregex_iterator();


	for (; it_words != it_end; ++it_words) {

		if (isPalindrome(it_words->str())) {
			++nPalindromes;
		}
	}

	std::cout << "Number of Palindromes: " << nPalindromes << std::endl;;
	return 0;
}

bool isPalindrome(const std::string& rhs)
{
	std::string original_string;

	std::copy_if(rhs.cbegin(), rhs.cend(),
		std::back_inserter(original_string),
		[](auto str) ->bool {return std::isalpha(str); });

	if (not original_string.empty()) {

		std::string reversed_string;

		std::transform(original_string.begin(), original_string.end(),
			original_string.begin(),
			[](auto str) {return std::tolower(str); });

		std::reverse_copy(original_string.cbegin(), original_string.cend(),
			std::back_inserter(reversed_string));

		return std::equal(original_string.cbegin(), original_string.cend(),
			reversed_string.cbegin(), reversed_string.cend());
	}
	return false;
}

