// Exercise 22.x: Searching for Characters
/*
		Write a program based on Exercise 22.18 that inputs a file name
		and a string and uses the function countStr to determine the total number of occurrences of the
		search string in the file. Output the result
*/

#pragma warning(disable : 4996) // strok is Unsafe Standard Library function in VS

#include<iostream>
#include<string>
#include<iterator>
#include<fstream>
#include<cstdlib>

int SEARCHING_FOR_CHARACTERS2()
{
	std::string	  name;
	std::ifstream file;

	std::cout << "Enter the name file with the format suffix(name.txt): ";
	std::getline(std::cin, name, '\n');

	file.open(name, std::ios::in);

	if (!file) {
		std::cerr << "Unable to open" << std::endl;
		std::exit(EXIT_FAILURE);
	}

	std::string content{ (std::istreambuf_iterator<char>(file)),
						 (std::istreambuf_iterator<char>())
	};
	std::string	  key;
	int	 occurrences{ 0 };

	std::cout << "search character:  ",
		std::cin >> key;

	
	auto countStr{
		[&key](const char* rhs)->bool {return key == rhs; }
	};

	for (char* tokenPtr{ std::strtok(content.data(), " ") };
		tokenPtr != NULL;
		tokenPtr = std::strtok(NULL, " ")) {

		if (countStr(tokenPtr)) { ++occurrences; }
	}

	std::cout << "Occurrences: " << occurrences;

	return 0;
}