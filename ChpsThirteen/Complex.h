// Complex_h

/*

	Complex Class for exercise 13:16: Complex Class
*/


#ifndef COMPLEX_H
#define COMPLEX_H


#include<iostream>

class Complex
{
	friend std::istream& operator>>(std::istream&, Complex&);
	friend std::ostream& operator<<(std::ostream&, const Complex&);


	int real{ 0 };
	int imaginary{ 1 };
};


#endif COMPLEX_H