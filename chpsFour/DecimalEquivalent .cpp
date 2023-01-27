// 4.28 Exercise: Printing the Decimal Equivalent of a Binary Number
//Input an integer containing only 0  and 1  and print its decimal equivalent

#include<iostream>
#include<string>
#include<cmath>

using std::cout; using std::cin; using std::endl;
using std::string; using std::to_string; using std::pow;

int ToDecimal() {


	int number{ 0 };

	cout << "Enter the number to change from binary to decimal system: ",
		cin >> number;

	while (number != -1) {

		string binary{ to_string(number) };

		unsigned int power{ static_cast<unsigned int>(binary.length())};

		unsigned int decimal{ 0 };

		for (int i = 0; i < power; i++) {

			decimal += (static_cast<int>(binary[i] - 48) * pow(2, (power -1) - i));

		}

		cout << "Binary: " << number << endl
			<< "Decimal: " << decimal << endl;

		cout << "Enter another number to change to the decimal system (-1 to end): ",
			cin >> number;

	}

	return 0;
}