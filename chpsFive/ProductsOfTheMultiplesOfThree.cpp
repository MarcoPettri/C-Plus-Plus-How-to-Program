// 4.12 Exercise: Calculating The Product Of The Multiples Of Three
/* Write an application that calculates
the product of the multiples of 3 in the range 3 to 50 */

#include<iostream>
#include<locale>

int ProductofThemultiplesOfThree() {

	unsigned int total{ 3 };

	std::cout.imbue(std::locale(""));

	std::cout << "Multiples of Three: ";

	for (unsigned int i{ 3 }; i < 50; i += 3) {
		
		std::cout << i << ", ";
		total *= i;

	}

	std::cout << std::endl << "The product of the multiples of 3 in the range 3 to 50 is: "
		<< total;

	return 0;
}