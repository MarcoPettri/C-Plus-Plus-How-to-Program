//6.30 Exercise: Reverse Digits
/*
	Write a function that takes an integer value and returns the number with
	its digits reversed.For example, given the number 7631, the function should return 1367
*/ 

#include<iostream>

int reversed(int number);

int ReverseDigits() {

	int integer;
	std::cout << "Enter the numbers: ",
		std::cin >> integer;

	std::cout << "Reversed: " << reversed(integer);

	return 0;
}

int reversed(int number) {

	int reversedNumber{ 0 };

	while (number > 0) {

		reversedNumber *= 10;
		reversedNumber += number % 10;
		number /= 10;
	}
	return reversedNumber;
}