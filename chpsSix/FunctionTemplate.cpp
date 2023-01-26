//6.51 Exercise: Function Template minimum
/*
	Write a program that uses a function template called minimum
	to determine the smaller of two arguments.Test the program using integer, 
	character and floating-point number arguments.
*/

// 6.52 Exercise: Function Template maximum)
/*
	Write a program that uses a function template called maximum
	to determine the larger of two arguments.Test the program using integer, character 
	and floating-point number arguments.
*/

#include<iostream>
#include"Maximum_Minimum.h"

int FunctionTemplate() {

	int number1{ 2 };
	int number2{ 3 };
	char str1{ 'a' };
	char str2{ 'z' };
	double numDouble{ 599.322 };
	double numDouble2{ 5.322 };


	std::cout << "The maximum integer value is: "
		<< maximum(number1, number2) << std::endl
		<< "The minimum integer value is : "
		<< minumum(number2, number1) << std::endl;

	std::cout << "\nThe maximum double value is: "
		<< maximum(numDouble, numDouble2) << std::endl
		<< "The minimum double value is : "
		<< minumum(numDouble2, numDouble) << std::endl;

	std::cout << "\nThe maximum character value is: "
		<< maximum(str1, str2) << std::endl
		<< "The minimum character value is : "
		<< minumum(str2, str1) << std::endl;


		

	return 0;
}

