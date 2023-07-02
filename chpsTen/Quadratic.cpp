//Quadratic.cpp

/* 
	Quadratic class member - function definitions 
*/


#include "Quadratic.h"

// Constructor //
Quadratic::Quadratic(double A, double B, double C, char Var)
	:var{ Var } {

	setQC(A);
	setLC(B);
	setConstant(C);
}

// Addition and subtraction Operators // 
const Quadratic& Quadratic::operator+(const Quadratic& rhs)
{
	this->a += rhs.getQC();
	this->b += rhs.getLC();
	this->c += rhs.getConstant();

	return *this;
}

const Quadratic& Quadratic::operator-(const Quadratic& rhs)
{
	this->a -= rhs.getQC();
	this->b -= rhs.getLC();
	this->c -= rhs.getConstant();
	
	return *this;
}

// Setter Functions //
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

void Quadratic::setVar(char var)
{
	this->var = var;
}

// Solve Member Function //
std::string Quadratic::solve() const
{
	std::ostringstream out;
	const double& a = getQC();
	const double& b = getLC();
	const double& c = getConstant();

	double discriminant{ b * b - 4 * a * c };

	if (discriminant > 0)
	{
		double root1{
			(-b + std::sqrt(discriminant)) / (2 * a)
		};
		double root2{
			(-b - std::sqrt(discriminant)) / (2 * a)
		};

		out << "x_1 = " << root1 << '\n'
			<< "x_2 = " << root2;
	}
	else if (discriminant == 0)
	{
		double roots{ -b / (2 * a) };
		out << "x1 = x2 = " << roots;
	}
	else
	{
		out << "No Real Roots.";
	}
	out << std::endl;

	return out.str();
}


// Insertion Operator //
std::ostream& operator<<(std::ostream& out, const Quadratic& rhs)
{
	
	const double& a = rhs.getQC();
	const double& b = rhs.getLC();
	const double& c = rhs.getConstant();

	out << std::setprecision(2) << std::fixed;

	{a != 1 ? out << a << "x^2"
		: out << "x^2"; }

	if (b > 0)
	{
		{b != 1 ? out << " + " << b << "x"
			: out << " + x"; }
	}

	else if (b < 0) { out << " " << b << "x"; }

	if (c > 0) { out << " + " << c; }

	else if (c < 0) { out << " " << c; }
	
	out << " = 0" << std::endl;

	return out;
}

