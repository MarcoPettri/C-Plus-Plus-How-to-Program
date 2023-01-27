// 4.13 Fual Usage exercise

#include<iostream>
#include<iomanip>

using std::cout; using std::cin; 
using std::endl; using std::fixed;
using std::setprecision; 


int usageExercise() {
	
	double ToalKms{ 0 };
	int litersUsed{ 0 };
	int kilometersDriven;

	cout << "Enter Kilometers Driven (-1 to quit): ", 
		cin >> kilometersDriven;


	while (kilometersDriven != -1) {
		
		int liters;

		cout << "Enter liters used: ",
			cin >> liters;

		ToalKms += kilometersDriven;
		litersUsed += liters;

		cout << setprecision(4) << fixed;

		cout << "kms per liter this trip: " 
			<< static_cast<double>(kilometersDriven) / liters  << endl;

		cout << "Total the kms per liters: "
			<< ToalKms / static_cast<double>(litersUsed) << endl;

		cout << "Enter Kilometers Driven (-1 to quit): ",
			cin >> kilometersDriven;
	}

	return 0;
}