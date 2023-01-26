// Exercise 5.32: DollarAmount with Banker’s Rounding

/*
	The DollarAmount class’s addInterest member
	function uses the biased half - up rounding technique in which fractional amounts of .1, .2, .3 and .4
	round down, and .5, .6, .7, .8 and .9 round up.In this technique, four values round down and five
	round up.Banker’s rounding fixes this problem by rounding .5 to the nearest even integer—e.g.,
	0.5 rounds to 0, 1.5 and 2.5 round to 2, 3.5 and 4.5 round to 4, etc.Enhance class DollarAmount
	from Exercise 5.31 by reimplementing addInterest to use banker’s rounding,
	then retest the compound-interest program.
*/

#include<iostream>
#include<iomanip>
#include"DollarAmountTwo.h"

int Banker_sRounding() {

	int8_t rate; // whole-number interest rate
	int8_t divisor; // divisor for rate 

	std::cout << "Enter integer interest rate and divisor. For example:\n"
		<< "for     2%, enter:    2 100\n"
		<< "for   2.3%, enter:   23 1000\n"
		<< "for  2.37%, enter:  237 10000\n"
		<< "for 2.375%, enter: 2375 100000\n> ";

	std:: cin >> rate >> divisor;

	DollarAmount balance{ 1000, 00 }; // initial principal amount in pennies
	std::cout << "\nInitial balance: " << balance.toString() << std::endl;

	// display headers
	std::cout << "\nYear" << std::setw(20) << "Amount on deposit" << std::endl;

	// calculate amount on deposit for each of ten years
	for (unsigned int year{ 1 }; year <= 10; year++) {
		// increase balance by rate % (i.e., rate / divisor)
		balance.addInterest(rate, divisor);

		// display the year and the amount
		std::cout << std::setw(4) << year << std::setw(20) << balance.toString() << std::endl;
	}

	return 0;
}

