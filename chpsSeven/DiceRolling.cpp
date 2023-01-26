// Exercise 7.16: Dice Rolling
/*
	Write a program that simulates the rolling of two dice. The sum of the two values should then be calculated. 
	[Note: Each die can show an integer value from 1 to 6, so the sum of the
	two values will vary from 2 to 12, with 7 being the most frequent sum and 2 and 12 being the least
	frequent sums.] Figure 7.22 shows the 36 possible combinations of the two dice. Your program should
	roll the two dice 36,000,000 times. Use a one-dimensional array to tally the numbers of times each
	possible sum appears. Print the results in a tabular format. Also, determine if the totals are reasonable
	(i.e., there are six ways to roll a 7, so approximately one-sixth of all the rolls should be 7)

*/

#include<iostream>
#include<iomanip>
#include<locale>
#include<array>
#include<cstdlib>

int DiceRolling() {

	std::array<int, 13> frequencies{};

	for (int i{ 0 }; i < 36'000'000; ++i) {

		int diceOne = 1 + std::rand() % 6;
		int diceTwo = 1 + std::rand() % 6;
		int sum{ diceOne + diceTwo };

		frequencies[sum]++;
	}

	std::cout.imbue(std::locale(""));
	std::cout << "\t\tFrequencies of the sum of two dice rolled 36,000,000 times.\n\n";
	std::cout << "Result \t Total Appearances \t Frequency " << std::endl;

	
	for (int i{ 2 }; i < 13; ++i) {

		double frequency { double(frequencies[i]) / 36'000'000 };

		std::cout << std::setw(2)  << i << " \t " 
			<< frequencies[i]  << " \t\t " 
			<< frequency * 100 << "%" << std::endl;
	}

	return 0;
}