// Exercise 22.x:Division and multiplication via bit shifting
/*
		 Left-shifting an unsigned integer by one bit is equivalent to multiplying 
		 the value by 2 and right-shifting an unsigned integer by one bit is equivalent 
		 to dividing the value by 2. Write functions power2 and divide2 that take two unsigned integer
		 arguments, number and pow, and calculates number * 2pow and number/2pow. Use a shift operator to
		 calculate the result. Write a program to test the functions

*/

#include<iostream>

int power2(unsigned , unsigned);
int divided2(unsigned, unsigned);

int DIVISION_AND_MULTIPLICATION_VIA_BIT_SHIFTING()
{
	int number1{ 88 };
	int number2{ 4 };
	
	std::cout << "Number1: " << number1
		<< "\nNumber2: " << number2
		<< "\nNumber1 << number2 = " << (number1 << number2)
		<< "\nNumber1 >> number2 = " << (number1 >> number2)
		<< "\nPower2(number1, number2) = " << power2(number1, number2)
		<< "\ndivided2(number1, number2) = " << divided2(number1, number2)
		<< std::endl;

	return 0;
}

int power2(unsigned number, unsigned pow)
{

	if (!pow || pow == 1) { return number * (pow ? 2 : 1); }

	int result{ 2 };

	while (--pow){ result *= 2; }

	return number * result;
}

int divided2(unsigned number, unsigned pow)
{
	if (!pow || pow == 1) { return number / (pow ? 2 : 1); }

	int result{ 2 };

	while (--pow) { result *= 2; }

	return number / result;
}