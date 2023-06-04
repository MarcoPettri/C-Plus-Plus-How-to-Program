// Exercise 9.6: Rational Class

/*
		Create a class called Rational for performing arithmetic with fractions.
		 Write a program to test your class. Use integer variables to represent the private data of the class—
		the numerator and the denominator. Provide a constructor that enables an object of this class to be
		initialized when it's declared. The constructor should contain default values in case no initializers
		are provided and should store the fraction in reduced form. For example, the fraction
								
									2/4

		would be stored in the object as 1 in the numerator and 2 in the denominator. Provide public
		 member functions that perform each of the following tasks:

			a) add—Adds two Rational numbers. The result should be stored in reduced form.
			b) subtract—Subtracts two Rational numbers. Store the result in reduced form.
			c) multiply—Multiplies two Rational numbers. Store the result in reduced form.
			d) divide—Divides two Rational numbers. The result should be stored in reduced form.
			e) toRationalString—Returns a string representation of a Rational number in the form
				a/b, where a is the numerator and b is the denominator.
			f) toDouble—Returns the Rational number as a double
						
*/

#include<iostream>
#include "Rational.h"

int RationalClass()
{

	Rational number1{ 15, 30 };
	Rational number2{ 25, 13 };
	Rational number3{ 5, 3 };
	Rational number4{ 54, 12 };

	std::cout << "Rational Numbers:" << std::endl;
	std::cout << number1.toRationalString() << std::endl;
	std::cout << number2.toRationalString() << std::endl;
	

// Testing add member function

	std::cout << number1.toRationalString() << " + " 
		<< number2.toRationalString() << " = ";	

	number1.add(number2);
	std::cout << number1.toRationalString() << std::endl;

// Testing multiply member function


	std::cout << number2.toRationalString() << " * " 
		<< number3.toRationalString() << " = ";
	
	number2.multiply(number3);

	std::cout << number2.toRationalString() << std::endl;

// Testing divide member function

	std::cout << number3.toRationalString() << " / "
		<< number1.toRationalString() << " = ";

	number3.divide(number1);

	std::cout << number3.toRationalString() << std::endl;

// Testing subtract member function
	std::cout << number4.toRationalString() << " - "
		<< number2.toRationalString() << " = ";

	number4.subtract(number2);

	std::cout << number4.toRationalString() << std::endl;

// Testing toDouble member function 

	std::cout << number1.toRationalString() << " = " 
		<< number1.toDouble() << std::endl;


	return 0;
}