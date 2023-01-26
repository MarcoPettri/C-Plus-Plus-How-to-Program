// 6.19 Exercise : Hypotenuse Calculations

/*
	Define a function hypotenuse that calculates the hypotenuse of
	a right triangle when the other two sides are given. The function should take two double arguments
	and return the hypotenuse as a double. Use this function in a program to determine the hypotenuse
	for each of the triangles shown below.
	Triangle	Side 1		Side 2
		1		3.0			4.0
		2		5.0			12.0
		3		8.0			15.0
*/

#include<iostream>
#include<iomanip>
#include<vector>

inline double hypotenuse(const double& side1, const double& side2) {
	return (side1 * side1) + (side2 * side2);
}

int HypotenuseCalculations() {
	typedef std::vector<double> vector;

	std::vector<vector> sides{
			{3.0, 5.0, 8.0 },
			{4.0, 12.0, 15.0 },
	};

	std::cout << std::fixed << std::setprecision(2)
		<< "Triangle" << std::setw(9)
		<< "Side 1" << std::setw(12)
		<< "Side 2" << std::setw(14)
		<< "Hypotenuse" << std::endl;

	for (int column{ 0 }; column < sides.at(0).size(); column++) {

		double sideOne{ sides.at(0).at(column) };
		double sideTwo{ sides.at(1).at(column) };
		double hypotenuses{ hypotenuse(sideOne, sideTwo) };

		std::cout << std::setw(4) << column + 1
			<< std::setw(13) << sideOne
			<< std::setw(12) << sideTwo
			<< std::setw(14) << hypotenuses
			<< std::endl;
	}

	return 0;
}