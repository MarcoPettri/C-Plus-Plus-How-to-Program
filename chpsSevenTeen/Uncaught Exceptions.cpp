//Exercise 17.x: Uncaught Exceptions
/*

        Write a program that illustrates that a function with its own try
        block does not have to catch every possible error generated within the try. Some exceptions can slip
        through to, and be handled in, outer scopes.
*/

#include <iostream>
#include <stdexcept>     


void function_2() {

    try {
        std::cout << "function_2 throw underflow_erro" << std::endl;
        throw std::underflow_error{""};
    }
    catch (const std::overflow_error&) {
        std::cout << "Overflow_error is handled in function 2" << std::endl;
    }
    
    // stack unwinding occurs //

    try {
        std::cout << "this line never is executed" << std::endl;
    }
    catch (const std::underflow_error&) {
        std::cout << "This line never is executed" << std::endl;
    }

}

void function() {

    try {
        std::cout << "function1 call function_2" << std::endl;
        function_2();
    }
    catch (const std::underflow_error&) {
        std::cout << "underflow_error is handled in function 1" << std::endl;
    }
}

int UNCAUGHT_EXCEPTIONS() {

    std::cout << "function1 is called inside main" << std::endl;
    function();

    return 0;
}
