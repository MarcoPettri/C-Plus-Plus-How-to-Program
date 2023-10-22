// Exercise 17.x: Member-Object Destructors
/*
	Write a program illustrating that member-object destructors
	are called for only those member objects that were constructed before an exception occurred.

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

int MEMBER_OBJECT_DESTRUCTORS()
{

	try {
		Class1 myClass1{};

		std::cout << "Before throw exception\n" << std::endl;

		throw true;

		Class2 myClass2{};
		Class3 myClass3{};
	}
	catch (...) {
		std::cout << "\nAfter Throw exception" << std::endl;
	}

	return 0;
}