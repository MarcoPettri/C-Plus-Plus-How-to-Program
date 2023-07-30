// Account.cpp

/*
	Account Class Definitions
*/


#include<stdexcept>
#include"Account.h"

Account::Account(double bal) {
	setBalance(bal);
}

void Account::credit(double amount)
{
	if (amount < 0.0f) {
		throw std::invalid_argument("Amount must be positive");
	}

	this->balance += amount;
}

bool Account::debit(double amount) 
{
	if (amount > this->balance) {
		std::cout << "Debit amount exceeded account balance." << std::endl;

		return false;
	}
	else if (amount < 0.0f) {
		throw std::invalid_argument("Amount must be positive");
	}

	this->balance -= amount;
	return true;
}

void Account::setBalance(double rhs)
{
	if (rhs < 0.0) {
		throw std::invalid_argument("initial balance invalid: must be >= 0.00");
	}
	this->balance = rhs;
}

std::ostream& operator<<(std::ostream& out, const Account& rhs)
{
	out << "Balance: " << rhs.balance;
	return out;
}
