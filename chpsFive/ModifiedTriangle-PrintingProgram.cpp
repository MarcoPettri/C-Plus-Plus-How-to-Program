// 4.21 Exercise: Modified Triangle-Printing Program

/*
	 Modify Exercise 5.15 to combine your code from
	 the four separate triangles of asterisks such that all four patterns print side by side. 
	 [Hint: Make clever use of nested for loops.]
*/


#include<iostream>

int ModifiedTrianglePrintingProgram() {

	std::cout << "(a)\t(b)\t\t(c)\t(d)\n";
	for (unsigned int ast{ 1 }; ast <= 10; ast++) {

		//Pattern of the triangle (a)
		for (unsigned int a{ 1 }; a <= ast; a++) {

			std::cout << "*";
		}

		std::cout << "    ";

		// Pattern of the triangle (b)
		for (unsigned int b{ 10 }; b >= ast; b--) {
			std::cout << "*";
		}

		std::cout << "    ";

		// Pattern of the triangle (c)
		for (unsigned int c{ 10 }; c >= ast; c--) {
			std::cout << "*";
		}

		std::cout << "    ";

		// Pattern of the triangle (d)
		for (unsigned int d{ 1 }; d <= ast; d++) {

			std::cout << "*";
		}

		std::cout << "\n";
	}


	return 0;
}