//Exercise 8.12 : Simulation: The Tortoise and the Hare

/*
		In this exercise, you'll re-create the classic race of
		the tortoise and the hare. You'll use random number generation to develop a simulation of this
		memorable event.
			Our contenders begin the race at "square 1" of 70 squares. Each square represents a possible
		position along the race course. The finish line is at square 70. The first contender to reach or pass
		square 70 is rewarded with a pail of fresh carrots and lettuce. The course weaves its way up the side
		of a slippery mountain, so occasionally the contenders lose ground.
			There is a clock that ticks once per second. With each tick of the clock, your program should
		use function moveTortoise and moveHare to adjust the position of the animals according to the
		rules in Fig. 8.18. These functions should use pointer-based pass-by-reference to modify the posi-
		tion of the tortoise and the hare.

					Animal		Move type	 Percentage of the time			Actual move

					Tortoise	Fast plod		      50%				 3 squares to the right
								  Slip				  16%				 6 squares to the left
								Slow plod			  34%				 1 square to the right

					Hare		  Sleep				  38%				 No move at all
								Big   hop			  16%				 11 squares to the right
								Big   slip			  16%				 9 squares to the left
								Small hop			  20%				 1 square to the right
								Small slip			  10%				 2 squares to the left

								Fig. 8.18 | Rules for moving the tortoise and the hare


			Use variables to keep track of the positions of the animals (i.e., position numbers are 1–70).
		Start each animal at position 1 (i.e., the "starting gate"). If an animal slips left before square 1,
		move the animal back to square 1.
			Generate the percentages in Fig. 8.18 by producing a random integer i in the range
		1 <= i <= 50. For the tortoise, perform a "fast plod" when 1 <= i <= 25, a "slip" when 26 <= i <= 33
		or a "slow plod" when 34 <= i <= 50. Use a similar technique to move the hare.

			Begin the race by displaying
					BANG !!!!!
					AND THEY'RE OFF !!!!!

			For each tick of the clock (i.e., each iteration of a loop), display a 70-position line showing the
		letter T in the tortoise's position and the letter H in the hare's position. Occasionally, the contenders
		land on the same square. In this case, the tortoise bites the hare and your program should display
		OUCH!!!beginning at that position. All positions other than the T, the H or the OUCH!!! (in case of a tie)
		should be blank.
			After displaying each line, test whether either animal has reached or passed square 70. If so,
		display the winner and terminate the simulation. If the tortoise wins, display TORTOISE WINS!!!
		YAY!!! If the hare wins, display Hare wins. Yuck. If both animals win on the same clock tick, you
		may want to favor the tortoise (the "underdog"), or you may want to display It's a tie. If neither
		animal wins, perform the loop again to simulate the next tick of the clock.

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