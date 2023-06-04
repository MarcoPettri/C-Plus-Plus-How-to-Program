// Rectangle.h

/*

		Rectangle Class for exercise 9.11: Rectangle class
*/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stdexcept>

class Rectangle {
public:
	Rectangle(float length = 1, float width = 1);

//Getter functions
	double perimeter() const;
	double area() const;
	float getLength() const;
	float getWidth() const;

// Setter functions
	void setLength(float);
	void setWidth(float);


private:
	float length;
	float width;
};

#endif // !RECTANGLE_H
