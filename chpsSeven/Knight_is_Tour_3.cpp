//// Exercise 7.23: Knight's Tour: Brute-Force Approaches 
/*
	In Part (c) of the previous exercise, we developed a solution to the Knight’s Tour problem. 
	The approach used, called the "accessibility heuristic," generates many solutions and executes efficiently. 
	As computers continue to increase in power, we'll be able to solve more problems with sheer computer power 
	and relatively unsophisticated algorithms.
 
	- a) Use random-number generation to enable the knight to walk around the chessboard (in its legitimate L-shaped moves) at random.
		Your program should run one tour and display the final chessboard. How far did the knight get?

	- b) Most likely, the program in Part (a) produced a relatively short tour. Now modify your program to attempt 1,000,000 tours.
		Use a one-dimensional array to keep track of the number of tours of each length. When your program finishes attempting the 1,000,000 tours, 
		it should display this information in a neat tabular format. What was the best result?

	- c) Most likely, the program in Part (b) gave you some “respectable” tours, but no full tours. 
		Now let your program run until it produces a full tour. [Caution: This version of the program could run for hours on a powerful computer.]
		Once again, keep a table of the number of tours of each length, and display this table when the first full tour is found. 
		How many tours did your program attempt before producing a full tour? How much time did it take?

	- d) Compare the brute-force version of the Knight’s Tour with the accessibility-heuristic version. 
		Which required a more careful study of the problem? Which algorithm was more challenging to develop? 
		Which required more computer power? Could we be certain (in advance) of obtaining a full tour with the accessibility-heuristic approach? 
		Could we be certain (in advance) of obtaining a full tour with the brute-force approach? Argue the pros and cons of brute-force problem-solving in general.

*/


#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <chrono>
#include "Knight3.h"

void print(std::vector<int64_t>&);

int KnightIsTour_3() {
	
// Answer A

	Kinght3 k;

	std::cout << " Answer A:";
	k.displayBoard();

	while (k.makeMove());

	k.displayBoard();

	std::cout << "Total Movements Made: "
		<< std::count(k.getBoard().begin(), k.getBoard().end(), "[1]");

// Answer B

	std::vector<int64_t> arr(64);

	for (int i{ 0 }; i < 1'000; ++i) {

		Kinght3 k;

		while (k.makeMove());

		int finalPosition{ 8 * k.currentPosition()[0] + k.currentPosition()[1] };
		arr[finalPosition] += std::count(k.getBoard().begin(), k.getBoard().end(), "[1]");

	}

	std::cout << "\n\n Answer B: \n" << std::setw(30) 
		<< "Results\n" << std::setw(9) << std::endl;

	print(arr);

	std::vector<int64_t>::iterator bestResult = std::max_element(arr.begin(), arr.end());
	int row_colum = std::distance(arr.begin(), bestResult);

	std::cout << "\n\nThe Best Result is in:\n\n";

	std::cout << std::setw(13) << "Row" 
		<< std::setw(14) << "Column" 
		<< std::setw(22) << "Total Movements" << std::endl;

	std::cout << std::setw(12) << row_colum / 8
		<< std::setw(13) << row_colum % 8
		<< std::setw(18) << *bestResult;

// Answer C

	int countTours{ 0 };
	bool sentinel{ false };
	arr = std::vector<int64_t>(64);

	
	auto star = std::chrono::steady_clock::now();

	while (!sentinel) {

		Kinght3 k;

		while (k.makeMove());

		int finalPosition{ 8 * k.currentPosition()[0] + k.currentPosition()[1] };
		int nStep = std::count(k.getBoard().begin(), k.getBoard().end(), "[1]");

		arr[finalPosition] += nStep;
	}

	auto end = std::chrono::steady_clock::now();

	std::cout << "\n\n\n Answer C: \n" << std::setw(30)
		<< "Results\n" << std::setw(9) << std::endl;

	print(arr);

	std::cout << "\nAttempts to get a full tour: " << countTours << std::endl;

	std::cout << "Execution Time: " 
		<< std::chrono::duration <double, std::milli>(end - star).count()
		<< " ms" << std::endl;

// Answer D

	std::cout << "\n\n\t D) Questions:\n\n";
	std::cout << "-1) Which required a more careful study of the problem?\n"
		"-2) Which algorithm was more challenging to develop?\n"
		"-3) Which required more computer power?\n"
		"-4) Could we be certain(in advance) of obtaining a full tour with the accessibility-heuristic approach?\n"
		"-5) Could we be certain(in advance) of obtaining a full tour with the brute-force approach?\n";

	std::cout << "\n Answers:\n\n";
	std::cout << "-1) The version with ''heuristic accessibility'' because all possible scenarios must be taken into account,\
					   for example, that the next position is not off the board, that it does not contain negative indices, etc.\n"
		"\n-2) The version with ''heuristic accessibility''.\n"
		"\n-3) The brute force approach, in addition, also requires more time.\n"
		"\n-4) Yes, since each next position is a product of the previous one\n"
		"\n-5) No, the reason for this is that the following positions are chosen at random.\n";

	
	std::cout << "\n\n D) PROS AND CONS OF BRUTE FORCE ALGORITHM:\n\n";
	std::cout << "Pros:\n\n";
	std::cout << "- It is a generic method and not limited to any specific domain of problem.\n"
		"- The brute force method is deal for solving small and simpler problems.\n"
		"- It is known for its simplicity and can serve as a comparison benchmark\n";

	std::cout << "\nCons:\n\n";
	std::cout << "- The brute force approach is inefficient. For real-time problems,\n"
					"   algorithm analysis often goes above the O(N!) order of growth.\n"
		"\n- This method relies more on compromising the power of a computer system\n"
		   "   for solving a problem than on a good algorithm design.\n"
		"\n- Brute force algorithms are slow.\n"
		"\n- Brute force algorithms are not constructive or creative."
		<< std::endl;
	
	
	return 0;
}

void print(std::vector<int64_t>& vect) {

	for (int i{ 0 }; i < 8; ++i) { std::cout << i << std::setw(5); }
	std::cout << "\n\n";

	for (int index{ 0 }; index < 64; ++index) {

		if (index % 8 == 0 || index == 0) {
			std::cout << std::setw(5) << index / 8;
		}

		std::cout << std::setw(5) << vect[index];

		if ((1 + index) % 8 == 0) { std::cout << std::endl; }
	}
}