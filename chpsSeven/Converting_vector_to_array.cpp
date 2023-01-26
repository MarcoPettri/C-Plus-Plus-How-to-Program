// Exercise 7.19: Converting vector Example of Section 7.10 to array

/*
	Convert the vector example of
	Fig. 7.21 to use arrays. Eliminate any vector-only features.
*/


#include <iostream>
#include <iomanip>  
#include <array>   
#include <stdexcept>

void outputArray(const std::array<int, 7>&); // display the array
void outputArray(const std::array<int, 20>&); // display the array
void inputArray(std::array<int, 7>&); // input values into the array
void inputArray(std::array<int, 20>&); // input values into the array

int VectorToArray() {
    std::array<int, 7> integers1{};  
    std::array<int, 20> integers2{}; 

    // print integers1 size and contents
    std::cout << "Size of array integers1 is " << integers1.size()
        << "\narray after initialization: ";
    outputArray(integers1);

    // print integers2 size and contents
    std::cout << "\nSize of array integers2 is " << integers2.size()
        << "\narray after initialization: ";
    outputArray(integers2);

    // input and print integers1 and integers2
    std::cout << "\nEnter 7 integers:" << std::endl;
    inputArray(integers1);
    std::cout << "\nEnter 20 integers:" << std::endl;
    inputArray(integers2);

    std::cout << "\nAfter input, the arrays contain:\n"
        << "integers1: ";
    outputArray(integers1);
    std::cout << "integers2: ";
    outputArray(integers2);


    // create array integers3 using integers1 as an         
    // initializer; print size and contents                  
    std::array<int, 7> integers3{ integers1 }; // copy constructor

    std::cout << "\nSize of array integers3 is " << integers3.size()
        << "\narray after initialization: ";
    outputArray(integers3);


    // use square brackets to use the value at location 5 as an rvalue
    std::cout << "\nintegers1[5] is " << integers1[5];

    // use square brackets to create lvalue
    std::cout << "\n\nAssigning 1000 to integers1[5]" << std::endl;
    integers1[5] = 1000;
    std::cout << "integers1: ";
    outputArray(integers1);

    // attempt to use out-of-range subscript                     
    try {
        std::cout << "\nAttempt to display integers1.at(15)" << std::endl;
        std::cout << integers1.at(15) << std::endl; // ERROR: out of range
    }
    catch (std::out_of_range& ex) {
        std::cerr << "An exception occurred: " << ex.what() << std::endl;
    }

    return 0;

}

// output array contents
void outputArray(const std::array<int, 7>& items) {
    for (int item : items) {
        std::cout << item << " ";
    }

    std::cout << std::endl;
}
// output array contents
void outputArray(const std::array<int, 20>& items) {
    for (int item : items) {
        std::cout << item << " ";
    }

    std::cout << std::endl;
}

// input array contents
void inputArray(std::array<int, 7>& items) {
    for (int& item : items) {
        std::cin >> item;
    }
}
// input array contents
void inputArray(std::array<int, 20>& items) {
    for (int& item : items) {
        std::cin >> item;
    }
}