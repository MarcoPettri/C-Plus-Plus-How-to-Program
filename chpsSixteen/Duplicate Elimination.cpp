// Exercise 16.x: Duplicate Elimination
/*

		Read 20 integers into an array. Next, use the unique algorithm to
		reduce the array to the unique values entered by the user. Use the copy algorithm to display the
		unique values.
*/


#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<array>
#include<iterator>


int DUPLICATE_ELIMINATION()
{
	std::ostream_iterator<int> output{ std::cout, " " };
	const std::size_t SIZE{ 20 };
	std::array<int, SIZE> integers;

	std::cout << "Enter 20 integers separated by spaces: "; 

	// input: 3 2 5 5 7 3 5 4 6 1 4 7 3 2 5 5 6 3 7 9 //
	for (std::size_t index{ 0 }; index < SIZE; ++index) {
		std::cin >> integers[index];
	}
	
	std::cout << "Integers entered:" << std::endl;
	std::copy(integers.cbegin(), integers.cend(), output);


	std::cout << "\nUnique Integers:" << std::endl;

	std::sort(integers.begin(), integers.end());
	auto endLocation = std::unique(integers.begin(), integers.end());
	
	std::copy(integers.begin(), endLocation, output);

	

	return 0;
}