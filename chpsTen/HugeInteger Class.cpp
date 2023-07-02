// Exercise 10.9: HugeInteger Class

/*
		A machine with 32-bit integers can represent integers in the range of
		approximately –2 billion to +2 billion. This fixed-size restriction is rarely troublesome, but there are
		applications in which we would like to be able to use a much wider range of integers. This is what
		C++ was built to do, namely, create powerful new data types. Consider class HugeInteger of Exercise 9.14,
		then: 
			a) Allow the constructor to accept an integer or string.
			b) overload all the member functions,
				including "output" member function by "<<" insertion operator.
			c) Overload the + addition operator.
			d) Overload the - subtraction operator.
			e) Overload all the relational and equality operators.

			
*/


#include "HugeInteger.h"


int Huge_Integer_Class() {


	HugeInteger first{ 4685 };
	HugeInteger second{ "3737377373737373773737373737737317" };
	HugeInteger third{ "18383838838383838838383838383883838301" };
	HugeInteger fourth;


	// Test Output
	std::cout << "First HugeInteger: " << first;

	std::cout << "Second HugeInteger: " << second;

	std::cout << "Third HugeInteger: " << third;

	std::cout << "Fourth HugeInteger: " << fourth;

	//  test assignment operator and copy constructor provided by the compiler 
	fourth = first;
	HugeInteger fifth{ second };


	std::cout << "\nUpdated fourth HugeInteger: " << fourth << std::endl;
	std::cout << "Fifth HugeInteger: " << fifth << std::endl;

	// Test Predicate Functions //

	std::cout << "\nFirst  > Second:   " << std::boolalpha << (first > second) << std::endl;
	std::cout << "Second >= First:   " << (second >= first) << std::endl;
	std::cout << "Third  < Fourth:   " << (third < fourth) << std::endl;
	std::cout << "Third  <= Second:  " << (third <= second) << std::endl;
	std::cout << "Fourth == First:   " << (fourth == first) << std::endl;
	std::cout << "Third  != Second:  " << (third != second) << std::endl;
	std::cout << "First  is Zero:    " << first.isZero() << std::endl;

	//Test Operations //
	std::cout << "\nFourth + Fifth = ";
	fourth + fifth;

	std::cout << "Fourth + 91,331 = ";
	fourth + 91'331;	

	std::cout << "Fourth + \"3,341\" = ";
	fourth + "3341";


	std::cout << "\nThird  - Second = ";
	third - second;	

	std::cout << "Second - \"12,249,997\" = ";
	second - 12'249'997;

	std::cout << "First  - 7,324 = ";
	first - 7'324;	


	return 0;
}