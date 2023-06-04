// Rectangle.cpp

// Rectangle class member-function definitions

#include "Rectangle.h"

Rectangle::Rectangle(float l, float w){
	setLength(l);
	setWidth(w);
}


//Getter functions
double Rectangle::perimeter() const { return 2 * (width + length); }
double Rectangle::area() const { return width * length; }
float Rectangle::getLength() const { return length; }
float Rectangle::getWidth() const { return width; }


// Setter functions

void Rectangle::setLength(float l) 
{
	if (0 < l && l < 20)
	{
		length = l;
	}
	else {
		throw std::invalid_argument(
			"the length must be greater than 0.0 and less than 20.0"
		);
	}
}

void Rectangle::setWidth(float w)
{
	if (0 < w && w < 20)
	{
		width = w;
	}
	else {
		throw std::invalid_argument(
			"the width must be greater than 0.0 and less than 20.0"
		);
	}
}