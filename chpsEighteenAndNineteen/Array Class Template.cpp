// Exercise 18.x: Array Class Template
/*
		Reimplement class Array from Figs. 10.10–10.11 as a class template. 
		Exercise each of the new Array class template's capabilities in a program.

*/



#include <stdexcept>
#include "Array.hpp"

int ARRAY_CLASS_TEMPLATE() {
    Array<int> integers1{ 7 }; 
    Array<int> integers2; 

    std::cout << "Size of Array integers1 is " << integers1.getSize()
        << "\nArray after initialization: " << integers1;

   
    std::cout << "\nSize of Array integers2 is " << integers2.getSize()
        << "\nArray after initialization: " << integers2;

    std::cout << "\nEnter 17 integers:" << std::endl;
    std::cin >> integers1 >> integers2; //  19 20 40 42 25 2 40 40 18 15 16 82 75 20 81 76 55

    std::cout << "\nAfter input, the Arrays contain:\n"
        << "integers1: " << integers1
        << "integers2: " << integers2;


    std::cout << "\nEvaluating: integers1 != integers2" << std::endl;

    if (integers1 != integers2) {
        std::cout << "integers1 and integers2 are not equal" << std::endl;
    }

                 
    Array<int> integers3{ integers1 }; 

    std::cout << "\nSize of Array integers3 is " << integers3.getSize()
        << "\nArray after initialization: " << integers3;

    std::cout << "\nAssigning integers2 to integers1:" << std::endl;
    integers1 = integers2; 

    std::cout << "integers1: " << integers1 << "integers2: " << integers2;

    std::cout << "\nEvaluating: integers1 == integers2" << std::endl;

    if (integers1 == integers2) {
        std::cout << "integers1 and integers2 are equal" << std::endl;
    }


    std::cout << "\nintegers1[5] is " << integers1[5];

    std::cout << "\n\nAssigning 1000 to integers1[5]" << std::endl;
    integers1[5] = 1000;
    std::cout << "integers1:\n" << integers1;

    // attempt to use out-of-range subscript
    try {
        std::cout << "\nAttempt to assign 1000 to integers1[15]" << std::endl;
        integers1[15] = 1000; 
    }
    catch (std::out_of_range& ex) {
        std::cout << "An exception occurred: " << ex.what() << std::endl;
    }

    return 0;
}
