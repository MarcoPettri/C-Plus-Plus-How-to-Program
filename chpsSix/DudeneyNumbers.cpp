//6.28 (Dudeney Numbers) 

/*
	A Dudeney number is a positive integer that is a perfect cube such
	that the sum of its digits is equal to the cube root of the number.There are exactly seven such
	integers.Write a function isDudeney to test if a parameter number is a Dudeney number.Use this
	function in a program that determines and prints the first 3 Dudeney integers.Then challenge the
	power of your computer by finding all 7 Dudeney numbers.Make use of the <cmath> cube root
	function, cbrt.
*/
	
#include<iostream>
#include<vector>
#include<cmath>

bool isDudeney(unsigned int number);

int DudeneyNumbers() {

	//int dudeneyNumber{ 19'683 } // for test
	
	std::vector<unsigned> dudeneyNumebrs;

	for (unsigned int numbers{ 0 }; dudeneyNumebrs.size() < 7; numbers++) {

		if (isDudeney(numbers)) {
			dudeneyNumebrs.push_back(numbers);
		}
	}
	std::cout << "Dudeney Numbers: ";
	for (auto& numbers : dudeneyNumebrs) {

		std::cout << numbers 
			<< (numbers != dudeneyNumebrs.back() ? ", " : "");
	}


	return 0;
}


bool isDudeney(unsigned int number) {

	unsigned int cbrt{ 
		static_cast<unsigned int>(std::cbrt(number) )
	};

	if (std::pow(cbrt, 3) == number) {

		int digitSum{ 0 };

		while (number > 0) {

			digitSum += number % 10;
			number /= 10;
		}

		if (digitSum == cbrt) { return true; }
		else { return false; }
	}
	else {
		return false;
	}
}

