// Exercise 13.16: Complex Class
/*


		Write a program that accomplishes each of the following:

			a) Create a user-defined class Complex that contains the private integer data members real
			and imaginary and declares stream insertion and stream extraction overloaded operator
			functions as friends of the class.

			b) Define the stream insertion and stream extraction operator functions. The stream ex-
			traction operator function should determine whether the data entered is valid, and, if
			not, it should set failbit to indicate improper input. The input should be of the form

									3 + 8i

			c) The values can be negative or positive, and it’s possible that one of the two values is not
			provided, in which case the appropriate data member should be set to 0. The stream
			insertion operator should not be able to display the point if an input error occurred. For
			negative imaginary values, a minus sign should be printed rather than a plus sign.
			d) Write a main function that tests input and output of user-defined class Complex, using
			the overloaded stream extraction and stream insertion operators.

*/

#include "Complex.h"

int Complex_Class()
{
	Complex comp;


	std::cout << "Enter the complex number in the form 3 + 8i or 3 + i: ",
		std::cin >> comp;

	std::cout << comp;

	return 0;
}