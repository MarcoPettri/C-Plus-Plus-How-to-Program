// ChekingAccount2.cpp

/*
	CheckingAccount2 Class Definitions

*/

#include"CheckingAccount2.h"


CheckingAccount2::CheckingAccount2(double bal, double fee)
	:Account2(bal)
{
	setFee(fee);
}

void CheckingAccount2::setFee(double rhs)
{
	if (rhs < 0.0f) {
		throw std::invalid_argument("Thee Fee must be >= 0");
	}

	this->fee = rhs;
}

void CheckingAccount2::credit(double amount)
{
	Account2::credit(amount - this->fee);

}

bool CheckingAccount2::debit(double amount)
{
	if (Account2::debit(amount)) {
		this->setBalance(this->getBalance() - this->fee);
		return true;
	}
	return false;
}

std::string CheckingAccount2::to_string() const
{
	std::ostringstream out;
	out << Account2::to_string() << "\nFee: " << this->fee;

	return out.str();
}

