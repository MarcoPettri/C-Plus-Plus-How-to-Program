// 4.33 and 4.34  Exercise: Sides of a Triangle and sides of a right Triangle

 /* reads three nonzero double value and determines and prints whether they could represent the sides of a triangle
 and if they're sides of a right triangle */


#include<iostream>

using std::cout; using std::cin;

int triangle() {

	double a{ 0 }, b{ 0 }, c{ 0 };

	cout << "Enter three integers separated by spaces: ",
		cin >> a >> b >> c;

	if ((a + b > c) && (a + c > b) && (b + c > a)) {
		cout << "The sides form a tringle";

		if ((pow(a, 2) + pow(b, 2)) == pow(c, 2)) {
			cout << " and they're the sides of a right Triangle";
		}
	}
	else {
		cout << "The sides don't form a triangle";
	}



	return 0;
}

