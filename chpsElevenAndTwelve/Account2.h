//Account2.h
/*

	Account2 class for exercise 12.13: Polymorphic Banking Program Using Account Hierarchy

*/


#ifndef ACCOUNT2_H
#define ACCOUNT2_H

#include<iostream>
#include<stdexcept>
#include<sstream>

class Account2 {

public:
	Account2(double);
	virtual ~Account2() = default;

	virtual void		  credit(double);
	virtual bool		  debit(double);
	virtual std::string	  to_string() const;
	inline double		  getBalance() const { return balance; }
			void		  setBalance(double);


private:
	double balance;
};

#endif ACCOUNT2_H
