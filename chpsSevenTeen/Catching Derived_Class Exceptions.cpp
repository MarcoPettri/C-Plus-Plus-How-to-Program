// Exercise 17.x: Catching Derived-Class Exceptions
/*
		Use inheritance to create various derived classes of
		runtime_error. Then show that a catch handler specifying the base class can catch derived-class
		exceptions
*/

#include<iostream>
#include<stdexcept>


class FirstException : public std::runtime_error
{
public:
	FirstException()
		: std::runtime_error{ "derived class: FirsException" } {}

};

class SecondException : public std::runtime_error
{
public:
	SecondException()
		:std::runtime_error{ "derived class: SecondException" } {}
};

class ThirdException : public std::runtime_error
{
public:

	ThirdException()
		:std::runtime_error{ "derived class: ThirdException" } {}
};

int CATCHING_DERIVED_CLASS_EXCEPTIONS()
{
	try {
		throw FirstException{};
	}
	catch (const std::runtime_error& except) {
		std::cout << except.what();
		std::cout << "\n\n" << std::endl;
	}

	try {
		throw SecondException{};
	}
	catch (const std::runtime_error& except) {

		std::cout << except.what();
		std::cout << "\n\n" << std::endl;
	}

	try {
		throw ThirdException{};
	}
	catch (const std::runtime_error& except) {

		std::cout << except.what();
		std::cout << "\n\n" << std::endl;
	}

	return 0;
}

