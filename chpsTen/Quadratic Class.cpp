// Exercise 10.10: Enhanced Quadratic Class
/*

		Enhance the Quadratic class of Exercise 9.5 by introducing
		three overloaded operators as follows:

			a) Addition (+): adds two Quadratic objects together.
			b) Subtraction (-): subtracts one Quadratic object from another.
			c) Output operator (<<): displays a Quadratic equation in the form ax^2 + bx + c = 0.

		Write a test program to demonstrate the capabilities of the enhanced Quadratic class
*/	

#include "Quadratic.h"
#include <iostream>

int Quadratic_Class()
{

	Quadratic equation1{ 9.34, 10.65, 52.5 };
	Quadratic equation2{ 0, 5, 6 };

// Testing getters functions //

	std::cout << "Equation 1 --> " << equation1 << std::endl;

	std::cout << "Quadratic Coefficient: "<< equation1.getQC() << std::endl;

	std::cout << "Linear Coefficient: "<< equation1.getLC() << std::endl;

	std::cout << "Constant Coefficient: " << equation1.getConstant() << std::endl;

	std::cout << "Variable: " << equation1.getVar() << std::endl;

	std::cout << "\nSolve equation 1: \n" << equation1.solve() << std::endl;

	std::cout << "\nEquation 2 --> "<< equation2 << std::endl;

	std::cout << "Solve equation 2: \n" << equation2.solve() << std::endl;

// Testing setters functions  //

	equation1.setCoefficients(25, 20, 4);
	equation2.setLC(0);

// Testing Operations // 

	std::cout << "\nEquation 1 --> " << equation1 
		<< "Equation 2 --> "<< equation2 << std::endl;

	std::cout << "Equation 1 + Equation 2: \n" << equation1 + equation2;


	equation1.setCoefficients(2.7182, 94.312, -4);

	std::cout << "\nEquation 3 --> " << equation1 << std::endl;

	std::cout << "Equation 3 - Equation 2: \n" << equation1 - equation2;

	return 0;
}