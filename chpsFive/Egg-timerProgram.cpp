//5.23 Exercise: Egg-timer Program
/*
		Write an application that prints the following egg - timer shape.
		You may use output statements that print a single asterisk(*), a single hash(#) a single space or a single
		newline character.Maximize your use of iteration(with nested for statements), and minimize the
		number of output statements.

								#########
								#*******#
								# ***** #
								#  ***  #
								#   *   #
								#  ***  #
								# ***** #
								#*******#
								#########

*/


#include<iostream>

int EggTimmer() {


	for (int i{ 8 }; i >= -8; i -= 2) {

		std::cout << "#";

		if ((i % 8 != 0) || (i == 0)) {

			for (int y{ (i > 0 ? std::abs(i - 6) : i + 6) }; y > 0; y -= 2) {

				std::cout << " ";
			}

			for (int y{ std::abs(i) }; y >= 0; y--) {

				std::cout << "*";
			}
			for (int y{ (i > 0 ? std::abs(i - 6) : i + 6) }; y > 0; y -= 2) {

				std::cout << " ";
			}
		}
		else {
			for (unsigned int x{ 0 }; x < 7; x++) {

				std::cout << "#";
			}
		}

		std::cout << "#";
		std::cout << std::endl;
	}

	std::cout << std::endl;

	return 0;
}