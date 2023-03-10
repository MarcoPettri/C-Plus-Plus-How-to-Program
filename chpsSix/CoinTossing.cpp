//6.33 (Coin Tossing) 
/*
	Write a program that simulates coin tossing. For each toss of the coin, the
	program should print Heads or Tails.Let the program toss the coin 100 times and count 
	the number of times each side of the coin appears.Print the results.
	The program should call a separate function flip that takes no arguments 
	and returns 0 for tails and 1 for heads.[Note:If the program realistically simulates the coin tossing, 
	then each side of the coin should appear approximately half the time.]
*/

#include<iostream>
#include<cstdlib>
#include<ctime>


inline int flip() { return (std::rand() % 2); }

int CoinTossing() {


	std::srand(static_cast<unsigned int>(std::time(NULL)));
	int head{ 0 }, tail{ 0 };

	for (int i{ 0 }; i < 100; i++) {

		int coin{ flip() };

		std::cout << coin << ", "; 
		
		if (coin) { head++; }
		else { tail++; }
	}
	std::cout << "\nHead: " << head
		<< "\nTail: " << tail
		<< std::endl;

	return 0;
}


