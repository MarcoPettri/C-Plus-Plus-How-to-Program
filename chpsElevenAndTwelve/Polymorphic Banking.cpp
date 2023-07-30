//Exercise 12.13: Polymorphic Banking Program Using Account Hierarchy

/*

			Develop a polymorphic banking program using the Account hierarchy created in Exercise 11.10. 
		Create a vector of Account pointers to SavingsAccount and CheckingAccount objects. 
		For each Account in the vector, allow the user to specify an amount of money to withdraw 
		from the Account using member function debit and an amount of money to deposit into the Account 
		using member function credit. As you process each Account, determine its type. If an Account 
		is a SavingsAccount, calculate the amount of interest owed to the Account using member function calculateInterest, 
		then add the interest to the account balance using member function credit. After processing an Account, 
		print the updated account balance obtained by invoking base-class member function getBalance.
	

*/

#include<vector>
#include<typeinfo>

#include"Account2.h"
#include"CheckingAccount2.h"
#include"SavingsAccount2.h"


int Polymorphic_Banking()
{
	std::vector<Account2*> accounts{
		new CheckingAccount2{ 50.00, 4.75},
		new CheckingAccount2{ 84.00, 4.75},
		new SavingsAccount2{50.00, 0.75},
		new SavingsAccount2{442.00, 0.25}
	};

	for (Account2* accnts : accounts) {

		std::cout << "Type of account: " << typeid(*accnts).name() << "\n";

		bool sentinela;
		double amount;
		std::cout << accnts->to_string() << '\n';

		do {
		
			std::cout << "\nEnter the amount of money to be withdrawn from the account: ",
				std::cin >> amount;

		} while (not accnts->debit(amount));

		do {
			try {

				std::cout << "\nEnter an amount of money to deposit into the account: ",
					std::cin >> amount;

				accnts->credit(amount);

				sentinela = false;
			}
			catch (const std::invalid_argument& e) {

				std::cout << e.what() << std::endl;

				sentinela = true;
 			}

		} while (sentinela);

	
		SavingsAccount2* svgs_account{ dynamic_cast<SavingsAccount2*>(accnts) };

		if (svgs_account != nullptr) {
				double interest{ svgs_account->calculateInterest() };
				svgs_account->credit(interest);
		}

		std::cout << "\nAccount Balance Updated: " << accnts->getBalance() << "\n\n";

		delete accnts;
	}


	return 0;
}