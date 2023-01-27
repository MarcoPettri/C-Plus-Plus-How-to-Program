//4.35 Exercise: Factorial and Napier's power series 

#include <iostream>
#include<iomanip>
using std::cout; using std::cin;
using std::endl; using std::setprecision;
using std::fixed;

int factorial(unsigned int number) {

	unsigned int factor{ 1 };

	while (number > 0) {

		factor *= number;
		--number;
	}
	return factor;
}

double constant_e(unsigned int term, unsigned int x = 1 ) {

	double napierCostant{ 1.0 };


	while (term > 0) {
	
		int factor{ 1};

		for (int i = 1; i <= term; i++) {
			factor *= i;
		}
	
		napierCostant += 1 / static_cast<double>(factor);

		--term;
	}

	return pow(napierCostant, x);
}

int program() {

	unsigned int number{ 0 };

	cout << setprecision(4) << fixed;

	cout << "Enter the number: ",
		cin >> number;


	cout << "his factorial is " << factorial(number) << endl;

	cout << "Enter the desired accuracy of 'e': ",
		cin >> number;

	cout << "constant 'e' = " << constant_e(number) << endl;
	
	cout << "Enter the desired precision of 'e' raised to power of 'x': ",
		cin >> number;

	cout << constant_e(number, number);

	return 0;
}