// Exercise 5.33: DollarAmount with dollars and cents Data Members

/*
	Reimplement class DollarAmount from Exercise 5.32 to store data members dollars and cents, rather than amount. 
	Modify the body of each constructor and member function appropriately 
	to manipulate the dollars and cents data members
*/

#include<iostream>
#include "DollarAmountTwo.h"

int DollarAmountFour() {
	DollarAmount d1{ 55, 12 };
	DollarAmount d2{ 103, 66 };

	std::cout << "Account 1: " << d1.toString() << std::endl
		<< "Account 2: " << d2.toString() << std::endl;

	d1.substract(d2);
	std::cout << "Account 1 - Account 2 = " << d1.toString();

	return 0;
}