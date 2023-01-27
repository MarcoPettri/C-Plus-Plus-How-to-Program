// 4.27 Exercise: Palindromes 
//The program reads a five-digit integer and determines whether it is a palindrome.

#include<iostream>

using std::cout; using std::cin; using std::endl;

int Palindrome() {

	int reverseNumber{ 0 }, number{ 0 };

	cout << "Enter the number: ",
		cin >> number;

	if (number > 0) {

		int integer{ number };

		while (number != 0) {

			reverseNumber *= 10;
			reverseNumber += number % 10;
			number /= 10;
		}

		if (integer == reverseNumber) {
			cout << "It's a Palindrome\n"
				<< integer << " = " << reverseNumber;
		}
		else {
			cout << "It isn't a Palindrome\n"
				<< integer << " != " << reverseNumber;
		}
	}
	else {
		cout << "The number must be positive" << endl;
	}
	
	

	return 0;
}



