//Exercise 13.6: Write C++ Statements
/*
			Write a statement for each of the following:
				a) Print integer 40000 left justified in a 15-digit field.
				b) Read a string into character array variable state.
				c) Print 200 with and without a sign.
				d) Print the decimal value 100 in hexadecimal form preceded by 0x.
				e) Read characters into array charArray until the character 'p' is encountered, 
					up to a limit of 10 characters (including the terminating null character). 
					Extract the delimiter from the input stream, and discard it.
				f) Print 1.234 in a 9-digit field with preceding zeros


*/

#include<iostream>
#include<iomanip>


int Write_C_Plus_Plus_Statements()
{
//	(a)

	std::cout << std::left << std::setw(15) << 40'000 << std::endl;

//

// (b)
	const int SIZE{ 10 };
	char state[SIZE];


	std::cout << "Enter the string: ";
	std::cin.get(state, SIZE, '\n'); // cin.get does not discard the stream delimiter
	std::cout << state << std::endl;
	
//

// (c)
	std::cout << 200 << ", " << std::showpos << 200;
	std::cout <<  std::noshowpos << std::endl; // showpos is a sticky manipulators

	
// (d)
	std::cout << std::showbase << std::hex << 100;
	std::cout << std::noshowbase << std::dec << std::endl; // showbase and hex are sticky manipulators


// (e)

	char charArray[SIZE];

	std::cin.getline(charArray, SIZE, 'p'); // cin.getline discards the stream delimiter
	std::cout << charArray << std::endl;

//

// (f)
	std::cout.precision(9);
	std::cout << std::showpoint << 1.234;

//

	return 0;
}