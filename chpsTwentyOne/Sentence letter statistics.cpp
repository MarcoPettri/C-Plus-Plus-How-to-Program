// 21.x: Sentence letter statistics
/*
		Write a program that prints statistics about a sentence. The program
		asks the user to enter a sentence and the program prints how many times each ASCII character
		appears in the sentence. Ignore case in your implementation.
*/


#include<iostream>
#include<string>
#include<map>

int SENTENCE_LETTER_STATISTICS()
{
	std::map<char, int> alphabet{ 
		{'a', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0},
		{'f', 0}, {'g', 0}, {'h', 0}, {'i', 0}, {'j', 0}, 
		{'k', 0}, {'l', 0}, {'m', 0}, {'n', 0}, {'o', 0}, 
		{'p', 0}, {'q', 0}, {'r', 0}, {'s', 0}, {'t', 0}, 
		{'u', 0}, {'v', 0}, {'w', 0}, {'x', 0}, {'y', 0},
		{'z', 0}
	};
	std::string sentence;

	std::cout << "Enter the sentence: ";
	std::getline(std::cin, sentence, '\n');

	for (const auto& str : sentence) {

		int val{ static_cast<int>(str) };

		if (val > 64 && val < 91) {
			
			// A(65) to a(97), B(64) to b(98), ... , Z(90) to z(122) = 32 
			val += 32; // so, 65('A') + 32 = 97('a'), ... , 90('Z') + 32 = 122('z')

			alphabet[static_cast<char>(val)] += 1;
		}
		else if (val > 89 && val < 123) {
			alphabet[static_cast<char>(val)] += 1;
		}
	}

	for (const auto& pair : alphabet) {
		std::cout << pair.first << ": " << pair.second << std::endl;
	}


	return 0;
}

