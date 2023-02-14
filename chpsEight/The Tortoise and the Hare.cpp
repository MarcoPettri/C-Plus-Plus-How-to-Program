//Exercise 11.12 : Simulation: The Tortoise and the Hare

/*


*/

#include<iostream>
#include<iomanip>
#include<string>
#include<random>
#include <chrono>
#include <thread>

namespace simulation {

	std::random_device seed; // Seed
	std::default_random_engine ENGINE{ static_cast<unsigned>(seed()) }; //Engine
	std::uniform_int_distribution<int> RANDOM_INT{ 1, 50 }; // Interval
}


void moveTortoise(int*);
void moveHare(int*);

int Simulation() {

	int tortoise{ 0 };
	int hare{ 0 };

	std::cout << "\t\tBANG!!!!\n"
		<< "\n\tAND THEY'RE OFF!!!!\n";

	for (int square{ 1 }; square < 71; square++) {

	// Processing Phase 
		std::cout << std::endl;
		// Return the round winner
		while (tortoise != square && hare != square) {

			moveHare(&hare);
			std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::nanoseconds(60));
			moveTortoise(&tortoise);

			if(tortoise > square || hare > square) {

				(tortoise > square ? tortoise = 0 : hare = 0);
			}

		}

		// Termination Phase
		if (tortoise == hare) {

			if (square == 70) {
				// Break the draw in case it happens at the end of the race 
				while (tortoise != square || hare != square) {

					moveHare(&hare);
					moveTortoise(&tortoise);

					if (tortoise > square || hare > square) {

						(tortoise > square ? tortoise = 0 : hare = 0);
					}
				}
			}
			else {
				// Show the draw and gives the position to the tortoise 
				std::cout << "\n\n";

				std::cout << std::setw(13) <<  std::string(30, '-') << std::endl;

				std::cout << "|" 
					<< std::setw(20) << "There is a tie!"
					<< std::setw(11) << "|\n";

				std::cout << std::string(30, '~') << std::endl;

				std::cout << std::setw(2) << " Square "
					<< std::setw(10) << "| Tortoise  |"
					<< std::setw(7) << " Hare "
					<< std::setw(3) << "|"
					<< std::endl;

				std::cout << std::string(30, '~') << std::endl;

				std::cout << std::setw(4) << square 
					<< std::setw(14) << " | I'll win"
					<< std::setw(14) << "|I'll win |\n"

					<< std::setw(4) << square
					<< std::setw(14) << "| I'll win"
					<< std::setw(13) << " | OUCH!!! |"
					<< std::endl;

				std::cout << std::string(30, '~') << std::endl;

			}
		}
		if (tortoise == square) {
			//If the tortoise won, show the square and its position
			std::cout << "\n\n";

			std::cout << std::string(30, '~') << std::endl;

			std::cout << std::setw(2) << " Square "
				<< std::setw(13) << "| Tortoise |"
				<< std::setw(7) << "Hare"
				<< std::setw(3) <<  "|"
				<< std::endl;

			std::cout << std::string(30, '~') << std::endl;

			std::cout << std::setw(4) << square
				<< std::setw(18) << " | I'll win | "
				<< std::setw(9) << "|"
				<< std::endl;

			std::cout << std::string(30, '~') << std::endl;

			// check if it's the winner of the race, and show the result
			if (square == 70) {

				std::cout << "\n\n";
				std::cout << '\n' << std::string(30, '-') << std::endl;
			
				std::cout << "|"
					<< std::setw(20) << " * Winner! * "
					<< std::setw(10) << "|"
					<< std::endl;
				
				std::cout << std::string(30, '~') << std::endl;

				std::cout << "|"
					<< std::setw(12) << " TORTOISE WINS!!! YAY!!!"
					<< std::setw(6) << "|"
					<< std::endl;

				std::cout << std::string(30, '-') << std::endl;

			}
		}
		else if (hare == square) {
			// if the hare won, show the square and its position
			std::cout << "\n\n";

			std::cout << std::string(30, '~') << std::endl;

			std::cout << std::setw(2) << " Square "
				<< std::setw(4) << "| Tortoise |"
				<< std::setw(8) << "Hare"
				<< std::setw(3) << "|"
				<< std::endl;

			std::cout << std::string(30, '~') << std::endl;

			std::cout << std::setw(4) << square
				<< std::setw(5) << "|"
				<< std::setw(22) << "| I'll win |"
				<< std::endl;

			std::cout << std::string(30, '~') << std::endl;

			// check if it's the winner of the race, and show the result
			if (square == 70) {
				std::cout << "\n\n";
				std::cout << '\n' << std::string(30, '-') << std::endl;

				std::cout << "|"
					<< std::setw(20) << " * Winner! * "
					<< std::setw(10) << "|"
					<< std::endl;

				std::cout << std::string(30, '~') << std::endl;

				std::cout << "|"
					<< std::setw(22) << " HARE WINS!!! YAY!!!"
					<< std::setw(8) << "|"
					<< std::endl;

				std::cout << std::string(30, '-') << std::endl;

			}
		}
		
	}

	return 0;
}
void moveTortoise(int* tortoiseSquare) {


	int movement{ simulation::RANDOM_INT(simulation::ENGINE) };

	if (1 <= movement && movement <= 25) {
		*tortoiseSquare += 3; // Fast Plod
	}
	else if( 26 <= movement && movement <= 33){
		*tortoiseSquare -= 6; // Slip
	}
	else {
		(*tortoiseSquare)++; // Slow plod
	}
}
void moveHare(int* hareSquare) {


	int movement{ simulation::RANDOM_INT(simulation::ENGINE)};

	if (40 <= movement && movement <= 50) {
		*hareSquare += 10; // Big hop
	}
	else if (30 <= movement && movement < 40) {
		*hareSquare -= 9; // Big slip
	}
	else if (20 <= movement && movement < 30) {
		(*hareSquare)++; // Small hop
	}	
	else if (10 <= movement && movement < 20) {
		*hareSquare -= 2; // Small slip 
	}
	// else = Sleep -> No move at all
	
}