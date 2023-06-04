// Rational.cpp

// Rational class member-functions definitions

#include "Rational.h"

Rational::Rational(int divident, int divisor)
{
	if (divisor)
	{
		int gcd = std::gcd(divident, divisor);

		divident /= gcd;
		divisor /= gcd;

		numerator = divident;
		denominator = divisor;
	}
	else
	{
		throw std::invalid_argument(
			"ZeroDivisionError: division by zero"
		);
	}
}

void Rational::add(Rational other)
{
	if (this->denominator == other.denominator)
	{
		this->numerator += other.numerator;
	}
	else {

		this->numerator = (this->numerator * other.denominator) + (other.numerator * this->denominator);
		this->denominator *= other.denominator;

		int gcd = std::gcd(this->numerator, this->denominator);

		this->numerator /= gcd;
		this->denominator /= gcd;
	}
}


void Rational::subtract(Rational other)
{
	if (this->denominator == other.denominator)
	{
		this->numerator -= other.numerator;
	}
	else {

		this->numerator = (this->numerator * other.denominator) - (other.numerator * this->denominator);
		this->denominator *= other.denominator;

		int gcd = std::gcd(this->numerator, this->denominator);

		this->numerator /= gcd;
		this->denominator /= gcd;
	}
}

void Rational::multiply(Rational other)
{
	this->numerator *= other.numerator;
	this->denominator *= other.denominator;

	int gcd = std::gcd(this->numerator, this->denominator);

	this->numerator /= gcd;
	this->denominator /= gcd;
}

void Rational::divide(Rational other)
{
	this->numerator *= other.denominator;
	this->denominator *= other.numerator;

	int gcd = std::gcd(this->numerator, this->denominator);

	this->numerator /= gcd;
	this->denominator /= gcd;
}

std::string Rational::toRationalString() const
{
	std::ostringstream out;
	{
		this->denominator != 1 ? out << this->numerator << "/" << this->denominator
			: out << this->numerator;
	}
	

	return out.str();
}

double Rational::toDouble() const
{
	return static_cast<double>(this->numerator) / this->denominator;
}