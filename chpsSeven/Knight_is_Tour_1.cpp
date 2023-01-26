// Exercise 7.22: Knight's Tour 
/*
		- a) Write a script to move the knight around the chessboard. Keep a counter that varies from 1 to 64. 
		Record the latest count in each square the knight moves to.
		Test each potential move to see if the knight has already visited that square. 
		Test every potential move to ensure that the knight does not land off the chessboard. Run the application. 
		How many moves did the knight make?
*/

#include <iostream>
#include <array>
#include "Knight.h"

int KnightIsTour_1() {


	int totalMoviments{ 0 };
	std::array<int, 2> startPosition{ 3, 4 };


	Knight k{ startPosition };

	std::cout << "Start\n";
	k.displaysBoard();

	for (int movements{ 1 }; k.move(); ++movements) {

		std::cout << "\nMovements: " << movements << std::endl;
		k.displaysBoard();
		std::cout << std::endl;

	}
	for (auto const& rows : k.getBoard()) {
		for (auto const& squares : rows) {
			if (squares == "[ ]") { totalMoviments++; }
		}
	}
	 
	std::cout << "\nNumber of moves missing to complete the board: " << totalMoviments << std::endl;

	return 0;
}