// Exercise 9.14: HugeInteger Class

/*

		Create a class HugeInteger that uses a 40-element vector of digits to
		store integers as large as 40 digits each. Provide member functions input, output, add and subtract.
		For comparing HugeInteger objects, provide functions isEqualTo, isNotEqualTo, isGreaterThan,
		isLessThan, isGreaterThanOrEqualTo and isLessThanOrEqualTo—each of these is a "predicate"
		function that simply returns true if the relationship holds between the two HugeIntegers and re-
		turns false if the relationship does not hold. Also, provide a predicate function isZero. If you feel
		ambitious, provide member functions multiply, divide and remainder. In Chapter 10, you'll learn
		how to overload input, output, arithmetic, equality and relational operators so that you can write
		expressions containing HugeInteger objects, rather than explicitly calling member functions.
*/

#include "HugeInteger.h"


int Huge_Integer() {


	HugeInteger first{ "4685" };
	HugeInteger second{ "3737377373737373773737373737737317" };
	HugeInteger third{ "18383838838383838838383838383883838301" };
	HugeInteger fourth{ "154" };


	// Test Output
	std::cout << "first HugeInteger: ";
	first.output();

	std::cout << "second HugeInteger: ";
	second.output();

	std::cout << "third HugeInteger: ";
	third.output();

	std::cout << "fourth HugeInteger: ";
	fourth.output();

// Test input
	fourth.input("803");
	
	std::cout << "\nUpdated fourth HugeInteger: ";
	fourth.output();

// Test Predicate Functions

	std::cout << "\nFirst > Second: " << std::boolalpha << first.isGreaterThan(second) << std::endl;
	std::cout << "Second >= First: " << second.isGreaterThanOrEqualTo(first) << std::endl;
	std::cout << "Third < Fourth : " << third.isLessThan(fourth) << std::endl;
	std::cout << "Third <= Second : " << third.isLessThanOrEqualTo(second) << std::endl;
	std::cout << "Fourth == First: " << fourth.isEqualTo(first) << std::endl;
	std::cout << "Third != Second: " << third.isNotEqualTo(second) << std::endl;
	std::cout << "First is Zero: " << first.isZero() <<  std::endl;

//Test Operations
	std::cout << "\nFourth + first = ";
	fourth.add(first);

	std::cout << "\nThird - second = ";
	third.subtract(second);

    return 0;
}