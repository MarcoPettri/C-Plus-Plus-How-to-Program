// 5.14 Exercise: Modified Compound-Interest Program
/* Modify the compound-interest application of Fig. 5.6 to repeat
its steps for interest rates of 5 %, 6 %, 7 %, 8 %, 9 % and 10 % .
Use a for loop to vary the interest rate */

#include <iostream>
#include <iomanip>
#include <cmath> // for pow function
using namespace std;

int CompoundInterestProgram() {
    // set floating-point number format
    cout << fixed << setprecision(2);

    double principal{ 1000.00 }; // initial amount before interest
    double rate{ 0.05 }; // interest rate

    for (int i{0}; i <= 5; i++) {

        cout << "\nInitial principal: " << principal << endl;
        cout << "    Interest rate:    " << rate << endl;

        // display headers
        cout << "\nYear" << setw(20) << "Amount on deposit" << endl;

        // calculate amount on deposit for each of ten years
        for (unsigned int year{ 1 }; year <= 10; year++) {

            // calculate amount on deposit at the end of the specified year
            double amount = principal * pow(1.0 + rate, year);

            // display the year and the amount
            cout << setw(4) << year << setw(20) << amount << endl;
        }
        rate += 0.01;
    }

    return 0;
}