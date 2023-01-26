// 5.15 Exercise: Triangle-Printing Program

/*  
	Write an application that displays the following patterns separately, one below the other. 
	Use for loops to generate the patterns. All asterisks (*) should be printed by a single statement of the form cout << '*'; 
	which causes the asterisks to print side by side. A statement of the form cout << '\n'; can be used to move to the next line. 
	A statement of the form cout << ' '; can be used to display a space for the last two patterns. 
	There should be no other output statements in the program. 
	[Hint: The last two patterns require that each line begin with an appropriate number of blank spaces.]
					(a)			(b)				(c)		   (d)
					*		**********		**********      *
					**		 *********		*********      **
					***		  ********		********      ***
					****	   *******		*******      ****
					*****		******		******      *****
					******		 *****		*****      ******
					*******		  ****		****      *******
					********	   ***		***      ********
					*********		**		**      *********
					**********		 *		*	  ***********	
*/


#include<iostream>

int TrianglePrintingProgram() {

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