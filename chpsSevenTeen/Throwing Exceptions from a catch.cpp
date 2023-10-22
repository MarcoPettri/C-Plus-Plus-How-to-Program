// Exercise 17.x: Throwing Exceptions from a catch
/*

		Suppose a program throws an exception and the appropriate exception handler begins executing. 
		Now suppose that the exception handler itself throws the same exception.
		Does this create infinite recursion? Write a program to check your observation.

*/


#include<iostream>
#include<exception>

int THROWING_EXCEPTIONS_FROM_A_CATCH()
{

	try {
		throw std::exception{ "Exception inside of try block" };
	}
	catch (const std::exception& except) {
		std::cout << except.what() << " handled" << std::endl;
		throw std::exception{ "Exception inside of catch block"};
	}

	std::cout << "The programme is aborted. This is never executed" << std::endl;


	return 0;
}