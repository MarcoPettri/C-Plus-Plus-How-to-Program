//SavingsAccount.h
/*

	SavingsAccount class for exercise 12.13: Polymorphic Banking Program Using Account Hierarchy

*/


#ifndef SAVINGS2_ACCOUNT_H
#define SAVINGS2_ACCOUNT_H

#include "Account2.h"


class SavingsAccount2 : public Account2 {

public:
	SavingsAccount2(double bal, double init_rat);
	~SavingsAccount2() = default;

	virtual std::string to_string() const override;
			void		setInterestRate(double);
			double		getInterestRate() const;
			double		calculateInterest() const;


private:
	double interestRate;

};

#endif // !SAVINGS2_ACCOUNT_H
