// Exercise 13.12: Displaying numbers in different bases

/*

			Write a program that displays a range of numbers in decimal, octal, and hexadecimal. 
		Ask the user for a lower and upper limit, both inclusive, and display 
		the numbers in three columns: decimal, octal, and hexadecimal
*/

#include<iostream>
#include<iomanip>

int Displaying_Numbers_In_Different_Bases()
{
	int lower;
	int upper;

	std::cout << "Enter the lower and upper limit: ",
		std::cin >> lower >> upper;

	std::cout << "Decimal" 
		<< "\t\tOctal" 
		<< "\t\tHexadecimal" <<  std::endl;


	for (; lower != upper; ++lower) {

		std::cout << lower << "\t\t"
			<< std::oct << lower << "\t\t"
			<< std::hex << lower << std::dec << std::endl;
	}

	return 0;
}