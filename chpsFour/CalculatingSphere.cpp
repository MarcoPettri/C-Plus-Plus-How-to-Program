// 4.31 Exercise: Calculating sphere's circumference, area and  volumen
// Reads the radius of a sphere and computes the circumference, area and volume of the sphere

#define _USE_MATH_DEFINES

#include<iostream>


using std::cout; using std::cin; using std::endl; 

int sphereCalculation() {

	double r{ 0.0 };

	cout << "Input the sphere's radius: ",
		cin >> r;

	cout << "The area of the sphere is = " << 4 * M_PI * pow(r, 2) << endl
		<< "The Circumference is  = " << 2 * M_PI * r << endl
		<< "The volumen is = " << static_cast<double>(4) / 3 * M_PI * pow(r, 3) << endl;

	return 0;
}