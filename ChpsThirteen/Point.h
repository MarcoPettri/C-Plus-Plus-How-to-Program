//Point.h
/*
		
		Point Class for exercise 13.15: Point Class
*/


#ifndef POINT_h
#define POINT_h

#include <iostream>


class Point {

	friend std::istream& operator>>(std::istream&, Point&);
	friend std::ostream& operator<<(std::ostream&, const Point&);

	
	int xCoordinate;
	int yCoordinate;
};


#endif POINT_h