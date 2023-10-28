// Exercise 21.x:Reversing a string with Iterators
/*
	Write a program that inputs a line of text and prints the
	text backward. Use iterators in your solution
*/

#include<iostream>
#include<string>
#include<iterator>

int REVERSING_A_STRING_WITH_ITERATORS()
{
	std::string sentence;
	
	std::cout << "Sentence: ",
		std::getline(std::cin, sentence);

	std::cout << "Reversed sentence\n";
	for (auto it{ sentence.crbegin() }; it != sentence.crend(); ++it) {
		std::cout << *it;
	}

	std::cout << "\n";

	std::ostream_iterator<decltype(sentence)::value_type> out{std::cout};
	std::copy(sentence.crbegin(), sentence.crend(), out);
	

	return 0;
}