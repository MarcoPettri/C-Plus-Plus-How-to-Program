// 6.21 Exercise: Multiple of 3
/*
	Write a program that inputs a series of integers and passes them one at a time
	to function isMultiple3, which uses the remainder operator to determine whether an integer is a
	multiple of 3. The function should take an integer argument and return true if the integer is a multiple
	of 3 and false otherwise

*/

#include<iostream>

inline bool isMultiple3(int& number) { return (number % 3 == 0 ? true : 3);}


int Multiple3() {

	int number;
	std::cout << std::boolalpha <<
		"Enter the number(-1 to exist): ",
		std::cin >> number;

	while (number != -1) {

		std::cout << isMultiple3(number) << std::endl 
			<< "Enter the number(-1 to exist): ",
				std::cin >> number;
	}

	return 0;
}