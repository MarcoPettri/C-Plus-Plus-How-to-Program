// Quadratic.h
/*
	Quadratic class for Exercise 17.x:	Exception Handling and Program Control

*/

#ifndef QUADRATIC_H
#define QUADRATIC_H

#include<string>
#include<iomanip>
#include<sstream>
#include<cmath>


class Quadratic {
public:
	//Constructor
	Quadratic(double = 1, double = 0, 
		double = 0, char = 'x');


	std::string toString() const;
	std::string solve() const;

	double getQC() const { return a; } // Return Quadratic Coefficient
	double getLC() const { return b; } // Return Linear Coefficient
	double getConstant() const { return c; } // Return Constant coefficient

	void add(const Quadratic&);
	void subtract(const Quadratic&);
	void setCoefficients(double, double, double); // Set Coefficients
	void setQC(double); // Set Quadratic Coefficient
	void setLC(double);	 // Linear Coefficient
	void setConstant(double); // set Constant coefficients



private:
	double a;
	double b;
	double c;
	char var;
};


#endif QUADRATIC_H
