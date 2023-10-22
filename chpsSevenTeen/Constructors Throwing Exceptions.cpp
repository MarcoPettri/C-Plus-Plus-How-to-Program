// Exercise 17.x: Constructors Throwing Exceptions
/*
	Write a program that shows a constructor passing information 
	about constructor failure to an exception handler after a try block.
*/


#include<iostream>
#include<stdexcept>

class MyClass {

public:
	explicit MyClass(int arg) {
		if (not arg) {
			throw std::invalid_argument("Invalid argument: 0");
		}
		else {
			std::cout << "Valid Argument: " << arg << std::endl;
		}
	}
};

int CONSTRUCTORS_THROWING_EXCEPTIONS()
{

	try {
		MyClass test1{ 23 };

		// throw a exception //
		MyClass test2{ 0 };
		
	}
	catch (const std::invalid_argument& what_arg) {
		std::cout << what_arg.what() << std::endl;
	}
	return 0;
}