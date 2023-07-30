//SavingsAccount.cpp

/*
	SavingsAccount Class Definitions

*/

#include "SavingsAccount.h"
#include <stdexcept>


SavingsAccount::SavingsAccount(double bal, double init_rat)
	:Account(bal) 
{
	setInterestRate(init_rat);
}

double SavingsAccount::getInterestRate() const { return this->interestRate; }

void SavingsAccount::setInterestRate(double rhs)
{
	if (0.0f < rhs && rhs < 1.0f) {
		this->interestRate = rhs;
		return;
	}

	throw std::invalid_argument("Interest rate must be greater than 0 and less than 1.");


}
double SavingsAccount::calculateInterest() const { return this->interestRate * this->getBalance(); }

std::ostream& operator<<(std::ostream& out, const SavingsAccount& rhs)
{
	out << "Balance: " << rhs.getBalance()
		<< "\nInterest Rate: " << rhs.interestRate;

	return out;
}
