// Exercise 22.x: Displaying Characters for Given ASCII Codes
/*

		Write a program that inputs an ASCII code and prints the corresponding character. 
		Modify this program so that it generates all possible three-digit codes 
		in the range 000–255 and attempts to print the corresponding characters. 
		What happens when this program is run?
*/

#include<iostream>

int DISPLAYING_CHARACTERS_FOR_GIVEN_ASCII_CODES() {

	unsigned code;

	std::cout << "ASCII code: ",
		std::cin >> code;


	std::cout << "Characters: " << static_cast<char>(code) << std::endl;


	std::cout << "\nASCII Table\n";
	 
	for (unsigned i{ 0 }; i < 256; ++i) {

		std::cout << i << ": " << static_cast<char>(i) << "\t";

		if (not (i % 10) && i) { std::cout << std::endl; }

	}
	return 0;
}