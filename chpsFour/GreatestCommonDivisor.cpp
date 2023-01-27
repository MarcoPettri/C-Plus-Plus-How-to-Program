// 6.31 Exercise: Greatest Common Divisor

/*
	The greatest common divisor (GCD) of two integers is the largest
	integer that evenly divides each of the numbers. Write a function gcd 
	that returns the greatest common divisor of two integers.
*/

#include<iostream>
#include <utility>

int gcd(int a, int b);

int GreatestCommonDivisor() {

	int n1, n2;

	std::cout << "Enter the first number: ",
		std::cin >> n1;	
	std::cout << "Enter the second number: ",
		std::cin >> n2;

	std::cout << "GCD(" << n1 << ", " << n2 << ") = "
		<< gcd(n1, n2);

	return 0;
}

int gcd(int a, int b) {
	
	while (b) {
		a %= b;
		std::swap(a, b);
	}
	return a;
}
