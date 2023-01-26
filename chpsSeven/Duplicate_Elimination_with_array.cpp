// Exercise 7.13: Duplicate Elimination with array

/*
	Use a one-dimensional array to solve the following problem.
	Read in 20 numbers, each of which is between 10 and 100, inclusive.
	As each number is read, validate it and store it in the array only
	if it isn't a duplicate of a number already read.
	After reading all the values, display only the unique values that the user entered.
	Provide for the "worst case" in which all 20 numbers are different. Use the smallest possible array to solve this problem.

*/

#include<iostream>
#include<array>
#include<algorithm>

int DuplicateEliminationWithArray() {

	std::array<int, 20> arr{};

	for (int i{ 0 }; i < 20; ++i) {

		int number;
		std::cout << "Enter the Number: ",
			std::cin >> number;

		if ((10 <= number)
			&& (100 >= number)
			&& (std::count(arr.begin(), arr.end(), number) == 0)) {

			arr[i] = number;
		}
		else {
			std::cout << "\nThe Number must be in the interval  10 <= number <= 100\n"
				<< "and must also be different from the previous numbers entered.\n\n";
		}

	}

	std::cout << "\nThe valid numbers entered are: ";

	for (int elem : arr) { if (elem) { std:: cout << elem << ", "; } }

	return 0;
}