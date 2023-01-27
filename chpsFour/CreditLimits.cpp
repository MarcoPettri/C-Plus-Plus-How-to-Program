// 4.14  Credit Limits exercise 

#include <iostream>
#include <iomanip>

using std::cout; using std::cin; using std::endl;
using std::fixed; using std::setprecision;


int creditLimits() {

	unsigned int account{ 0 };

	cout << "Enter account number (-1 to quit): ",
		cin >> account;

	while (account != -1) {

		double balance, charges, credits, limit;

		cout << setprecision(2) << fixed;

		cout << "Enter the beginning balance: ",
			cin >> balance;
		cout << "Enter total charges: ",
			cin >> charges;
		cout << "Enter total credits: ",
			cin >> credits;
		cout << "Enter credit limit: ",
			cin >> limit;

		cout << "New balance is: " 
			<< balance + charges - credits << endl;

		if ((balance + charges - credits) > limit) {

			cout << "Account: " << account << endl
				<< "Credit limits: " << limit << endl
				<< "Balance: " << balance + charges - credits  << endl
				<< "Credit Limits Exeeced." << endl;
		}

		cout << "\nEnter account number (-1 to quit): ",
			cin >> account;
	}




	return 0;
}
