// Polynomial.H
/*
		Polynomial Class for exercise 10.11: Polynomial Class
*/

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H


#include<ostream>
#include<string>
#include<vector>


class Polynomial
{
	friend std::ostream& operator<<(std::ostream&, const Polynomial&);

public:
	Polynomial(const std::string&); // Default Constructor
	Polynomial(const Polynomial&); // Copy Constructor
	Polynomial(const std::vector<std::string>&);

	// Assignment Operators // 
	const Polynomial& operator=(const Polynomial&);
	const Polynomial& operator+=(const Polynomial&);
	const Polynomial& operator-=(const Polynomial&);
	const Polynomial& operator*=(const Polynomial&);
	const Polynomial& operator*=(double);

	// Arithmetic Operators //
	Polynomial operator+(const Polynomial&) const;
	Polynomial operator-(const Polynomial&) const;
	Polynomial operator*(const Polynomial&) const;
	Polynomial operator*(double) const;


private:
	std::vector<std::string> poly;
	void simplify();
	void sort_poly();

};


#endif // !POLYNOMIAL_H
