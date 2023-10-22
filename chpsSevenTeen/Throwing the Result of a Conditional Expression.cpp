// Exercise 17.x: Throwing the Result of a Conditional Expression
/*
		Throw the result of a conditional expression that returns either a double or an int.
		Provide an int catch handler and a double catch handler. 
		Show that only the double catch handler executes, regardless of whether the int or the
		double is returned.

*/

#include<iostream>

int THROWING_THE_RESULT_OF_A_CONDITIONAL_EXPRESSION()
{
	try {
		bool condition{ false };
		throw (condition ? 3.23 : 11);
	}
	catch (const int& k) {
		std::cout << "Catch int value: " << k << std::endl;
	}
	catch (const double& n) {
		std::cout << "Catch double value: " << n << std::endl;
	}	

	try {
		bool condition{ true };
		throw (condition ? 3.23 : 11);
	}
	catch (const int& k) {
		std::cout << "Catch int value: " << k << std::endl;
	}
	catch (const double& n) {
		std::cout << "Catch double value: " << n << std::endl;
	}
	
	return 0;
}