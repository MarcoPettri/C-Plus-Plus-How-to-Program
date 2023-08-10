// Exercise 13.15: Point Class

/*
		Write a program that accomplishes each of the following:

			a) Create a user-defined class Point that contains the private integer data members
			xCoordinate and yCoordinate and declares stream insertion and stream extraction over-
			loaded operator functions as friends of the class.

			b) Define the stream insertion and stream extraction operator functions. The stream ex-
			traction operator function should determine whether the data entered is valid, and, if
			not, it should set the failbit to indicate improper input. The stream insertion operator
			should not be able to display the point after an input error occurred.

			c) Write a main function that tests input and output of user-defined class Point, using the
			overloaded stream extraction and stream insertion operators.

*/

#include "Point.h"

int Point_Class()
{
	Point root;

	std::cout << "Enter the x-y coordinates int the form (x, y): ",
		std::cin >> root;

	std::cout << root << std::endl;

	return 0;
}