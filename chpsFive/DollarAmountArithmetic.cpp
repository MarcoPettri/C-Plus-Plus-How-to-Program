// 5.33 Exercise: DollarAmount Arithmetic
/*	
		Enhance class DollarAmount from Exercise 5.30 with a divide member function that receives an int parameter, 
		divides the data member amount by that value and stores the result in the data member.
		Use rounding techniques similar to the addInterest member function.
		Test your new divide member function
*/

#include <iostream>
#include <iomanip>
#include "DollarAmount.h"


int DollarAmountArithmetic(){

	DollarAmount d1{ 124, 55 };
	DollarAmount d2{ 124, 55 };
	DollarAmount d3{ 124, 55 };

	std::cout << std::fixed << std::setprecision(2);
	std::cout << d1.toString() << " / 4 = " << 124.55 / 4   << std::endl;

	d1.divide(4);
	std::cout << "Rounded = " << d1.toString() << "\n\n";

	std::cout << d2.toString() << " / 5 = " << 124.55 / 5   << std::endl;
	d2.divide(5);
	std::cout << "Rounded = " << d2.toString() << "\n\n";

	std::cout << d3.toString() << " / 7 = " << 124.55 / 7   << std::endl;
	d3.divide(7);
	std::cout << "Rounded = " << d3.toString() << std::endl;

	return 0;
}