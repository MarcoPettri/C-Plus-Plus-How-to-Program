//Exercise 14.6: File Matching

/*

				Exercise 14.3 asked you to write a series of single statements. Actually,
			these statements form the core of an important type of file-processing program, namely, a file-
			matching program. In commercial data processing, it's common to have several files in each application system. 
			In an accnt_numbers-receivable system, for example, there is generally a master file containing detailed information
			about each customer, such as the customer's name, address, telephone number, outstanding balance, credit limit, 
			discount terms, contract arrangements and, possibly, a condensed history of recent purchases and cash payments.
				As transactions occur (e.g., sales are made and cash payments arrive), they're entered into a
			file. At the end of each business period (a month for some companies, a week for others and a day
			in some cases), the file of transactions (called trans.dat in Exercise 14.3) is applied to the master
			file (called oldmast.dat in Exercise 14.3), thus updating each accnt_number's record of purchases and
			payments. During an updating run, the master file is rewritten as a new file (newmast.dat), which
			is then used at the end of the next business period to begin the updating process again.
				File-matching programs must deal with certain problems that do not exist in single-file pro-
			grams. For example, a match does not always occur. A customer on the master file might not have
			made any purchases or cash payments in the current business period, and therefore no record for
			this customer will appear on the transaction file. Similarly, a customer who did make some purchases 
			or cash payments may have just moved to this community, and the company may not have had a chance
			to create a master record for this customer.
				Use the statements from Exercise 14.3 as a basis for writing a complete file-matching
			accnt_numbers-receivable program. Use the accnt_number number on each file as the record key for matching
			purposes. Assume that each file is a sequential file with records stored in increasing order by
			accnt_number number.
				When a match occurs (i.e., records with the same accnt_number number appear on both the master
			and transaction files), add the dollar amount on the transaction file to the current balance on the
			master file, and write the newmast.dat record. (Assume purchases are indicated by positive
			amounts on the transaction file and payments are indicated by negative amounts.) When there is a
			master record for a particular accnt_number but no corresponding transaction record, merely write the
			master record to newmast.dat. When there is a transaction record but no corresponding master
			record, print the error message "Unmatched transaction record for accnt_number number ..." (fill in
			the accnt_number number from the transaction record).

*/


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>


void output(std::ofstream&, int, const std::string&, double);

int File_Matching()
{
    int         accnt_number;     // Account Number
    int         trans_accnt;     // Transaction Account Number
    double      accnt_balance;  // Account Balance
    double      trans_balance; // Transaction Balance
    std::string accnt_nme;    // Account Name


    std::ifstream inOldMaster{   "oldmaster.dat",   std::ios::in  };
    std::ifstream inTransaction{ "transaction.dat", std::ios::in  };
    std::ofstream outNewMaster{  "newmaster.dat",   std::ios::out };

    if (!inOldMaster) {
        std::cerr << "Unable to open oldmaster.dat\n";
        std::exit(EXIT_FAILURE);
    }

    if (!inTransaction) {
        std::cerr << "Unable to open transaction.dat\n";
        std::exit(EXIT_FAILURE);
    }

    if (!outNewMaster) {
        std::cerr << "Unable to open newmaster.dat\n";
        std::exit(EXIT_FAILURE);
    }

    std::cout << "Processing..." << std::endl;

    do {

        inTransaction >> trans_accnt >> trans_balance;

        inOldMaster >> accnt_number >> std::quoted(accnt_nme) >> accnt_balance;

        while (accnt_number < trans_accnt && !inOldMaster.eof()) {

            output(outNewMaster, accnt_number, accnt_nme, accnt_balance);
            inOldMaster >> accnt_number >> std::quoted(accnt_nme) >> accnt_balance;
        }

        if (accnt_number == trans_accnt) {

            accnt_balance += trans_balance;
        }
        else {
            std::cout << "Unmatched transaction record for account: "
                << trans_accnt << std::endl;
        }

        output(outNewMaster, accnt_number, accnt_nme, accnt_balance);

    } while (!inTransaction.eof() && !inOldMaster.eof());


    if (!inOldMaster.eof() || !inTransaction.eof()) {

        while (!inOldMaster.eof()) {

            inOldMaster >> accnt_number >> std::quoted(accnt_nme) >> accnt_balance;
            output(outNewMaster, accnt_number, accnt_nme, accnt_balance);
        }

        while (!inTransaction.eof()) {

            inTransaction >> trans_accnt >> trans_balance;
            std::cout << "Unmatched transaction record for account: " 
                << trans_accnt << std::endl;
        }
    }
   
    inTransaction.close();
    inOldMaster.close();
    outNewMaster.close();

    std::cout << "\nEnd." << std::endl;

    return 0;
}

void output(std::ofstream& out_nwMstr, int accnt_number, const std::string& accnt_nme, double accnt_blnce)
{
    out_nwMstr.setf(std::ios::fixed | std::ios::showpoint);
    out_nwMstr.precision(2);

    out_nwMstr << accnt_number << ' '
        << std::quoted(accnt_nme) << ' '
        << accnt_blnce << std::endl;
}