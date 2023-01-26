//5.27 Exercise: Replacing continue with a Structured Equivalent

/*
	Describe in general how you’d remove any continue statement from a loop in a program
	and replace it with some structured equivalent. Use the technique you develop here to remove
	the continue statement from the program in Fig. 5.14
*/


// Fig. 5.14: ContinueTest.cpp
#include<iostream>

int ReplacingContinue() {

	for (unsigned int count{ 1 }; count <= 10; count++) { // loop 10 times

		/*	if (count == 5) {

				continue;
			} */

		std::cout << (count == 5 ? ++count : count) << " ";;

	}

	std::cout << "\nUsed continue to skip printing 5" << std::endl;


	return 0;
}





