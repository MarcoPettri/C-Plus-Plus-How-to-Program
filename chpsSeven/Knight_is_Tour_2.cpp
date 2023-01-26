// Exercise 7.22: Knight's Tour 

/*

- B) After attempting to write and run a Knight's Tour script, you've probably developed some valuable insights.
	We'll use these insights to develop a heuristic (i.e., a common-sense rule) for moving the knight.
	Heuristics do not guarantee success, but a carefully developed heuristic greatly improves the chance of success.
	You may have observed that the outer squares are more troublesome than the squares nearer the center of the board.
	In fact, the most troublesome or inaccessible squares are the four corners.
	<br> &nbsp; Intuition may suggest that you should attempt to move the knight to the most troublesome squares first and leave open those
	that are easiest to get to so that when the board gets congested near the end of the tour, there will be a greater chance of success.
	<br> &nbsp; We could develop an “accessibility heuristic” by classifying each of the squares according to how accessible it is and
	always moving the knight (using the knight's L-shaped moves) to the most inaccessible square. We fill two- dimensional array accessibility
	with numbers indicating from how many squares each particular square is accessible. On a blank chessboard, each of the 16 squares nearest the center is rated as 8,
	each corner square is rated as 2, and the other squares have accessibility numbers of 3, 4 or 6 as follows:

					2 3 4 4 4 4 3 2
					3 4 6 6 6 6 4 3
					4 6 8 8 8 8 6 4
					4 6 8 8 8 8 6 4
					4 6 8 8 8 8 6 4
					4 6 8 8 8 8 6 4
					3 4 6 6 6 6 4 3
					2 3 4 4 4 4 3 2

	Write a new version of the Knight's Tour, using the accessibility heuristic. The knight should always move to the square with the lowest accessibility number.
	In case of a tie, the knight may move to any of the tied squares. Therefore, the tour may begin in any of the four corners.
	[Note: As the knight moves around the chessboard, your application should reduce the accessibility numbers as more squares become occupied.
	In this way, at any given time during the tour, each available square's accessibility number will remain equal to precisely the number of squares from which that square may be reached.]
	Run this version of your script. Did you get a full tour? Modify the script to run 64 tours, one starting from each square of the chessboard.
	How many full tours did you get?
*/

#include <iostream>
#include <algorithm>
#include "Knight2.h"

int KnightIsTour_2() {

	std::vector<std::string> board(64, "[0]");
	Knight2 kinght;


	//Answer 1
	do { kinght.displayBoard(); } while (kinght.move());


	std::cout << "Did you get a full tour?" << std::endl;

	int tour{ 0 };
	for (auto const& squares : kinght.getBoard()) {
		if (squares == "[0]") { tour++; }
	}

	std::cout << (tour == 63 ? "Yes" : "Not") << std::endl;

	//Answer 2

	tour = 0;

	for (int startingPosition{ 0 }; startingPosition < 64; ++startingPosition) {

		Knight2 kinght;

		std::vector<int> row_column{ startingPosition / 8, startingPosition % 8 };
		kinght.set(row_column);

		while (kinght.move());
		
		if (std::count(kinght.getBoard().begin(), kinght.getBoard().end(), "[0]") == 63) {
			tour++;
		}
	}

	std::cout << "\n\t Answer 2\n"
		<< "\nHow many full tours did you get?\n"
		<< tour << std::endl;

	return 0;
}