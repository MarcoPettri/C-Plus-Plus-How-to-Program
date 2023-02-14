// Exercise 8.15 : Machine-Language Programming

/*
 Note: See Machine-Language Programming.md

		Write SML programs to accomplish each of the following tasks:
			a) Use a sentinel-controlled loop to read positive numbers and compute and display their
				sum. Terminate input when a negative number is entered.
			b) Use a counter-controlled loop to read seven numbers, some positive and some negative,
				and compute and display their average.
			c) Read a series of numbers, and determine and display the largest number. The first num-
				ber read indicates how many numbers should be processed.

*/

#include "Simpletron.h"
#include<string>
#include<regex>


bool isNumber(const std::string&);

int Machine_Language_Programming() {

	std::string input;
	Simpletron simpletron;


 // A)
	std::cout << "A)\n";

	do {
		std::cout << "\n\tSimpletron\n"
			<< "-> OP to show available operations\n"
			<< "-> MA to show Memory address\n" 
			<< "-> Negative number to exit\n" <<  std::endl;
		
		std::cout << ">> ",
			std::cin >> input;


		if (isNumber(input)) {
			int operation = std::stoi(input) / 100;
			int address = std::stoi(input) % 100;
			simpletron.perform(operation, address); 
		}
		else if(input[0] != '-'){

			if (input == "OP") { simpletron.displayOperations(); }
			else if (input == "MA") { simpletron.displayMemory(); }
			else { std::cout << "...\n" << std::endl; }
		}
	

	} while (input[0] != '-');

	simpletron.reset();

// B)

	std::cout << "\nB)\n\n";

	for (int address{ 0 }; address <= 7; address++) {

		std::cout << (address != 7 ? "Enter the Number" : "Number of numbers entered") 
			<< std::endl;

		simpletron.perform(SML::READ, address);

		if (address < 7) { simpletron.perform(SML::ADD, address); }

		else if (address == 7) { 
			simpletron.perform(SML::DIVIDE, address); 
		
			simpletron.perform(SML::STORE, address);

			std::cout << "Average:\n";
			simpletron.perform(SML::WRITE, address);
		}

		else { simpletron.perform(SML::LOAD, address); }

	}
	std::cout << std::endl;
	simpletron.reset();

// C)

	std::cout << "\nC)\n\n";

	int n_numbers;
	std::cout << "Numbers to be entered: ",
		std::cin >> n_numbers;

	std::cout << std::endl;

	for (; n_numbers; n_numbers--) {
		std::cout << "Enter the Number\n";
		simpletron.perform(SML::READ, n_numbers);
	}

	std::cout << "The largest number in memory is " << simpletron.max();

	return 0;
}


bool isNumber(const std::string& str) {

	std::regex pattern{ "[0-9]+" };
	return std::regex_match(str, pattern);
}


