//6.45 Exercise: Math Library Functions
/*
		 Write a program that tests as many of the math library functions
		in Fig. 6.2 as you can. Exercise each of these functions by having your program print out tables of
		return values for a diversity of argument values
*/


#include <iostream>
#include <iomanip>
#include <cmath>
#include<cstdlib>


int MathLibraryFunctions() {

    
    std::cout << std::fixed << std::setprecision(3);
    std::cout << "Testing the math library functions.";

    std::srand(static_cast<unsigned int>(std::time(NULL)));

    for (int i{ 0 }; 5 >= i ; i++){

        double value{ double(1 + std::rand() % 6)};
        double value2{ double(1 + std::rand() % 9)};

        std::cout << "\n\nsqrt(" << value << ") = " << sqrt(value)
            << "\nexp(" << value << ") = " << exp(value)
            << "\nexp(" << value2 << ") = " << exp(value2)
            << "\nlog(" << value << ") = " << log(value)
            << "\nlog(" << value2 << ") = " << log(value2)
            << "\nlog10(" << value << ") = " << log10(value)
            << "\nlog10(" << value2 << ") = " << log10(value2)
            << "\nfabs(" << value << ") = " << fabs(value)
            << "\nfabs(" << value2 << ") = " << fabs(value2)
            << "\nceil(" << value << ") = " << ceil(value)
            << "\nceil(" << value2 << ") = " << ceil(value2)
            << "\nfloor(" << value << ") = " << floor(value)
            << "\nfloor(" << value2 << ") = " << floor(value2)
            << "\npow(" << value << ", " << i << ") = " << pow(value2, i) 
            << "\npow(" << value2 << ", " << i << ") = " << pow(value2, i)
            << "\nfmod(" << value2 << ", " << value << ") = " << fmod(value2, value)
            << "\nsin(" << value << ") = " << sin(value)
            << "\ncos(" << value2 << ") = " << cos(value2)
            << "\ntan(" << value << ") = " << tan(value) << std::endl;
    }
    return 0;
}
