// Exercise 22.x: Searching for Characters
/*
	
		Write a program that inputs a file name and a search character
		and uses function countChr to determine the total number of occurrences of the character in the file.
*/

#include<iostream>
#include<string>
#include<iterator>
#include<fstream>
#include<cstdlib>

int SEARCHING_FOR_CHARACTERS()
{
	std::string	  name;
	std::ifstream file;
	char		   key;
	int			   occurrences{ 0 };

	std::cout << "Enter the name file with the format suffix(name.txt): ";
	std::getline(std::cin, name, '\n');

	file.open(name, std::ios::in);

	if (!file) {
		std::cerr << "Unable to open" << std::endl;
		std::exit(EXIT_FAILURE);
	}


	std::cout << "search character:  ",
		std::cin >> key;


	auto countChr{
		[&key](const char rhs)->bool {return key == rhs; }
	};

	for (auto it{ std::istreambuf_iterator<char>(file) },
			  end{ std::istreambuf_iterator<char>() };
		it != end; ++it) {

		if (countChr(*it)) { ++occurrences; }
	}

	std::cout << "Occurrences: " << occurrences;

	return 0;
}