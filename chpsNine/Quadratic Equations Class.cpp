// Exercise 9.5 : Quadratic Equations Class

/*

			Create a class called Quadratic for performing arithmetic on
			and solving quadratic equations. A quadratic equation is an equation of the form

								ax^2 + bx + c = 0

			where a != 0. Use double variables to represent the values of a, b, and c and provide a constructor
			that enables objects of this class to be initialized when they are created. Give default values of a = 1,
			b = 0, and c = 0. Create a char variable called variable to represent the variable used in the equation
			and give it a default value of x. The constructor should not allow the value of a to be 0. If 0 is given,
			assign 1 to a. Provide public member functions that perform the following tasks.

						a) add—adds two Quadratic equations by adding the corresponding values of a, b, and c.
							The function takes another object of type Quadratic as its parameter and adds it to the
							calling object.

						b) subtract—subtracts two Quadratic equations by subtracting corresponding values of
							a, b, and c. The function takes another object of type Quadratic as its parameter and
							subtracts it from the calling object.

						c) toString—returns a string representation of a quadratic equation in the form ax^2 + bx +
							c = 0 using the actual values of the data members.

						d) solve—solves a quadratic equation using Bhaskara's formula,
							and displays the solutions if (b^2 -4ac) is greater than 0. Otherwise, it displays "No Real
							Roots."
			Write a driver program to test the functionality of the Quadratic class

*/

#include<iostream>
#include "Quadratic.h"

int QuadraticEquationsClass()
{

	Quadratic equation1{ 9.34, 10.65, 52.5 };
	Quadratic equation2{ 0, 5, 6 };

// Testing getters functions
	std::cout << "Equation 1: " 
		<< equation1.toString() << "\n\n";

	std::cout <<"Quadratic Coefficient: " 
		<< equation1.getQC() << "\n\n";

	std::cout << "Linear Coefficient: " 
		<<  equation1.getLC() << "\n\n";

	std::cout <<  "Constant Coefficient: " 
		<< equation1.getConstant() << "\n\n";

	std::cout << "Solve equation 1: \n"
		<< equation1.solve() << "\n\n";

	std::cout << "Equation 2: "
		<< equation2.toString() << "\n\n";

	std::cout << "Solve equation 2: \n"
		<< equation2.solve() << "\n\n";

// Testing setters functions 

	equation1.setCoefficients(25, 20, 4);
	equation2.setLC(0);

// Testing Operations

	std::cout << "Equation 1: "
		<< equation1.toString() << "\n\n";
	std::cout << "Equation 2: "
		<< equation2.toString() << "\n\n";

	std::cout << "Equation 1 + Equation 2: \n";

	equation1.add(equation2);

	std::cout << equation1.toString() << "\n\n";

	equation1.setCoefficients(2.7182, 94.312, -4);

	std::cout << "Equation 3 : "
		<< equation1.toString() << "\n\n";

	std::cout << "Equation 3 - Equation 2: \n";

	equation1.subtract(equation2);

	std::cout << equation1.toString() << std::endl;


	return 0;
}