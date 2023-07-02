
// DollarAmount.h

/*

	DollarAmount Class for exercise 10.12: DollarAmount Class Enhancement
*/

#ifndef DOLLAR_AMOUNT_H
#define DOLLAR_AMOUNT_H


#include<iostream>
#include<stdexcept>
#include<cstdint>
#include<cmath>


class DollarAmount {

	friend std::ostream& operator<<(std::ostream&, const DollarAmount&);
public:

	//Initialize amount from an int64_t value
	DollarAmount(std::int64_t integer, std::int16_t cents);

	 // Assignment Operators // 
	const DollarAmount& operator+=(const DollarAmount&);
	const DollarAmount& operator-=(const DollarAmount&);
	const DollarAmount& operator/=(const DollarAmount& rhs);
	const DollarAmount& operator*=(const DollarAmount& rhs);

	const DollarAmount& operator+=(double);
	const DollarAmount& operator-=(double);
	const DollarAmount& operator/=(double);
	const DollarAmount& operator*=(double);

	// Arithmetic Operators //
	DollarAmount operator+(const DollarAmount& rhs) const { return *this + (rhs.amount / 100.f); }
	DollarAmount operator-(const DollarAmount& rhs) const { return *this - (rhs.amount / 100.f); }
	DollarAmount operator/(const DollarAmount& rhs) const { return *this / (rhs.amount / 100.f); }
	DollarAmount operator*(const DollarAmount& rhs) const { return *this * (rhs.amount / 100.f); }

	DollarAmount operator+(double) const;
	DollarAmount operator-(double) const;
	DollarAmount operator/(double) const;	
	DollarAmount operator*(double) const;	


	// uses integer arithmetic to calculate interest amount //
	const DollarAmount& addInterest(unsigned rate, unsigned divisor);

private:
	int64_t amount;

};

#endif // !DOLLAR_AMOUNT_H
