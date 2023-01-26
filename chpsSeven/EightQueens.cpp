// Exercise 7.24: Eight Queens

/*
	 Another puzzler for chess buffs is the Eight Queens problem. Simply stated:
	Is it possible to place eight queens on an empty chessboard so that no queen is "attacking" any other,
	i.e., no two queens are in the same row, the same column, or along the same diagonal? 
	Use the thinking developed in Exercise 7.22 to formulate a heuristic for solving the Eight Queens problem. 
	Run your program.

*/

#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<chrono>

void print();
bool validPostion(int r, int c);
bool game(int n_Queens);

std::vector<std::string> board(64, "[ ]");

int EightQueens() {

	print();
	auto star = std::chrono::steady_clock::now();
	game(8);
	auto end = std::chrono::steady_clock::now();
	print();
	std::cout << "Execution Time: "
		<< std::chrono::duration <double, std::milli>(end - star).count()
		<< " ms" << std::endl;

	return 0;
}

bool validPostion(int r, int c){
	/*
	* If the row and column are not already occupied,
	* and the row and column do not share a diagonal with
	* another queen, then the position is valid
	*
	* Parameters
	 ----------
	*	int r: row
	*	int c: column
	*
	* Returns
	-------
	*	true if the position is valid, otherwise false;
	*/

	//checking vertically and horizontally
	for (int index{ 0 }; index < 8; index++) {

		if ((board[8 * r + index] == "[Q]") 
						|| 
			(board[8 * index + c] == "[Q]")) { return false; }
	}

	for (int index{ 0 }; index < 64; index++) {

		int row = index / 8;
		int column = index % 8;

		//The diagonals are checked.
		if ((row + column == r + c) || (row - column == r - c)) {
			if (board[index] == "[Q]") { return false; }
		}
	}
	
	return true;
		
}

bool game(int n_Queens) {


	if (not n_Queens) { return true; }

	for (int row_column{ 0 }; row_column < 64; row_column++) {
		int row = row_column / 8;
		int column = row_column % 8;

		
		if(validPostion(row, column)){

			board[row_column] = "[Q]";

			if (game(n_Queens - 1)) { return true; }

			board[row_column] = "[ ]";
		}
	}

	return false;
 
}
void print() {

	std::cout << std::setw(30) << "Board\n\n" << std::setw(9);
	for (int i{ 0 }; i < 8; ++i) { std::cout << i << std::setw(5); }
	std::cout << "\n\n";

	for (int index{ 0 }; index < 64; ++index) {

		if (index % 8 == 0 || index == 0) {
			std::cout << std::setw(5) << index / 8;
		}

		std::cout << std::setw(5) << board[index];

		if ((1 + index) % 8 == 0) { std::cout << std::endl; }
	}
}