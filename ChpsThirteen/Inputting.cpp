// Exercise 13.7: Inputting Decimal, Octal and Hexadecimal Values
/*
			 Write a program to test the inputting of integer values in decimal, octaland hexadecimal formats.
		Output each integer read by the program in all three formats.Test the program with the following input data : 10, 010, 0x10.
*/


#include<iostream>

int Inputting()
{
	int number;
	std::ios_base::fmtflags defualt_input{ std::cin.flags() };


	std::cout << "Enter the number (EOF to exit): ";
	
	std::cin.unsetf(std::ios::dec);
	std::cin.unsetf(std::ios::hex);
	std::cin.unsetf(std::ios::oct);

	while (std::cin >> number) {

		std::cout << "Decimal: " << number << '\n'
			<< "Octal: " << std::oct << number << '\n'
			<< "Hexa: " << std::hex << number << std::dec << std::endl;

		std::cout << "Enter the number (EOF to exit): ";

	}

	std::cin.flags(defualt_input);

	return 0;
}