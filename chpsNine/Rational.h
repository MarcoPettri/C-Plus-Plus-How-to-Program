// Rational.h
/*
	Rational Class for Exercise 9.6: Rational Class

*/

#ifndef RATIONAL_H
#define RATIONAL_H

#include<string>
#include<sstream>
#include<numeric>
#include<stdexcept>

class Rational
{
public:
	Rational(int = 1, int = 1);

	void add(Rational);
	void subtract(Rational);
	void multiply(Rational);
	void divide(Rational);

	std::string toRationalString() const;
	double toDouble() const;

private:
	int numerator;
	int denominator;
};

#endif // !RATIONAL_H


