// 4.16 Fundraising initiative Calculator exercise

#include<iostream>
#include<iomanip>

using std::cout; using std::cin;
using std::endl; using std::setprecision;
using std::fixed;

int FundraisingInitiativeCalculator() {

	int laps{ 0 };
	double total{ 0.0 }, rate{ 0.0 };

	cout << setprecision(2) << fixed;

	cout << "Enter laps complete (-1 to end): ",
		cin >> laps;

	while (laps != -1) {

		cout << "Enter the sponsortship rate: ",
			cin >> rate;
		

		if (laps > 40) {

			cout << "Student contribution is: "
				<< ((0.5 * rate) + rate) * laps << endl;

			total += ((0.5 * rate) + rate) * laps;
		}
		else {
			cout << "Student contribution is: "
				<< rate * laps << endl;

			total += rate * laps;
		}

		cout << "\nEnter laps complete (-1 to end): ",
			cin >> laps;
	}

	cout << "Total funds raise: " << total;

	return 0;
}