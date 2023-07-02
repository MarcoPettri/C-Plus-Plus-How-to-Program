//Dollar Amount Class.cpp

// Exercise 10.12: DollarAmount Class Enhancement
// Exercise 10.13: DollarAmount Class Enhancement

/*
        Exercise 10.12:
            Enhance class DollarAmount from Exercise 5.32 with overloaded addition (+), 
             subtraction (-), multiplication (*) and division (/) operators.

       Exercise 10.13:
            Enhance class DollarAmount from Exercise 10.12 to make the overloaded addition, 
             subtraction and multiplication operators commutative.

*/



#include <iomanip>

#include "DollarAmount.h"

int Dollar_Amount_Class() {

    DollarAmount d1{ 123, 45 }; // $123.45
    DollarAmount d2{ 15, 76 }; // $15.76
    DollarAmount d3{ 144, 33 }; // $144.33

 // Testing Arithmetic and Assignment Operators //

    std::cout << "d1 (" << d1 << ") + d2 ("
        << d2 << "), d1 = " << d1 + d2 << std::endl;

    d1 += d2; // modifies d1

    std::cout << d1 << "\n\n";


    std::cout << "d3 (" << d3 << ") + 12.98"
        << ", d3 = " << d3 + 12.98 << std::endl;

    d3 += 12.98; // modifies d3

    std::cout << d3 << "\n\n";

    std::cout << "d1 (" << d1 << ") - d2 ("
        << d2 << "), d1 = " << d1 - d2 << std::endl;

    d1 -= d2; // modifies object d1

    std::cout << d1 << "\n\n";    
    
   
    std::cout << "d3 (" << d3 << ") - 34.32"
        << ", d3 = " << d3 - 34.32 << std::endl;

    d3 -= 34.32; // modifies object d3

    std::cout << d3 << "\n\n";

    std::cout << "d1  * d2 = " << d1 * d2 << std::endl;

    d1 *= d2; // modifies object d1
    std::cout << d1 << "\n\n";    
    
    std::cout << "d1 / 23.52 = " << d1  / 23.52 << std::endl;

    d1 /= 23.52;
    std::cout << d1 << "\n\n";

 // Testing addInterest Member function // 

    std::cout << "Enter integer interest rate and divisor. For example:\n"
        << "for     2%, enter:    2 100\n"
        << "for   2.3%, enter:   23 1000\n"
        << "for  2.37%, enter:  237 10000\n"
        << "for 2.375%, enter: 2375 100000\n> ";


    int rate; // whole-number interest rate
    int divisor; // divisor for rate 
    std::cin >> rate >> divisor;

    DollarAmount balance{ 1000, 00 }; // initial principal amount in pennies
    std::cout << "\nInitial balance: " << balance << std::endl;

    // display headers
    std::cout << "\nYear" << std::setw(30) << "Amount on deposit" << std::endl;

    // calculate amount on deposit for each of ten years
    for (unsigned int year{ 1 }; year <= 10; year++) {
        // increase balance by rate % (i.e., rate / divisor)
        balance.addInterest(rate, divisor);

        // display the year and the amount
        std::cout << std::setw(4) << year << std::setw(20) << balance << std::endl;
    }

    return 0;
}