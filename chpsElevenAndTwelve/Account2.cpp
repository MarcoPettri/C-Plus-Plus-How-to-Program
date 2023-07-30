//Account2.cpp
/*

	Account2 class definitions 

*/

#include "Account2.h"


Account2::Account2(double bal)
{
	setBalance(bal);
}

void Account2::credit(double amount)
{
	if (amount < 0.0f) {
		throw std::invalid_argument("Amount must be positive");
	}

	this->balance += amount;
}

bool Account2::debit(double amount)
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

void Account2::setBalance(double rhs)
{
	if (rhs < 0.0) {
		throw std::invalid_argument("initial balance invalid: must be >= 0.00");
	}
	this->balance = rhs;
}

std::string Account2::to_string() const
{
	std::ostringstream out;
	out << "Balance: " << this->balance;

	return out.str();
}
