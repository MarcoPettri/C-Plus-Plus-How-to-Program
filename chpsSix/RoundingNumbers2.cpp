// Exercise 6.14 : Rounding Numbers 2

#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<regex>

void roundToInteger(const double& number);
void roundToTenths(const double& number);
void roundToHundredths(const double& number);
void roundToToushandths(const double& number);

int RoundingNumbers2() {


	std::vector<double> numbers;
	std::string number;

	std::cout << "Enter the numbers (press Ctrl+z to exit)"
		<< std::endl << ">>> ";
	std::regex pattern("[0-9\.0-9|0-9]+");

	while (std::cin >> number) {

		if (std::regex_match(number, pattern)) {

			numbers.push_back(stod(number));
			std::cout << ">>> ";
		}
		else {
			std::cout << "Error!" << std::endl << ">>> ";
		}
	}
	std::cout << std::setw(12)  << "Number \t"
		<< std::setw(10) << "\t integer \t"
		<< std::setw(10) << "\t tenths \t"
		<< std::setw(10) << "\t hundredth \t"
		<< std::setw(10) << "\t thousandth \t"
		<< std::endl;

	for (const double& x : numbers) {
		std::cout<< std::setw(10) << x 
			<< std::setw(22);
		roundToInteger(x);
		std::cout << std::setw(23);
		roundToTenths(x);
		std::cout << std::setw(27);
		roundToHundredths(x);
		std::cout << std::setw(25);
		roundToToushandths(x);
		std::cout << std::endl;
	}
	return 0;
}

void roundToInteger(const double& number) {
	std:: cout << int(std::floor(number + 0.5));
}
void roundToTenths(const double& number) {
	std::cout << std::fixed 
		<< std::setprecision(1)
		<< std::floor(number * 10 + 0.5) / 10;
}
void roundToHundredths(const double& number) {
	std::cout << std::fixed 
		<< std::setprecision(2)
		<< std::floor(number * 100 + 0.5) / 100;
}
void roundToToushandths(const double& number) {
	std::cout << std::fixed 
		<< std::setprecision(3)
		<< std::floor(number * 1'000 + 0.5) / 1000;
}
