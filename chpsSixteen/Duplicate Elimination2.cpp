//Exercise 16.x: Duplicate Elimination 2
/*

		Modify Exercise 16.8 to use the unique_copy algorithm. The
		unique values should be inserted into a vector that's initially empty. Use a back_inserter to enable
		the vector to grow as new items are added. Use the copy algorithm to display the unique values.
*/

#include<iostream>
#include<iterator>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<array>

int DUPLICATE_ELIMINATION_2()
{

	std::ostream_iterator<int> output{ std::cout, " " };
	const std::size_t          SIZE{ 20 };
	std::array<int, SIZE>      integers;
	std::vector<int>           unique_values;


	std::cout << "Enter 20 integers separated by spaces: ";

	// input: 3 2 5 5 7 3 5 4 6 1 4 7 3 2 5 5 6 3 7 9 //
	for (std::size_t index{ 0 }; index < SIZE; ++index) {
		std::cin >> integers[index];
	}

	std::cout << "Integers entered:" << std::endl;
	std::copy(integers.cbegin(), integers.cend(), output);


	std::cout << "\nUnique Integers:" << std::endl;

	std::sort(integers.begin(), integers.end());
	std::unique_copy(integers.cbegin(), integers.cend(), std::back_inserter(unique_values));
	std::copy(unique_values.cbegin(), unique_values.cend(), output);

	return 0;
}