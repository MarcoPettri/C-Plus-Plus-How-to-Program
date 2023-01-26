//Exercise 5.26: Knight's Tour- Closed-Tour Test

/*

	In the Knight’s Tour, a full tour occurs when the knight
	makes 64 moves, touching each square of the board once and only once. A closed tour occurs when
	the 64th move is one move away from the location in which the knight started the tour. Modify the
	Knight’s Tour program you wrote in Exercise 7.22 to test for a closed tour if a full tour has occurred.
*/


#include<iostream>
#include<vector>
#include<cstdlib>

#include "Knight2.h"


int knightIsTour_4() {

	Knight2 knight;
	knight.displayBoard();
	bool checker{ false };
	int attempts{ 1 };

	std::cout << "\n\t\tStars" << std::endl;

	while (not checker) {

		std::cout << "\n\n\nAttempts: " << attempts;
		std::vector<int>initialPosition{ std::rand() % 8, std::rand() % 8 };

		Knight2 knight;
		knight.set(initialPosition);
		knight.displayBoard();

		while (knight.move()) {
			knight.displayBoard();
		}
		
		/*if the final position is either one row and two columns
		or two rows and one column from the initial position, then it is a valid position
		Therefore, the absolute value of the difference between the rows and the columns is obtained,
		*/
		std::vector<int> finalPosition = { std::abs(knight.currentPosition()[0] - initialPosition[0]),
										  std::abs(knight.currentPosition()[1] - initialPosition[1]) };
		//and finally the above mentioned criteria are checked. 
		checker = { (finalPosition[0] == 1 && finalPosition[1] == 2)
										   ||
					(finalPosition[0] == 2 && finalPosition[1] == 1) };

		if (checker) {
			std::cout << "\n\nInitial Position: \n\tRow: "
				<< initialPosition[0] << "\n\tColumn: " << initialPosition[1];

			std::cout << "\n\nFinal Position: \n\tRow: "
				<< knight.currentPosition()[0] << "\n\tColumn: " << knight.currentPosition()[0];

			knight.set(initialPosition);

			knight.displayBoard();
		}
		attempts++;
	}

	return 0;
}