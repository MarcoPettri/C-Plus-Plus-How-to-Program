// 6.41 Exercise : Recursive Greatest Common Divisor

/*
	The greatest common divisor of integers x and y is the largest integer that evenly divides both x and y. 
	Write a recursive function gcd that returns the greatest common divisor of x and y, defined recursively as follows:
	If y is equal to 0, then gcd(x, y) is x; otherwise, gcd(x, y) is gcd(y, x % y), where % is the remainder operator. 
	[Note: For this algorithm, x must be larger than y.]

*/

#include<iostream>
#include<numeric>


inline int recursiveGCD(int x, int y) { return (y == 0 ? x : recursiveGCD(y, x % y)); }

int RecursiveGreatestCommonDivisor() {


	std::cout << "GCD(" << 24 << ", " << 112 << ") = " << std::gcd(24, 112) << std::endl;
	std::cout << "GCD(" << 24 << ", " << 112 << ") = " << recursiveGCD(24, 112);
	return 0;
}

