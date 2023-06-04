// Exercise 9.11: Rectangle Class
/*
* 
		Create a class Rectangle with attributes length and width, each of which
		defaults to 1. Provide member functions that calculate the perimeter and the area of the rectangle.
		Also, provide set and get functions for the length and width attributes. The set functions should verify
		that length and width are each floating-point numbers larger than 0.0 and less than 20.0.
		
*/


#include<iostream>
#include "Rectangle.h"

int RectangleClass()
{
	Rectangle rect{ 12, 5 };


	std::cout << "Width = " << rect.getWidth() << '\n'
		<< "Length = " << rect.getLength() << std::endl;

	std::cout << "Perimeter = " << rect.perimeter() << '\n'
		<< "Area = " << rect.area() << std::endl;


	return 0;
}