// SavingsAccount2.cpp

/*
	SavingsAccount2 Class Definitions

*/

#include "SavingsAccount2.h"



SavingsAccount2::SavingsAccount2(double bal, double init_rat)
	:Account2(bal)
{
	setInterestRate(init_rat);
}

double SavingsAccount2::getInterestRate() const { return this->interestRate; }

std::string SavingsAccount2::to_string() const
{
	std::ostringstream out;
	out << Account2::to_string() << "\nInterest Rate : " << this->interestRate;
	return out.str();
}

void SavingsAccount2::setInterestRate(double rhs)
{
	if (0.0f < rhs && rhs < 1.0f) {
		this->interestRate = rhs;
		return;
	}

	throw std::invalid_argument("Interest rate must be greater than 0 and less than 1.");


}
double SavingsAccount2::calculateInterest() const { return this->interestRate * this->getBalance(); }


