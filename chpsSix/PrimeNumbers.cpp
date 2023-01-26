// 6.29 Exercise: Prime Numbers
/*
			An integer is said to be prime if it’s divisible by only 1 and itself. 
			For example, 2, 3, 5 and 7 are prime, but 4, 6, 8 and 9 are not.

			a) Write a function that determines whether a number is prime.
			
			b) Use this function in a program that determines and prints all 
				the prime numbers between 2 and 10,000.
				How many of these numbers do you really have to test before being sure that you’ve found all the primes?

*/

#include<iostream>
#include<locale>
#include<iomanip>

bool isPrime(unsigned int& number);


int PrimeNumbers() {

	std::cout << std::boolalpha
		<< "\t\tPrime Numbers between 2 and 10,000\n" << std::endl;

	for (unsigned int numbers{ 2 }; numbers <= 10'000; numbers++) {


		if (isPrime(numbers)) {
			std::cout << std::setw(10) << numbers ;
		}
	}

	return 0;
}


bool isPrime(unsigned int& number) {

	if ((number % 2) == 0 && (number != 2)) {
		return false;
	}
	else if ((number % 3) == 0 && (number != 3)) {
		return false;
	}
	else if ((number % 5 == 0) && number != 5) {
		return false;
	}
	else if ((number % 7 == 0) && (number != 7)) {
		return false;
	}
	else {
		return true;
	}

}
