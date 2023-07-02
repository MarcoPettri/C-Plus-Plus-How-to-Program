// Quadratic.h
/*
	Quadratic class for Exercise 10.10 : Enhanced Quadratic Class

*/

#ifndef QUADRATIC_H
#define QUADRATIC_H

#include<string>
#include<ostream>
#include<sstream>
#include<iomanip>
#include<cmath>

class Quadratic {
	friend std::ostream& operator<<(std::ostream&, const Quadratic&);

public:
	// Constructor //
	Quadratic(double = 1, double = 0, double = 0, char = 'x');

	// Addition and Subtraction Operators // 
	const Quadratic& operator+(const Quadratic&);
	const Quadratic& operator-(const Quadratic&);

	// Solve Function //
	std::string solve() const;

	// Getter Functions
	double getQC() const { return a; } // Return Quadratic Coefficient
	double getLC() const { return b; } // Return Linear Coefficient
	double getConstant() const { return c; } // Return Constant coefficient
	char   getVar() const { return var; } // Return variable '

	// Setter Functions // 
	void setCoefficients(double, double, double); // Set Coefficients
	void setQC(double); // Set Quadratic Coefficient
	void setLC(double);	 // Set Linear Coefficient
	void setConstant(double); // Set Constant Coefficient
	void setVar(char); // Set Variable


private:
	double a;
	double b;
	double c;
	char var;
};


#endif QUADRATIC_H
