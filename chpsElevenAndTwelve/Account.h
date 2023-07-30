//Account.h

/*
	Account Class for Exercise 11.10: Account Inheritance Hierarchy 

*/

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<iostream>

class Account {

	friend std::ostream& operator<<(std::ostream&, const Account&);
public:
	Account(double);
	~Account() = default;

			void  credit(double);
			bool  debit(double);
			void  setBalance(double);
	inline double getBalance() const { return balance; }


private:
	double balance;
};

#endif ACCOUNT_H


