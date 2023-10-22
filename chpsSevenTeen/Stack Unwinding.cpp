//Exercise 17.x: Stack Unwinding
/*

	 Write a program that throws an exception from a deeply nested function and still has the catch handler 
	 following the try block enclosing the initial call in main catch the exception.
*/

#include <iostream>
#include <stdexcept>     

void function3() {

    std::cout << "In function 3" << std::endl;
    // function3 throws runtime error
    throw std::runtime_error{ "runtime_error in function3" }; 
} 

void function2() {

    try {
        std::cout << "function3 is called inside function2" << std::endl;
        function3(); 
    }
    catch (const std::overflow_error&) {
        std::cout << "Overflow_error" << std::endl;
    }
    // stack unwinding occurs, return control to function1
}

void function1() {

    try {
        std::cout << "function2 is called inside function1" << std::endl;
        function2(); 
    }
    catch (const std::underflow_error&) {
        std::cout << "underflow_error" << std::endl;
    }
    // stack unwinding occurs, return control to main
}

int STACK_UNWINDING() {

    try {
        std::cout << "function1 is called inside main" << std::endl;
        function1(); 
    }
    catch (const std::runtime_error& except) { 
        std::cout << "Exception occurred: " << except.what() << std::endl;
    }

    return 0;
}

