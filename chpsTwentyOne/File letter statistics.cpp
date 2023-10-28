//Exercise 20.x: File letter statistics
/*
	Repeat exercise "Sentence letter statistics" but this time allow the user to specify a file name
		to work with. Print a simple bar chart to summarize the results

*/


#include<iostream>
#include<iomanip>
#include<string>
#include<map>
#include<fstream>>
#include<cstdlib>


int FILE_LETTER_STATISTICS()
{
	std::map<char, int> alphabet{
	{'a', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0},
	{'f', 0}, {'g', 0}, {'h', 0}, {'i', 0}, {'j', 0},
	{'k', 0}, {'l', 0}, {'m', 0}, {'n', 0}, {'o', 0},
	{'p', 0}, {'q', 0}, {'r', 0}, {'s', 0}, {'t', 0},
	{'u', 0}, {'v', 0}, {'w', 0}, {'x', 0}, {'y', 0},
	{'z', 0}
	};


	std::string name_file;
	std::string sentence;
	std::ifstream file;

	std::cout << "Enter the name of the file with the format suffix(name.txt): ";
	std::getline(std::cin, name_file, '\n');


	file.open(name_file, std::ios::in);

	if (!file) {
		std::cerr << "Unable to open " << name_file << std::endl;
		std::exit(EXIT_FAILURE);
	}

	file >> sentence;

	for (const auto& str : sentence) {

		int val{ static_cast<int>(str) };

		if (val > 64 && val < 91) {

			val += 32; 

			alphabet[static_cast<char>(val)] += 1;
		}
		else if (val > 89 && val < 123) {
			alphabet[static_cast<char>(val)] += 1;
		}
	}
	std::cout << "Letter" << std::right
		<< std::setw(8) << "Value"
		<< std::setw(8) << "Bar\n";
	
	

	for (const auto& pair : alphabet) {

		std::cout << std::setw(4) << pair.first
			<< "\t " << pair.second
			<< "\t  " << std::string(pair.second, '*')
		    << std::endl;
	}


	
	return 0;
}