// Exercise 21.x: Counting Vowels
/*

		Write a program that counts the total number of vowels in a sentence.
		Output the frequency of each vowel
*/



#include<iostream>
#include<string>
#include<map>

int COUNTING_VOWELS()
{
	std::map<char, int> vowels{
		{'a', 0}, {'e', 0}, {'i', 0}, {'o', 0}, {'u', 0}
	};

	std::string sentence;

	std::cout << "Enter the sentence: ";
	std::getline(std::cin, sentence, '\n');

	for (const auto& str : sentence) {

		int value{ static_cast<int>(str) };

		if (value > 64 && value < 91) { value += 32; }

		switch (value) {

		case 'a':
			++vowels['a'];
			break;

		case 'e':
			++vowels['e'];
			break;

		case 'i':
			++vowels['i'];
			break;

		case 'o':
			++vowels['o'];
			break;

		case 'u':
			++vowels['u'];
			break;

		default:
			break;
		}
	}

	for (const auto& pair : vowels) {
		std::cout << pair.first << ": " << pair.second << std::endl;
	}


	return 0;
}