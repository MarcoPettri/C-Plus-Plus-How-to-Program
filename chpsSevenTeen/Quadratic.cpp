//Quadratic.cpp

// Quadratic class member-function definitions 


#include "Quadratic.h"
#include "NoRealRootException.h"
 

Quadratic::Quadratic(double A, double B, double C, char Var)
	:var{ Var } {

	setQC(A);
	setLC(B);
	setConstant(C);
}

void Quadratic::add(const Quadratic& right)
{
	this->a += right.getQC();
	this->b += right.getLC();
	this->c += right.getConstant();
}

void Quadratic::subtract(const Quadratic& right)
{
	this->a -= right.getQC();
	this->b -= right.getLC();
	this->c -= right.getConstant();
}

void Quadratic::setCoefficients(double a, double b, double c)
{
	setQC(a);
	setLC(b);
	setConstant(c);
}

void Quadratic::setQC(double a)
{
	this->a = (a != 0 ? a : 1);
}

void Quadratic::setLC(double b)
{
	this->b = b;
}

void Quadratic::setConstant(double c)
{
	this->c = c;
}

std::string Quadratic::toString() const 
{
	std::ostringstream out;
	const double& a = getQC();
	const double& b = getLC();
	const double& c = getConstant();

	out << std::setprecision(2) << std::fixed;

	{a != 1 ? out << a << "x^2"
		: out << "x^2"; }

	if( b > 0) 
	{ 
		{b != 1 ? out << " + " << b << "x"
			: out << " + x"; }
	}

	else if (b < 0) { out << " " << b << "x"; }
	
	if (c > 0) { out << " + " << c; }

	else if (c < 0) { out << " " << c; }
	
	return out.str();
}

std::string Quadratic::solve() const
{
	std::ostringstream out;
	const double& a = getQC();
	const double& b = getLC();
	const double& c = getConstant();

	double discriminant{ b * b  -4 * a * c};

	if (discriminant > 0)
	{
		double root1{
			(-b + std::sqrt(discriminant)) / (2 * a)
		};		
		double root2{
			(-b - std::sqrt(discriminant)) / (2 * a)
		};

		out << "x1 = " << root1 << '\n'
			<< "x2 = " << root2;	
	}
	else if (discriminant == 0)
	{
		double roots{-b / (2 * a) };
		out << "x1 = x2 = " << roots;
	}
	else 
	{
		throw NoRealRootException{};
	}

	return out.str();
}