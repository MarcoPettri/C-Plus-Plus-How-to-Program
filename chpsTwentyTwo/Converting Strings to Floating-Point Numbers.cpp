//Exercise 22.x: Converting Strings to Floating-Point Numbers
/*
		Write a program that inputs as command-
		line arguments four strings that represent floating-point values, converts the strings to double values,
		sums the values and prints the total of the four values. Use only the C string-processing techniques
		shown in this chapter.
*/



#include<iostream>
#include<cstdlib>

int CONVERTING_STRINGS_TO_FLOATING_POINT_NUMBERS(int argc, char* argv[])
{

	double result{ 0 };

	for (int i{ 1 }; i < argc; ++i) { result += std::atof(argv[i]); }


	std::cout << "Sum = " << result << std::endl;
	return 0;

}