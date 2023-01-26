// 6.27 Exercise: Find the Minimum 
/*
	Write a program that inputs three double-precision, floating-point
	numbers and passes them to a function that returns the smallest number.
*/

#include<iostream>

double smallest(double& first, double& second, double& third);

int Minimum() {

	double one, two, three;

	std::cout << "Enter three decimal numbers separated by spaces: ",
		std::cin >> one >> two >> three;

	std::cout << "The smallest is: " << smallest(one, two, three);

	return 0;
}

double smallest(double& first, double& second, double& third) {

	double smallest{ first };

	if (second < smallest) {
		smallest = second;
	}
	if (third < smallest) {
		smallest = third;
	}

	return smallest;
}