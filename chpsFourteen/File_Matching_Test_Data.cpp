// Exercise 14.17: File Matching Test Data
/*

		After writing the program of Exercise 14.6, write a simple program 
		to create some test data for checking out the program. 
		Use the sample account data in Figs. 14.14–14.15
*/


#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<string>
#include<vector>


struct Account
{
	std::string name;	   // Account Name
	int			number;	  // Account Number
	double		balance; // Account balance

};

struct Transaction
{
	int		number;  // Account Number 
	double	amount; // Transaction Amount
};

int File_Matching_Test_Data()
{
	std::ofstream outOldMaster{   "oldmaster.dat",	 std::ios::out };
	std::ofstream outTransaction{ "transaction.dat", std::ios::out };

	if (!outOldMaster) {
		std::cerr <<  "Unable to open oldmaster.dat" << std::endl;
		std::exit(EXIT_FAILURE);
	}

	if (!outTransaction) {
		std::cerr << "Unable to open transaction.dat" << std::endl;
		std::exit(EXIT_FAILURE);
	}


	std::vector<Account*> accounts{
		new Account{"Alan Jones", 100,  348.17},
		new Account{"Mary Smith", 300,  27.19},
		new Account{"Sam Sharp",  500,  0.00},
		new Account{"Suzy Green", 700, -14.22}
	};	

	std::vector<Transaction*> transactions{
		new Transaction{100, 27.14},
		new Transaction{300, 62.11},
		new Transaction{400, 100.56},
		new Transaction{900, 82.17}
	};

	outOldMaster.setf(std::ios::fixed   | std::ios::showpoint);
	outTransaction.setf(std::ios::fixed | std::ios::showpoint);

	outOldMaster.precision(2);
	outTransaction.precision(2);

	for (const Account* accnt: accounts ) {

		outOldMaster << accnt->number << ' '
			<< std::quoted(accnt->name) << ' '
			<< accnt->balance << std::endl;

		delete accnt;
	}

	for (const Transaction* trans : transactions) {

		outTransaction << trans->number 
			<< trans->amount << std::endl;

		delete trans;
	}

	outOldMaster.close();
	outTransaction.close();

	return 0;
}
