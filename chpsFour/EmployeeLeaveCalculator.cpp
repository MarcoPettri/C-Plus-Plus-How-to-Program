// 4.15 Employee Leave Calculator

#include<iostream>
#include<iomanip>

using std::cout; using std::cin;
using std::endl; using std::fixed;
using std::setprecision;

int employeeLeaveCalculator() {


	double hours;
	cout << "Enter the hours worked (-1 to end): ",
		cin >> hours;

	while (hours != -1) {

		double plus{ 0.1 * hours };

		cout << setprecision(2) << fixed;
		cout << "Accrued leave: " << 2 + plus << endl;

		cout << "Enter the hours worked (-1 to end): ",
			cin >> hours;

	}


	return 0;
}