// 4.20 Exercise: Pythagorean Triples
/*
    A right triangle can have sides whose lengths are all integers. The set
    of three integer values for the lengths of the sides of a right triangle is called a Pythagorean triple.
    The lengths of the three sides must satisfy the relationship that the sum of the squares of two of the
    sides is equal to the square of the hypotenuse. Write an application that displays a table of the
    Pythagorean triples for side1, side2 and the hypotenuse, all no larger than 500. Use a triple-nested
    for loop that tries all possibilities. This is an example of “brute-force” computing. You’ll learn in
    more advanced computer-science courses that for many interesting problems there’s no known algorithmic approach 
    other than using sheer brute force.
*/

#include<iostream>
#include<iomanip>
#include<cmath>

int PythagoreanTriples() {

    std::cout << std::setw(9) << "Side 1 "
        << std::setw(10) << "Side 2 "
        << std::setw(14) << "Hypotenuse" 
        << std::endl;

    for (unsigned int side1{ 1 }; side1 <= 500; side1++) {

        for (unsigned int side2{ side1 + 1 }; side2 <= 500; side2++) {

            for (unsigned int hypotenuse{ side2 + 1 }; hypotenuse <= 500; hypotenuse++) {

                if (std::pow(side1, 2) + std::pow(side2, 2) == std::pow(hypotenuse, 2)) {

                    std::cout << std::setw(5) << side1
                        << std::setw(10) << side2
                        << std::setw(12) << hypotenuse
                        << std::endl;
                }
            }
        }
    }

    return 0;
}