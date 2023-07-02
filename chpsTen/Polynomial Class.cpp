// Exercise:: Polynomial Class

/*
			Develop class Polynomial. The internal representation of a Polynomial
			is an array of terms. Each term contains a coefficient and an exponent—e.g.,
			the term 2x^4 has the coefficient 2 and the exponent 4. Develop a complete class
			containing proper constructor and destructor functions as well as set and get functions.
			The class should also provide the following overloaded operator capabilities:

				a) Overload the addition operator (+) to add two Polynomials.
				b) Overload the subtraction operator (-) to subtract two Polynomials.
				c) Overload the assignment operator to assign one Polynomial to another.
				d) Overload the multiplication operator (*) to multiply two Polynomials.
				e) Overload the addition assignment operator (+=), subtraction assignment operator (-=),
				and multiplication assignment operator (*=).


*/



#include "Polynomial.h"
#include<iostream>

int POLYNOMIAL_CLASS() {



	Polynomial poly{ "+2.8x^3 +3x^2 + x +24" };
	Polynomial poly2{ "344.44 +4x^3 + 2.33x^4 -44x  -x^2" };


	std::cout << "Poly1: " << poly << std::endl;
	std::cout << "Poly2: " << poly2 << std::endl;

	std::cout << "\nPoly1 + Poly2:\n" << (poly + poly2) << std::endl;
	std::cout << "\nPoly1 - Poly2:\n" << (poly - poly2) << std::endl;


	poly *= 3;
	std::cout << "\n\nPoly1 *= 3:\n" << poly << std::endl;

	Polynomial poly3{ poly * poly2 };
	std::cout << "\n\nPoly1 * Poly2:\n" << poly3 << std::endl;




	return 0;
}