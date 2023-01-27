// 4.26 Exercise: Square Of Asterisks

/*reads the size of the side of a square, then
prints a hollow square of that size out of asterisksand blank*/

#include<iostream>
#include <string>

using std::cout; using std::cin;
using std::endl; using std::string;

int SquareOfAsterisks() {

	int amount{ 0 };

	cout << "Enter the size of the side of a square: ",
		cin >> amount;
	
	while (amount != -1) {

		if ((1 < amount) && (amount <= 20) ) {

			string asterisks(amount, '*');
			string hollows(amount -2, ' ');

			for (int i = 0; i <= amount; i++) {

				if ((i == 0) || (i == amount)) {
					cout << asterisks << endl;
				}
				else {
					
					cout << "*" << hollows << "*" << endl;
				}
			}
		}
		else {
			cout << "the side sizes should be between 2 and 20" << endl;

		}
		cout << "Enter the size of the side of a square (-1 to end): ",
			cin >> amount;
	}
	

	return 0;
}