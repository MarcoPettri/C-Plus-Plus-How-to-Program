// 6.24 Exercise: Separate Digits:
/*
	Write program segments that accomplish each of the following:

	a) Calculate the integer part of the quotient when integer a is divided by integer b.
	b) Calculate the integer remainder when integer a is divided by integer b.
	c) Use the program pieces developed in (a) and (b) to write a function that inputs an integer
	between 1 and 32767 and prints it as a series of digits, each pair of which is separated by two spaces. 
	For example, the integer 4562 should print as follows:
															4  5  6  2

*/
#include<iostream>
#include<string>
int SeparateDigits() {


	int qoutient{ 132 / 5 };
	int remainder{ 132 % 5 };

	std::string str = std::to_string(qoutient) + std::to_string(remainder);

	for (auto digits : str) {
		std::cout << digits << "  ";
	}
	return 0;
}