// Exercise 17.x: Exception Handling and Program Control
/*
		Improve the Quadratic class of Exercise 9.5 by
		incorporating exceptions. Define an exception class called NoRealRootException and make the
		solve member function throw this exception when a quadratic equation does not have real roots.
		Write a test program to demonstrate the functionality of the improved Quadratic class.
*/

#include<iostream>
#include "Quadratic.h"
#include "NoRealRootException.h"

int EXCEPTION_HANDLING_AND_PROGRAM_CONTROL()
{	

	Quadratic equation1{ 9.34, 10.65, 52.5 };
	Quadratic equation2{ 0, 5, 6 };

	std::cout << "Equation 1: " << equation1.toString() << std::endl;
	std::cout << "Equation 2: " << equation2.toString() << std::endl;

	try {
		std::cout << "\nRoot of Equation 2:\n" << equation2.solve() << std::endl;

		std::cout << "\nRoot of Equation 1:\n";
		std::cout << equation1.solve() << std::endl;

	}
	catch (const NoRealRootException& messg) {

		std::cout << messg.what() << std::endl;
	}

	return 0;
}