//TicTacToe.cpp
/*
	TicTacToe Class Member-function definitions
*/

#include "TicTacToe.h"


TicTacToe::TicTacToe() : player{ 0 }, winner{ 0 }
{
	for (int i{ 0 }; i < 9; i++) {
		table.push_back(0);
	}
	players.push_back(1), players.push_back(2);

	while (not(player)) {


		std::cout << "Choose a Player: 1 to move first or 2 to move second: ",
			std::cin >> player;

		if (std::cin.fail() || (player != 1 && player != 2)) {

			std::cout << "\t\tChoose a valid player!!\n" << std::endl;
			std::cin.clear();
			player = 0;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
	
	}

}

void TicTacToe::display() const
{
	std::cout << std::endl;
	std::cout << std::setw(18) << "Table\n\n" << std::setw(9);

	for (int i{ 1 }; i < 4; i++) { std::cout << i << std::setw(5); }
	std::cout << "\n\n";

	for (int index{ 0 }; index < 9; index++) {
		
		if (not(index % 3) || not(index)) {
			std::cout << std::setw(4) << index / 3 + 1;
		}

		std::cout << std::setw(5) << table[index];

		if ((index + 1) % 3 == 0) {
			std::cout << std::endl;
		}
	}
}

void TicTacToe::play()
{
	display();

	do {
		std::cout << "\nPlay the player " << players[0] << std::endl;

		if (player == players[0]) {

			int row{ 0 }, column{ 0 };

			std::cout << "row: ", std::cin >> row;

			if (std::cin.fail() || not(0 < row && row < 4)) {
				std::cin.clear();
				row = 0;
			}
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "column: ", std::cin >> column;

			if (std::cin.fail() || not(0 < column && column < 4)) {
				std::cin.clear(); 
				column = 0;
			}
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			row--, column--;

			if (not(check(row, column))) {
				std::this_thread::sleep_for(std::chrono::seconds(1));
				display();
				continue;
			}
		}
		else {
			int row, column;
			std::random_device seed;
			std::default_random_engine ENGINE{ static_cast<unsigned>(seed()) };
			std::uniform_int_distribution<int> RANDOM_INDEX{ 0, 2 };
			do {
				row = RANDOM_INDEX(ENGINE);
				column = RANDOM_INDEX(ENGINE);

			} while (not(check(row, column)));

			row++, column++;

			std::cout << "row: ";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << row << std::endl;

			std::cout << "column: ";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout<< column << std::endl;
		}

		if (winner) {
			std::cout << '\n'
				<< std::setw(20) << "Gamer Over" << "\n\n"
				<< std::setw(19) << "Winner!!!" << std::endl
				<< std::setw(20) << "Player -> " << winner << std::endl;

			display();
		}
		else {
			bool draw{
				std::any_of(table.begin(),table.end(),
							[](int i) {return i == 0; })
			};

			if (not(draw)) { 
				winner = 3; 
				std::cout << '\n' 
					<< std::setw(20) << "Gamer Over" << "\n\n"
					<< std::setw(26) << "There is a Draw!" << std::endl;

				display();

			}
			else { 
				std::swap(players[0], players[1]); 
				std::this_thread::sleep_for(std::chrono::seconds(1));
				display();
			}
		}

		} while (not(winner));
}
bool TicTacToe::check(int row, int column)
{

	int position{ 3 * row + column };

	if (0 <= position && position < 9) {

		if (table.at(position) == 0) {
			table[position] = players[0];

			if (std::count(table.begin(), table.end(), 1) >= 3
									||
				std::count(table.begin(), table.end(), 2) >= 3) {
				
				for (int i{ 0 }; i < 3; i++) {

					bool test_vertical {
						   table[i] != 0
						&& table[i] == table[i + 3]
						&& table[i] == table[i + 6]
						&& table[i + 3] == table[i + 6]
					};

					if (test_vertical) {
						winner = players[0];
						return true;
					}	
					else if (i == 0 || i == 2) {

						int center{ 4 };
						int opposite_end{ (i == 0 ? 8 : 6) };

						bool test_diagonal{ 
							   table[i] != 0
							&& table[i] == table[center]
							&& table[i] == table[opposite_end]
							&& table[center] == table[opposite_end]
						};

						if (test_diagonal) {
							winner = players[0];
							return true;
						}
						else if(i == 0) {
							for (int row{ 0 }; row < 7; row += 3) {

								bool test_horizontal{
									   table[row] != 0
									&& table[row] == table[row + 1]
									&& table[row] == table[row + 2]
									&& table[row + 1] == table[row + 2]
								};
								if (test_horizontal) {
									winner = players[0];
									return true;
								}
							}
						}
					}

				}

			}
			return true;

		}
		else {
			if (players[0] == player) {
				std::cout << "\t That position is not possible. Choose an empty position!!"
					<< std::endl;
			}
			return false;
		}
	}
	else {
		std::cout << "\t Invalid Indexes!\n" << std::endl;
		return false;
	}
}