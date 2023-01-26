//5.24 (Modified Egg-timer Program) 
/*
		Modify the application you wrote in Exercise 5.23 to read an odd number
		in the range 1 to 29 to specify the height of the egg-timer.Your program should
		then display an egg - timer of the appropriate size.
		(The egg-timer shown above in Exercise 5.23 has a height of 9)

*/

#include<iostream>

int ModifiedEggTimer() {

	int range;

	std::cout << "Enter an odd number in the range 1 to 29: ",
		std::cin >> range;

	--range;

	for (int i{ range }; i >= -(range); i -= 2) {

		std::cout << "#";

		if ((i == 0) || (i % range != 0)) {

			for (int y{ (i > 0 ? std::abs(i - (range -2)) : i + (range -2)) }; y > 0; y -= 2) {

				std::cout << " ";
			}

			for (int y{ std::abs(i) }; y >= 0; y--) {

				std::cout << "*";
			}
		
			for (int y{ (i > 0 ? std::abs(i - (range -2)) : i + (range -2)) }; y > 0; y -= 2) {

				std::cout << " ";
			}
		}
		else {
			for (int x{ range  -1}; x > 0; x--) {

				std::cout << "#";
			}
		}

		std::cout << "#";
		std::cout << std::endl;
	}

	std::cout << std::endl;

	return 0;
}