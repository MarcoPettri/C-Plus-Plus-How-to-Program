// 6.20 Exercise: Factors
/*
	Write a function isFactor that determines for a pair of integers whether the second is a factor of the first.
	The function should take two integer arguments and return true if the second is a factor of the first, 
	false otherwise.Use this function in a program that inputs a series of pairs of integers.
*/

inline bool isFactors(int& firtsNumber, int& secondNumber) {
	return (secondNumber % firtsNumber == 0 ? true : false);
}

#include<iostream>
#include<vector>
#include<iomanip>

int Factors() {

	std::vector<int> numbers;
	int number;

	std::cout << "Enter the first number (-1 to exit): ",
		std::cin >> number;

	while (number != -1) {
		
		numbers.push_back(number);
		
		std::cout << "Enter the second number: ",
			std::cin >> number;
		numbers.push_back(number);

		std::cout << "\nEnter the first number (-1 to exit): ",
			std::cin >> number;
	}
	std::cout << std::boolalpha << std::endl;

	if (2 <= numbers.size()) {

		for (int index{ 0 }; index < numbers.size() -1; index++) {
		
			int first{ numbers.at(index) };
			index++;
			int second{ numbers.at(index) };

			std::cout << second << " factor of the " << first 
				<< " ?: " << isFactors(first, second) << std::endl;
		}
	
	}
	return 0;
}