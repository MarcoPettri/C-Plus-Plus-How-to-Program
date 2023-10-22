// Exercise 17.x: Placement of exception handlers
/*
	What happens when you place a catch handler that catches
	an object of a base class before a catch that catches an exception of a derived class from that base class?
*/

#include<iostream>
#include<stdexcept>


class MyException : public std::runtime_error
{
public:
	MyException(const char* what_arg)
		: std::runtime_error{ what_arg } {}

};


int PLACEMENT_OF_EXCEPTION_HANDLERS()
{

	try {
		throw MyException("My Exception");
	}
	catch (const std::runtime_error&) {
		std::cout << "This line always is executed" << std::endl;
	}
	catch (const MyException&) {
		std::cout << "This line never is executed" << std::endl;
	}

	return 0;
}