// Exercise 13.18: String-Terminating Null Character
/*

			Write a program to show that the getline and three-argument get istream member functions 
			both end the input string with a string-terminating null character. 
			Also, show that get leaves the delimiter character on the input stream, whereas getline 
			extracts the delimiter character and discards it.
*/

#include<iostream>


int String_Terminating_Null_Character()
{

	const int length{ 6 }; // "Strin\0".length() = 6, 

	// Test with get member-function //
	{
		char str[length];
		char delimiter;

		std::cout << "Enter \'String\': ",
			std::cin.get(str, length, 'g');

		std::cout << "str =  " << str << '\n';

		std::cout << "cin.get insert null-character in string: "
			<< std::boolalpha << (str[length - 1] == '\0') << '\n';

		// no waiting for input, 
		// cin inserts the character in the buffer into the variable delimiter
		std::cin >> delimiter;
		std::cout << "Delimiter left in buffer: " << delimiter;


	}
	std::cout << std::endl;
	std::cin.ignore();

	// Test with getline member-function //
	{
		char str[length];
		char delimiter;

		std::cout << "\nEnter \'String\': ",
			std::cin.getline(str, length, 'g');

		std::cout << "str =  " << str << '\n';

		std::cout << "cin.getline insert null-character in string: "
			<< std::boolalpha << (str[length - 1] == '\0') << '\n';

		//Waiting for input, no characters in buffer
		std::cin >> delimiter;
		std::cout << "Delimiter not left in buffer: " << delimiter;
	}

	std::cout << std::endl;



	return 0;
}

