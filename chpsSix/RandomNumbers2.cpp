//6.17 Exercise: Random Numbers 2

/*
	Write a single statement that prints a number at random from each of the following sets:
	a) 0, 3, 6, 9, 12.
	b) 3, 5, 7, 9, 11, 13.
	c) 6, 10, 14, 18
*/

#include<iostream>
#include<cstdlib>
#include<vector>
#include<ctime>

int RandomNumbers2() {

	std::vector<unsigned int> one{ 0, 3, 6, 9, 12 };
	std::vector<unsigned int> two { 3, 5, 7, 9, 11, 13 };
	std::vector<unsigned int> three{ 6, 10, 14, 18 };

	std::srand(static_cast<unsigned int>(std::time(NULL)));
	
	std::cout << "Vector One:" << std::endl;
	for (const unsigned int& element : one) { std::cout << element << " "; };
	std::cout << "\nRandom element: " << one.at(std::rand() % one.size()) << std::endl;

	std::cout << "\nVector Two:" << std::endl;
	for (const unsigned int& number : two) { std::cout << number << " "; };
	std::cout << "\nRandom element: " << two.at(std::rand() % two.size()) << std::endl;

	std::cout << "\nVector Three:" << std::endl;
	for (const unsigned int& number : three) { std::cout << number << " "; };
	std::cout << "\nRandom element: " << three.at(std::rand() % three.size()) << std::endl;

	

	return 0;
}