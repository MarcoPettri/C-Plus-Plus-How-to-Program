// Exercise 17.x: Rethrowing Exceptions
/*
	Write a program that illustrates rethrowing an exception.
*/

#include <iostream>
#include <exception>


void throwException() {

    try {
 
        throw std::exception{"Function throwException throws an exception"};
    }
    catch (const std::exception&) {

        throw; // rethrow exception 
    }

}

int RETHROWING_EXCEPTIONS() {

    try {
        std::cout << "main invokes function throwException" << std::endl;
        throwException();
    }
    catch (const std::exception& e) { // handle exception
        std::cout << "\nException handled in main:\n" << e.what() << std::endl;
    }

    return 0;
}