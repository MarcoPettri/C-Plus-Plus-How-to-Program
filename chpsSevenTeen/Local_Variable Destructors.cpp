// Exerxcise 17.x: Local-Variable Destructors
/*
		Write a program illustrating that all destructors for objects
		constructed in a block are called before an exception is thrown from that block.

*/

#include<iostream>

class Class1
{
public:
	Class1() { }

	~Class1() {
		std::cout << "destructor class 1" << std::endl;
	}

};

class Class2
{
public:
	Class2() { }

	~Class2() {
		std::cout << "destructor class 2" << std::endl;
	}

};

class Class3
{
public:
	Class3() { }

	~Class3() {
		std::cout << "destructor class 3" << std::endl;
	}

};

int LOCAL_VARIABLE_DESTRUCTORS()
{

	try {
		Class1 myClass1{};
		Class2 myClass2{};
		Class3 myClass3{};

		std::cout << "Before throw exception\n" << std::endl;

		throw true;
	}
	catch (...) {
		std::cout << "\nAfter Throw exception" << std::endl;
	}

	return 0;
}