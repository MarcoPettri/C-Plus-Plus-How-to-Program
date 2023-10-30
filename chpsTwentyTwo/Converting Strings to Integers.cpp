// Exercise 22.x:Converting Strings to Integers
/*

	Write a program that inputs as command-line arguments
	four strings that represent integers, converts the strings to integers, sums the values and prints the
	total of the four values. Use only the C string-processing techniques discussed in this chapter
*/

#include<iostream>
#include<cstdlib>

int CONVERTING_STRINGS_TO_INTEGERS(int argc, char* argv[])
{

	int result{ 0 };
	
	for (int i{ 1 }; i < argc; ++i) { result += std::atoi(argv[i]); }
		

	std::cout << "Sum = " << result << std::endl;
	return 0;

}