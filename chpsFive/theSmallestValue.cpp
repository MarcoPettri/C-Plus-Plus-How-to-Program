// 4.11 Exercise : Find The Smallest Value
// Write an application that finds the smallest of several integers.
//Assume that the first value read specifies the number of values to input from the user.

#include<iostream>

int TheSmallestValue() {

	int counter{ 0 };
	int smallest{ 0 };

	std::cout << "Enter the quantity of numbers to be evaluated: ",
		std::cin >> counter;

	std::cout << "Enter the number: ",
		std::cin >> smallest;

	for (; counter > 1; --counter) {
		 
		int number;
		std::cout << "Enter the number: ",
			std::cin >> number;

		if (number < smallest) {
			smallest = number;
		}
	}

	std::cout << "The smallest value entered is: " << smallest;

	system("pause>0");

	return 0;
}