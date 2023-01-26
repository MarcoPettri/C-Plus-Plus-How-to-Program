//5.29 Exercise: Peter Minuit Problem

/*
	Legend has it that, in 1626, Peter Minuit purchased Manhattan
	Island for $24.00 in barter. Did he make a good investment? To answer this question, modify the
	compound-interest program of Fig. 5.6 to begin with a principal of $24.00 and to calculate the
	amount of interest on deposit if that money had been kept on deposit until this year (e.g., 390 years
	through 2016). Place the for loop that performs the compound-interest calculation in an outer for
	loop that varies the interest rate from 5% to 10% to observe the wonders of compound interest.
*/

#include<iostream>

#include <iomanip>
#include<cmath>
#include<locale>

int PeterMinuitProblem() {

	// Set floating-point number format
	std::cout << std::fixed << std::setprecision(2);
	std::cout.imbue(std::locale(""));

	double principal{ 24.00 }; // initial amount before 

	// Calculate amount on deposit for each of ten years
	for (unsigned int i{ 5 }; i <= 10 ; i++){

		double rate{ static_cast<double>(i) / 100 };

		// Display headers
		std::cout << "Initial Principal:  " << principal << std::endl;
		std::cout << "   Interest rate:    " << rate << std::endl;

		std::cout << "\nYear" << std::setw(40) << "Amount on deposit" << std::endl;

		for (unsigned int year{ 1 }; year <= 390; year++) {

			// Calculate amount on deposit at the end of the specified year 
			double amount = principal * std::pow(1.0 + rate, year);

			//display the year and the amount
			std::cout << std::setw(4) << year << std::setw(40) << amount << std::endl;
		}

		std::cout << std::endl;
	}
	return 0;
}