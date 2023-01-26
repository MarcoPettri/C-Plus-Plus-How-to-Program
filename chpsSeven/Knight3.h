// Knight3.h
/*
	Knight Class Simulating the movements of the knight on a chessboard using brute force approaches.
*/

#include<iostream>
#include<iomanip>
#include<vector>
#include<random>


class Kinght3 {

public:
	Kinght3() {
		knightPosition = { RANDOM_INDEX(ENGINE), RANDOM_INDEX(ENGINE) };
		board[8 * knightPosition[0] + knightPosition[1]] = "[K]";
	}

	bool makeMove() {

		while (true) {
			
			int newPosition{ 8 * RANDOM_INDEX(ENGINE) + RANDOM_INDEX(ENGINE) };

			//Is verified that the new position generated is not disabled,
			//avoiding going through the checker function 
			//to know if it is a valid movement from the current position .

			if (board[newPosition] == "[1]" || board[newPosition] == "[K]") {
				continue;
			}

			else if (checker({ newPosition / 8, newPosition % 8 })) {

				board[8 * knightPosition[0] + knightPosition[1]] = "[1]";
				board[newPosition] = "[K]";
				knightPosition = { newPosition / 8, newPosition % 8 };

				return true;
			}
			//if there are no more possible movements from the current position the game is finished
			if (not accessibility()) {
				return false;
			}
		}
	}

	//Displays the chessboard in a nice format
	void displayBoard() const {
		std::cout << std::endl;
		std::cout << std::setw(30) << "Chessboard\n\n" << std::setw(9);

		for (int i{ 0 }; i < 8; ++i) { std::cout << i << std::setw(5); }
		std::cout << "\n\n";

		for (int index{ 0 }; index < 64; ++index) {

			if (index % 8 == 0 || index == 0) {
				std::cout << std::setw(5) << index / 8;
			}
			std::cout << std::setw(5) << board[index];

			if ((1 + index) % 8 == 0) {
				std::cout << std::endl;
			}
		}
	}	

	//Return the knight's Current Position
	const std::vector<int>& currentPosition() const {
		return  knightPosition;
	}
	
	//Return the board
	const std::vector<std::string>& getBoard() const {
		return board;
	}

private:
	std::vector<int> knightPosition;// The Knight's index
	std::vector<std::string> board = std::vector<std::string>(64, "[0]"); //Chessboard
	std::random_device seed; // Seed
	std::default_random_engine ENGINE{ static_cast<unsigned>(seed())}; //Engine
	std::uniform_int_distribution<int> RANDOM_INDEX{ 0, 7 }; // Interval


	bool checker(std::vector<int> newPosition) {
		/*
		* This function verifies that the new position is valid. 
        *
        * Parameters
        * ----------
        *	new_position : std::vector
        *		the position to tester if it is valid to move the knight
        * Returns
        * -------
        *     a boolean value
		* 
		*/

		//if the new position is either one row and two columns 
		//or two rows and one column from the current position, then it is valid
		std::vector<int> position { knightPosition[0] - newPosition[0], knightPosition[1] - newPosition[1] };

		//gets the abs of the results
		position[0] = (position[0] > 0 ? position[0] : -position[0]);
		position[1] = (position[1] > 0 ? position[1] : -position[1]);

		//Is checked that the difference between the current position of the knight and the new position 
		//meets the criteria mentioned above.  
		bool test{ (position[0] == 1 && position[1] == 2) || (position[0] == 2 && position[1] == 1) };

		if (test) {
			//verifies that the position remains valid 
			if (board[8 * newPosition[0] + newPosition[1]] == "[0]") {
				return true;
			}
		}
		return false;
	}
	
	bool accessibility() {
		/*
			It checks if the knight can move to any of the 8 possible positions 
			from the current position
		*/	

		//this vector is used to generate all possible moves. 4 when ±1 is added to the row and ±2 is added to the column 
		// and  4 when ±2 is added to the row and ±1 is added to the column, i.e
		// [ (1, 2), (-1, -2), (1, -2), (-1, 2), ] and [ (2, 1), (-2, -1), (2, -1),  (-2, 1) ]
		//to optimize the search is tried from two positions each turn 
		std::vector<int> possiblesRanges{ 1, 2, 2, 1 };
		int counter{ 0 };

		while (true) {

			std::vector<int> possiblePositions{  possiblesRanges[0] + knightPosition[0],
												 possiblesRanges[1] + knightPosition[1],
												 possiblesRanges[2] + knightPosition[0],
												 possiblesRanges[3] + knightPosition[1] };
			/*
			filter the possible position that are less than 8 and greater than 0, 
			that is, that are not off the board and are not negative indices
			*/
			if ((0 <= possiblePositions[0] && possiblePositions[0] < 8) 
										   &&
				(0 <= possiblePositions[1] && possiblePositions[1] < 8)) {
				// is checked that it is a valid position
				if (checker({ possiblePositions[0], possiblePositions[1] })) {
					return true;
				}
			}
			if ((0 <= possiblePositions[2] && possiblePositions[2] < 8) 
										   &&
				(0 <= possiblePositions[3] && possiblePositions[3] < 8)) {
					// is checked that it is a valid position
					if (checker({ possiblePositions[2], possiblePositions[3] })) {
						return true;
				}
			}

			if (counter < 3) {
				//the second and fourth possible movement, 
				//when counter = 0 --> (row  -1, column -2) and ( row -2, column -1)
				//when counter = 2 --> (row -1, column +2) and (row -2, column +1)
				if (not counter || counter == 2) {
					for (auto& index : possiblesRanges) { index *= -1; }
					counter++;
				}
				else {
					//the third possible movement, i.e (row +1, column -2) and (row +2, column -1)
					possiblesRanges[0] *= -1;
					possiblesRanges[2] *= -1;
					counter++;
				}
			}
			else {
				//if all valid positions have already been disabled 
				//then false is returned indicating that there are no possible moves from the current position
				return false;
			}
		}

	}
};