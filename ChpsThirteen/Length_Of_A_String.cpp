// Exercise 13.11: Length of a String
/*

			Write a program that inputs a string from the keyboard and determines
		the length of the string. Print the string in a field width that is twice the length of the string.
*/

#include<iostream>
#include<string>


int Length_Of_A_String()
{

	std::string string;

	std::cout << "Enter a string: ";
	std::getline(std::cin, string);

	std::cout.width(string.length() * 2);

	std::cout << string;


	return 0;
}