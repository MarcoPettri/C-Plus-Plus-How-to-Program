// Exercise 7.14: Duplicate Elimination with vector

/*

	Reimplement Exercise 7.13 using a vector.
	Begin with an empty vector and use its push_back function to add each unique value to the vector.
*/

#include<iostream>
#include<vector>
#include<algorithm>

int DuplicateEliminationWithVector() {

	std::vector<int> vect;

	for (int i{ 0 }; i < 20; ++i) {

		int number;
		std::cout << "Enter the number: ",
			std::cin >> number;

		if ((10 <= number)
			&& (100 >= number)
			&& (std::count(vect.begin(), vect.end(), number) == 0)) {

			vect.push_back(number);
		}
		else {
			std::cout << "\nThe Number must be in the interval  10 <= number <= 100\n"
				<< "and must also be different from the previous numbers entered.\n\n";
		}
	}

	std::cout << "\nThe valid numbers entered are: ";

	for (int elem : vect) { std::cout << elem << ", "; }

	return 0;
}