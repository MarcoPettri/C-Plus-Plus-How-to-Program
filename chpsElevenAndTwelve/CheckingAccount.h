//CheckingAccount.h

/*
	CheckingAccount Class for exercise 11.10: Account Inheritance Hierarchy

*/


#ifndef CHECKING_ACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"
class CheckingAccount: Account
{
	friend std::ostream& operator<<(std::ostream&, const CheckingAccount&);

public:
	CheckingAccount(double bal, double fee);
	~CheckingAccount() = default;
	void   credit(double);
	void   debit(double);
	void   setFee(double);
	double getFee() const { return fee; }


private:
	double fee;
};

#endif // !CHECKING_ACCOUNT_H
