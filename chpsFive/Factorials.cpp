//5.13 Exercise: Factorials
 /* Factorials are used frequently in probability problems.The factorial of a positive
 integer n(written n!and pronounced “n factorial”) is equal to the product of the positive integers from
 1 to n.Write an application that calculates the factorials of 1 through 20. Use type long.Display the
 results in tabular format.What difficulty might prevent you from calculating the factorial of 100? */


#include <iostream>
#include <iomanip>
#include <locale>

int factorials() {

	long mul = 1;

	std::cout.imbue(std::locale(""));

	std::cout << "Number(n)" << std::setw(47) << "n!" << std::endl;

	for (int i{ 1 }; i <= 20; i++) {

		// Calculate Factorial. N! = N( N -1 )!
		mul *= i;

		std::cout << std::setw(6) << i
			<< std::setw(50) << mul << std::endl;
	}

	return 0;
}