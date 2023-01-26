//5.30 Exercise: DollarAmount Constructor with Two Parameters
/*
	Enhance class DollarAmount(Fig. 5.8) with a constructor that receives two parameters representing 
	the whole number of dollars and the whole number of cents.Use these to calculate and store
	in the data member amount the total number of pennies. Test the class with your new constructor.
*/

// Test class DollarAmount with constructor two Parameters.
#include <iostream>
#include <iomanip>
#include <string>
#include "DollarAmount.h"

int testClassAmount1() {
    DollarAmount d1{ 123, 45 }; // $123.45
    DollarAmount d2{ 15, 76 }; // $15.76

    std::cout << "After adding d2 (" << d2.toString() << ") into d1 ("
        << d1.toString() << "), d1 = ";
    d1.add(d2); // modifies object d1
    std::cout << d1.toString() << "\n";

    std::cout << "After subtracting d2 (" << d2.toString() << ") from d1 ("
        << d1.toString() << "), d1 = ";
    d1.subtract(d2); // modifies object d1
    std::cout << d1.toString() << "\n";

    std::cout << "After subtracting d1 (" << d1.toString() << ") from d2 ("
        << d2.toString() << "), d2 = ";
    d2.subtract(d1); // modifies object d2
    std::cout << d2.toString() << "\n\n";

    std::cout << "Enter integer interest rate and divisor. For example:\n"
        << "for     2%, enter:    2 100\n"
        << "for   2.3%, enter:   23 1000\n"
        << "for  2.37%, enter:  237 10000\n"
        << "for 2.375%, enter: 2375 100000\n> ";
    int rate; // whole-number interest rate
    int divisor; // divisor for rate 
    std::cin >> rate >> divisor;

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