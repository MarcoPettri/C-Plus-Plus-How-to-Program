// Knight.h
/*
	Knight class that simulates the movements of the knight on a chessboard 
*/

#include<iostream>
#include<iomanip>
#include<array>
#include<string>



class Knight {
public:
	explicit Knight(std::array<int,2>& position) {

		//checks that the position is not off the board.
		if (position[0] < board.size() && position[1] < board.size()) {

			board.fill({ {"[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]"} });
			board[position[0]][position[1]] = "[k]";
			knightPosition = position;

		}
	}

	//Displays the chessboard in a nice format
	void displaysBoard() const {

		std::cout << std::endl;
		std::cout << std::setw(30) << "Chessboard\n\n" << std::setw(9);

		for (int i{ 0 }; i < 8; ++i) { std::cout << i << std::setw(4); }
		std::cout << "\n\n";

		for (int index{ 0 }; index < board.size(); ++index) {

			std::cout << std::setw(5) << index << std::setw(5);

			for (int squares{ 0 }; squares < board[index].size(); ++squares) {
				std::cout << board[index][squares] << " ";
			}
		
			std::cout << std::endl;
		}
	}

	// Return the knight's Current Position
	const std::array<int, 2>& currentPosition() const {
		return knightPosition;
	}

	//Return the Board
	const std::array<std::array<std::string, 8>, 8>& getBoard() const {
		return board;
	}

	bool move() {
		/*
		Simulates the movement of a knight on the chessboard
		from the knight's current position.

		@Returns
		-------
			A boolean value:
				if the knight was moved: True

				otherwise: False, i.e. there are no more possible moves from the current position.
		*/

		// This array is used to generate all possible moves. 4 when ±1 is added to the row and 4 when ±2 are added, i.e.
		std::array<int, 2> movements{ 1, 2 }; // [(1, 2), (-1, -2), (1, -2), (-1, 2), ], [(2, -1), (-2, 1), (2, 1),  (-2, -1)]

		// There can only be two attempts, one when ±1 is added to the row and ±2 to the column , and another when  ±2 is added to the row and ±1 to the column.

		//For simplicity, from here axis = 1 refers to rows ±1 and column ±2 ,while axis = 2 when row ±2 and column ±1
		int attempted{ 0 };
		// 'Count' keeps track of the attempts for each axis( max(4) ).
		int count{ 0 };

		while (attempted < 2) {

			// Adds ±1 or ±2 to the row and the column
			std::array<int, 2> newPosition{ knightPosition[0] + movements[0], knightPosition[1] + movements[1] };

			// Tests the new position; return true if knight was moved
				//checks that the new position is not off the board, i.e. an index error 
			if ((newPosition[0] < board.size()) && (newPosition[1] < board.size())) {

					//Check that the new position has not yet been occupied. 
				if (board[newPosition[0]][newPosition[1]] == "[ ]") {

					board[knightPosition[0]][knightPosition[1]] = "[1]";
					board[newPosition[0]][newPosition[1]] = "[K]";
					knightPosition = newPosition;
					return true;
				}
			}
			
			// If the new position does not work, there are at least 4 attempts for each axis, 
			// then the other possible moves are generated. 
			if (count < 3) {

				if (count < 2) {

					if (not count) {
						//The second possible movement, i.e (row  -1, column -2) or ( row -2, column -1)

						for (int& movement : movements) { movement *= -1; }
						count++;
					}
					else {
						//The third possible movement, i.e (row +1, column -2) or (row +2, column -1)
						movements[0] *= -1;
						count++;
					}
				}
				else {
					//The fourth  possible movement, i.e (row -1, column +2) or (row -2, column +1)
					for (int& movement : movements) { movement *= -1; }
					count++;
				}

			}
			//Otherwise, tests the second attempt, i.e. axis = 2.
			else {
				movements = { 2, 1 };
				count = 0;
				attempted++;
			}

		}
		//Return false if there are no more possible moves from the current position.
		return false;
	}


private:
	std::array<std::array<std::string, 8>, 8> board{};
	std::array<int, 2> knightPosition{};

};