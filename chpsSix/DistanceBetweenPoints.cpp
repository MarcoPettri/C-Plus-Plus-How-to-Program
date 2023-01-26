//6.42 Exercise: Distance Between Points

/*

	Write function distance that calculates the distance between two points(x1, y1) 
	and (x2, y2).All numbers and return values should be of type double.
*/

#include<iostream>
#include<cmath>


double distance(double, double, double, double);

int DistanceBetweenPoints() {

	double point1[]{ 3.0, 2.0 };
	double point2[]{ 9.0, 7.0 };



	std::cout << "Distance between (" << point1[0] << ", " << point1[1]
		<< ") and (" << point2[0] << ", " << point2[1] << ") = "
		<< distance(point1[0], point1[1], point2[0], point2[1]);

	return 0;
}

double distance(double x1, double y1, double x2, double y2) {
	
	double radicand{ std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2) };

	return std::sqrt(radicand);

}