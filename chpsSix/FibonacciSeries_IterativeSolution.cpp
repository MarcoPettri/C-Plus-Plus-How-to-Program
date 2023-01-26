// 6.37 Exercise: Fibonacci Series  iterative Solution 
/*
	Write a nonrecursive version of the function fibonacci from Fig. 6.26
*/

#include <iostream>
#include <utility>

unsigned long fibonacci(unsigned long);

int FibonacciSeries() {

	std::cout << fibonacci(10);
	return 0;
}

unsigned long fibonacci(unsigned long number) {

	unsigned long next{ 0 };
	unsigned long primer{ 0 };
	unsigned long second{ 1 };

	for (unsigned long i{ 1 }; i < number; i++) {
		next = primer + second;
		primer = second;
		second = next;
		
	}

	return next;
}