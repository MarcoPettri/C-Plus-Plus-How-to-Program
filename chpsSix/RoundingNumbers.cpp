// 6.13 Exercise: Rounding Numbers 
 /*
	An application of function floor is rounding a value to the nearest integer.The statement
			y = floor(x + 0.5);
	rounds the number x to the nearest integer and assigns the result to y.Write a program that reads
	several numbers and uses the preceding statement to round each of these numbers to the nearest
	integer.For each number processed, print both the original number and the rounded number.
*/

#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<regex>

int RoundingNumbers() {

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
	
	for (const double& x : numbers) {
		std::cout << x << " = "
			<< std::floor( x + 0.5)  
			<< std::endl;
	}

	return 0;
}