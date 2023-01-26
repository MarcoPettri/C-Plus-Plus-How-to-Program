// 5.25  Exercise: Removing break and continue

/*	A criticism of the break statement and the continue statement is that each is unstructured.
	Actually, these statements can always be replaced by structured statements, although doing so can be awkward.
	Describe in general how you'd remove any break statement from a loop in a program and replace 
	it with some structured equivalent. [Hint:The break statement exits a loop from the body of the loop.
	The other way to exit is by failing the loop-continuation test.Consider using in the loop-continuation test 
	a second test that indicates “early exit because of a ‘break’ condition.”] Use the technique you develop here to remove 
	the break statement from the application in Fig. 5.13.
*/

// Fig. 5.13: BreakTest.cpp


#include <iostream>

int removingBreakAndContinue() {
	unsigned int count; // control variable also used after loop

	for (count = 1; count <= 10 && count != 5; count++) { // loop 10 times

		/*if (count == 5) {
			break;

		}*/

		std::cout << count << " ";

	}

	std::cout << "\nBroke out of loop at count = " << count << std::endl;

	return 0;
}