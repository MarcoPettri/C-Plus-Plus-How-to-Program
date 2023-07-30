//CheckingAccount2.h
/*

	CheckingAccount2 class for exercise 12.13: Polymorphic Banking Program Using Account Hierarchy

*/

#ifndef CHECKING_ACCOUNT2_H
#define CHECKINGACCOUNT2_H

#include "Account2.h"

class CheckingAccount2: public Account2
{
public:

	CheckingAccount2(double bal, double fee);
	virtual ~CheckingAccount2() = default;

	virtual void		credit(double) override;
	virtual bool		debit(double) override;
	virtual std::string to_string() const override;
			void		setFee(double);
	inline double		getFee() const { return fee; }

private:
	double fee;
};

#endif // !CHECKING2_ACCOUNT_H
