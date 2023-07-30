// ChekingAccount.cpp

/*
	CheckingAccount Class Definitions

*/

#include"CheckingAccount.h"
#include<stdexcept>

CheckingAccount::CheckingAccount(double bal, double fee)
	:Account(bal) 
{
	setFee(fee);
}

void CheckingAccount::setFee(double rhs)
{
	if (rhs < 0.0f) {
		throw std::invalid_argument("Thee Fee must be >= 0");
	}

	this->fee = rhs;
}

void CheckingAccount::credit(double amount)
{
	Account::credit(amount - this->fee);

}

void CheckingAccount::debit(double amount)
{
	if (Account::debit(amount)) {
		this->setBalance(this->getBalance() - this->fee);
	}
}

std::ostream& operator<<(std::ostream& out, const CheckingAccount& rhs)
{
	out << "Balance: " << rhs.getBalance()
		<< "\nFee: " << rhs.fee;

	return out;
} 
