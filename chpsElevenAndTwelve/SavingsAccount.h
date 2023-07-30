// SavingsAccount.h

/*
	SavingsAccount Class for exercise 11.10: Account Inheritance Hierarchy
*/


#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "Account.h"


class SavingsAccount: public Account {

	friend std::ostream& operator<<(std::ostream&, const SavingsAccount&);

public:
	SavingsAccount(double bal, double init_rat);
	~SavingsAccount() = default;

	void   setInterestRate(double);
	double getInterestRate() const;
	double calculateInterest() const;
	

private:
	double interestRate;

};

#endif // !SAVINGS_ACCOUNT_H
