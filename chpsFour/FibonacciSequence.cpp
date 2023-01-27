// 4.30 Exercise: Fibonacci Sequence
// Prints the Fibonacci Sequence

#include<iostream>

using std::cout; using std::cin;

int FibonacciSequence() {

	int term{ 0 };
	int primerT{ 0 }, secondT{ 1 }, next{ 1 };
	
	cout << "Enter a posetive number: ",
		cin >> term;
	
	cout << "Fibonacci Series: "
		<< primerT << ", " << secondT << ", ";

	while (next <= term) {

		cout << next << ", ";

		primerT = secondT;
		secondT = next;
		next = primerT + secondT;
	}


	return 0;
}