// Exercise 16.x: Reading Data from a File
/*
		Use an istream_iterator<int>, the copy algorithm and a
		back_inserter to read the contents of a text file that contains int values separated by whitespace.
		Place the int values into a vector of ints. The first argument to the copy algorithm should be the
		istream_iterator<int> object that's associated with the text file's ifstream object. The second argument 
		should be an istream_iterator<int> object that's initialized using the class template
		istream_iterator's default constructor-the resulting object can be used as an "end" iterator. After
		reading the file's contents, display the contents of the resulting vector.

*/


#include<fstream>
#include<iostream>
#include<iterator>
#include<algorithm>
#include<cstdlib>
#include<vector>

int READING_DATA_FROM_A_FILE()
{
	std::ifstream integers{ "integers.txt", std::ios::in };


	if (!integers) {
		std::cerr << "Unable to open integers.txt\n";
		std::exit(EXIT_FAILURE);
	}

	std::vector<int> result;
	std::ostream_iterator<int> output{ std::cout, " " };
	std::istream_iterator<int> input{ integers };
	std::istream_iterator<int> end{};

	std::copy(input, end, std::back_inserter(result));
	std::copy(result.cbegin(), result.cend(), output);

	integers.close();


	return 0;
}