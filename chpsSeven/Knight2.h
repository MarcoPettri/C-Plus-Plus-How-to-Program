// Knight2.h
/*
	Knight class that simulates the movements of the knight on a chessboard using accessibility heuristics.
*/

#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<algorithm>


class Knight2 {

public:

	Knight2() {
		for (int i{ 0 }; i < 64; i++) {
			//The board is initialised with each
			//square with the number of accesses it has.
			accesibility(i);
		}
	}

	// Sets the knight's position
	void set(std::vector<int>& position) {
		
		if (position[0] < board.size() && position[1] < board.size()) {
			knightPosition = 8 * position[0] + position[1];
			board[knightPosition] = "[K]";
			return;
		}
		std::cout << "Invalid Position";
	}

	//Displays the chessboard in a nice format
	void displayBoard() const {
		std::cout << std::endl;
		std::cout << std::setw(30) << "Chessboard\n\n" << std::setw(9);

		for (int i{ 0 }; i < 8; ++i) { std::cout << i << std::setw(5); }
		std::cout << "\n\n";

		for (int index{ 0 }; index < 64; ++index) {

			if (index  % 8 == 0 || index == 0) {
				std::cout << std::setw(5) << index / 8;
			}
			std::cout << std::setw(5) << board[index];

			if (( 1 + index) % 8 == 0 ) {
				std::cout << std::endl;
			}
		}
	}

	bool move() {
		/*
		Simulates the movement of a knight on the chessboard
		from the knight's current position.

		@Returns
		-------
			A boolean value:
				if the knight was moved : True

				otherwise: False, i.e. there are no more possible moves from the current position.
		*/


		//All possible positions are generated 
		accesibility(); //from the current position of the knight.

		//Is checks that at least one position exists. 
		if(possiblesPosition.size()) {

			//The goal is to move the knight to the position of least accessibility.
			//In this way, the knight can travel as many positions as possible.
			int minimum{ possiblesPosition[0] };

			for (auto const& index : possiblesPosition) {

				int squareAccessibility = board[index][1] - '0';
				int status = board[minimum][1] - '0';

				if (squareAccessibility < status) {
					minimum = index;
				}

			}
			//The knight is moved to the position of least accessibility. 
			put(minimum, 0, true);
			return true;
		}
		return false;
	}

	//Return the knight's Current Position
	const std::vector<int> currentPosition() const {
		return { knightPosition / 8, knightPosition % 8 };
	}

	//Returns the possible positions that the knight can access from its current position
	std::vector<std::vector<int>>& getPossiblesPosition() const {

		std::vector<std::vector<int>> indexes{};

		for (auto const& index : possiblesPosition) {
			indexes.push_back({ index / 8, index % 8 });
		}
		return indexes;
	}

	//Return the Board
	const std::vector<std::string>& getBoard() const {
		return board;
	}


private:
	int knightPosition;
	std::vector<int> possiblesPosition;
	std::vector<std::string> board = std::vector<std::string>(64, "[0]");

	void accesibility(int row_column = -1) {
		/*
		It generates all possible moves from a given position

		@Parameters
		----------
		row_column: int , optional
			The square index to determine its accessibility
			Default: the position of the Knight

		@Returns
		--------
			Void
		*/

		if (row_column == -1) {
			row_column = knightPosition;
			possiblesPosition.clear();
		}

		//This vector is used to generate all possible moves. 4 when ±1 is added to the row and 4 when ±2 are added, i.e.
		std::vector<int> movements{ 1, 2 }; // { (1, 2), (-1, -2), (1, -2), (-1, 2) }, { (2, -1), (-2, 1), (2, 1),  (-2, -1) }
		 
		// There can only be two attempts, one when ±1 is added to the row and ±2 to the column , and another when  ±2 is added to the row and ±1 to the column.

		//For simplicity, axis = 1 refers to rows ±1 and column ±2 ,while axis = 2 when row ±2 and column ±1
		int attempted{ 0 };
		// 'Count' keeps track of the attempts for each axis( max(4) ).
		int count{ 0 };

		while (attempted < 2) {

			// Adds ±1 or ±2 to the row and the column
			int row = row_column / 8 + movements[0];
			int column = row_column % 8 + movements[1];

			//Is checked that the column and row are positive indices and that they are not outside the board
			if ((0 <= row && row < 8) && (0 <= column && column < 8)) {

				int newPosition = 8 * row + column;

				//#the new position is checked
				if( put(newPosition, row_column)) {

					//Default: the position of the Knight
					if (row_column == knightPosition ) {
						//If the position is valid, 
						//it is added to the vector of "possible position"
						//that the knight can access from its current position.
						possiblesPosition.push_back(newPosition); 							  

					}
				}
			}
			//there are at least 4 movements for each axis
			//then the other possible movements are generated.
			if (count < 3) {
				if (count < 2) {
					if (not count) {

						//The second possible movement, i.e (row  -1, column -2) or ( row -2, column -1)
						movements[0] *= -1;
						movements[1] *= -1;
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
					movements[0] *= -1;
					movements[1] *= -1;
					count++;
				}
			}
			//tests the second attempt, i.e. axis = 2
			else {
				movements = { 2, 1 };
				count = 0;
				attempted++;
			}
		}
	}	

	bool put(int& newIndex, int currentIndex = -1, bool move = false) {
		/*
		This function either moves the knight to the new position (if valid) or
		determines whether the new index is accessible from the current index

		@Parameters
		----------
		newIndex : int 
			the new index in which the knight has to move or index that must be tested if it is a valid position.

		currentIndex : int, optional
			the index of the square to determine from how many squares it is accessible.
			This is only used when initialising the board so that the accessibility number of each square can be displayed.


		move: bool, optional
			if True, the function will move the knight to the new index (if it is valid and if it has not yet been occupied).

		@Returns
		-------
			a boolean value.
		*/

		//checks that the new position is not off the board, i.e. an index error 
		if (newIndex < board.size()) {

			//is verified that the new position is valid  
			if (board[newIndex] != "[0]" || // or that the game has not started  
				std::all_of(board.begin(), board.end(), [&](const std::string& x) { return x != "[K]"; })) {

				if (move) {
					//iterates on all possible positions that are accessible from the knight's current position 
					for (auto& index : possiblesPosition) {

						//if they are different from the new position to which the knight has to move,
						if (index != newIndex) {

							//1 is subtracted from each square, that is, one less possibility of access 
							int squareAccessibility = (board[index][1] - '0') - 1;
							board[index] = "[" + std::to_string(squareAccessibility) + "]";
						}
						else {
							//The knight's current position is invalidated
							board[knightPosition] = "[0]";
							//the knight is inserted to the new position
							board[newIndex] = "[K]";
							//knight's position is updated
							knightPosition = newIndex;
						}
					}
				}//if the game did not start and if the new position can be accessed from the current square
				else if (std::all_of(board.begin(), board.end(), [&](const std::string& x) { return x != "[K]"; })) {

					//1 is added to the square 
					//This is to show the number of accessibility from each square. 
					int squareAccessibility = (board[currentIndex][1] - '0') + 1;
					board[currentIndex] = "[" + std::to_string(squareAccessibility) + "]";
				}

				return true;
			}
		} return false;

	}
};