//Exercise 17.x: Order of Exception Handlers
/*
		Write a program illustrating that the order of exception handlers is important. 
		The first matching handler is the one that executes. Attempt to compile and run
		your program two different ways to show that two different handlers execute with two different effects.

*/


#include<iostream>
#include<stdexcept>


class MyException : public std::runtime_error
{
public:
	MyException(const char* what_arg)
		: std::runtime_error{ what_arg } {}

};


int ORDER_OF_EXCEPTION_HANDLERS()
{

	try {

		std::cout << "First Exception" << std::endl;
		throw MyException("My Exception");
	}
	catch (const std::runtime_error&) {
		std::cout << "runtime_error base class" << std::endl;
	}
	catch (const MyException&) {
		std::cout << "MyException derived class" << std::endl;
	}	
		
	try {
		
		std::cout << "\nSecond Exception" << std::endl;
		throw MyException("My Exception");
	}
	catch (const MyException&) {
		std::cout << "MyException derived class" << std::endl;
	}	
	catch (const std::runtime_error&) {
		std::cout << "runtime_error base class" << std::endl;
	}


	return 0;
}