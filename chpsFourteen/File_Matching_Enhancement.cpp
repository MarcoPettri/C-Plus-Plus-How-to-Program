// Exercise 14.9: File-Matching Enhancement
/*
	
			It's common to have several transaction records with the
		same record key, because a particular customer might make several purchases and cash payments
		during a business period. Rewrite your accounts-receivable file-matching program of Exercise 14.6
		to provide for the possibility of handling several transaction records with the same record key. 
		Modify the test data of Exercise 14.7 to include the additional transaction records in Fig. 14.16.
*/


#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<vector>


void add_transactions(std::fstream&);
void output(std::ofstream&, int, const std::string&, double);

int File_Matching_Enhancement()
{
	int         accnt_number;     // Account Number
	int         trans_accnt;     // Transaction Account Number
	double      accnt_balance;  // Account Balance
	double      trans_balance; // Transaction Balance
	std::string accnt_nme;    // Account Name



	std::ifstream inOldMaster{		"oldmaster.dat",   std::ios::in };
	std::ofstream outNewMaster{		"newmaster.dat",   std::ios::out };
	std::fstream  inOutTransaction{ "transaction.dat", std::ios::in | std::ios::out};

	if (!inOldMaster) {
		std::cerr << "Unable to open oldmaster.dat" << std::endl;
		std::exit(EXIT_FAILURE);
	}

	if (!inOutTransaction) {
		std::cerr << "Unable to open transaction.dat" << std::endl;
		std::exit(EXIT_FAILURE);
	}

	if (!outNewMaster) {
		std::cerr << "Unable to open newmaster.dat" << std::endl;
		std::exit(EXIT_FAILURE);
	}


	std::cout << "Processing..." << std::endl;

	add_transactions(inOutTransaction); // Adding Transactions
	
	inOutTransaction >> trans_accnt >> trans_balance;

	inOldMaster >> accnt_number >> std::quoted(accnt_nme) >> accnt_balance;

	while (!inOutTransaction.eof() && !inOldMaster.eof()) {

		if (accnt_number > trans_accnt) {

			std::cout << "Unmatched transaction record for account: "
				<< trans_accnt << std::endl;

			output(outNewMaster, accnt_number, accnt_nme, accnt_balance);

			inOutTransaction >> trans_accnt >> trans_balance;

			inOldMaster >> accnt_number >> std::quoted(accnt_nme) >> accnt_balance;
		}

		while (accnt_number < trans_accnt && !inOldMaster.eof()) {

			output(outNewMaster, accnt_number, accnt_nme, accnt_balance);
			inOldMaster >> accnt_number >> std::quoted(accnt_nme) >> accnt_balance;
		}

		while (accnt_number == trans_accnt && !inOutTransaction.eof()) {

			accnt_balance += trans_balance;

			output(outNewMaster, accnt_number, accnt_nme, accnt_balance);
			inOutTransaction >> trans_accnt >> trans_balance;
		}

	}


	if (!inOldMaster.eof() || !inOutTransaction.eof()) {

		while (!inOldMaster.eof()) {

			inOldMaster >> accnt_number >> std::quoted(accnt_nme) >> accnt_balance;
			output(outNewMaster, accnt_number, accnt_nme, accnt_balance);
		}

		while (!inOutTransaction.eof()) {

			inOutTransaction >> trans_accnt >> trans_balance;
			std::cout << "Unmatched transaction record for account: "
				<< trans_accnt << std::endl;
		}
	}

	inOutTransaction.close();
	inOldMaster.close();
	outNewMaster.close();

	std::cout << "\nEnd." << std::endl;

	return 0;
}

void add_transactions(std::fstream& out_transactions)
{

	struct Transaction
	{
		int		number;		// Account number
		double	balance;	// Transaction Amount
	};


	std::vector<Transaction*> transactions{

		new Transaction{100, 27.14},
		new Transaction{300, 62.11},
		new Transaction{300, 83.89},
		new Transaction{400, 100.56},
		new Transaction{700, 80.78},
		new Transaction{700, 1.53},
		new Transaction{900, 82.17},

	};

	out_transactions.setf(std::ios::fixed | std::ios::showpoint);
	out_transactions.precision(2);

	for (const Transaction* trans : transactions) {

		out_transactions << trans->number
			<< trans->balance << std::endl;

		delete trans;
	}

}

void output(std::ofstream& out_nwMstr, int accnt_number, const std::string& accnt_nme, double accnt_blnce)
{
	out_nwMstr.setf(std::ios::fixed | std::ios::showpoint);
	out_nwMstr.precision(2);

	out_nwMstr << accnt_number << ' '
		<< std::quoted(accnt_nme) << ' '
		<< accnt_blnce << std::endl;
}