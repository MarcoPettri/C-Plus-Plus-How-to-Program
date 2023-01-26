// 4.19 Exercise: Calculating the value of PI
/*
	Print a table that shows the value of PI approximated by computing the first 200,000 terms of this
	series. How many terms do you have to use before you first get a value that begins with 3.14159?.
*/

#include<iostream>
#include<locale>

int CalculatingTheValueOfPi() {

	double pi{ 4 };
	unsigned int term{ 0 };

	for (unsigned i{ 1 }; i <= 200'000; i++) {

		if (i % 2 == 0) {

			pi += 4.0 / (1.0 + 2.0 * i);
		}
		else {

			pi -= 4.0 / (1.0 + 2.0 * i);
		}

		if (0 == term) {
			if (static_cast<int>(pi * 1'00000) == 314159) {
				term = i;
			}
		}
	}

	std::cout.imbue(std::locale(""));
	std::cout << "The approximate value of PI calculating the first 200,000 terms of this series is: " 
		<< pi << std::endl 
		<< "Term at which pi has value 3.14159 is: " << term;

	return 0;
}