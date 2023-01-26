// 6.48 Exercise: Circle Area

/*
	Write a C++ program that prompts the user for the radius of a circle, then calls
	inline function circleArea to calculate the area of that circle.
*/

#include<iostream>
const double PI{ 3.1415 };

inline double circleArea(const double& radius) { return PI * (radius * radius); }

int Circle_Area() {

	double rad;
	std::cout << "Enter the radius of the circle: ",
		std::cin >> rad;

	std::cout << "The area of the circle is: "
		<< circleArea(rad);


	return 0;
}