//DollarAmount.cpp

/*

		DollarAmount Class Member-Function Definitions

*/

#include "DollarAmount.h"

// Constructor //

DollarAmount::DollarAmount(std::int64_t integer, std::int16_t cents)
	: amount{ integer * 100 + cents } { }


// Assignment Operators // 

const DollarAmount& DollarAmount::operator+=(const DollarAmount& rhs) 
{
	amount += rhs.amount;

	return *this;
}

const DollarAmount& DollarAmount::operator-=(const DollarAmount& rhs) 
{
	amount -= rhs.amount;

	return *this;
}

const DollarAmount& DollarAmount::operator/=(const DollarAmount& rhs)
{ return *this /= (rhs.amount / 100.f); }

const DollarAmount& DollarAmount::operator*=(const DollarAmount& rhs)
{ return *this *= (rhs.amount / 100.f); }



const DollarAmount& DollarAmount::operator+=(double rhs)
{
	this->amount += static_cast<std::int64_t>(rhs * 100);
	
	return *this; 
}

const DollarAmount& DollarAmount::operator-=(double rhs)
{
	this->amount -= static_cast<std::int64_t>(rhs * 100);

	return *this;
}

const DollarAmount& DollarAmount::operator/=(double divisor)
{
	
	if (divisor < 0.f) { 
		divisor *= -1; 
	}
	else if (static_cast<int>(divisor) == 0) {
		throw std::overflow_error("ZeroDivisionError: division by zero"); 
	}

	this->amount /= divisor;

	return *this;
}


const DollarAmount& DollarAmount::operator*=(double rhs)
{
	this->amount *= rhs;
	return *this;
}


// Arithmetic Operators //

DollarAmount DollarAmount::operator+(double rhs) const
{
	std::int64_t total{ 
		static_cast<std::int64_t>(this->amount + (rhs * 100)) 
	};

	return DollarAmount(total / 100, total % 100);
}

DollarAmount DollarAmount::operator-(double rhs) const
{
	std::int64_t difference{ 
		static_cast<std::int64_t>(this->amount - (rhs * 100)) 
	};

	return DollarAmount(difference / 100, difference % 100);
}

DollarAmount DollarAmount::operator/(double rhs) const
{
	std::int64_t quotient{ 
		static_cast<std::int64_t>(this->amount / rhs) 
	};

	return DollarAmount(quotient / 100, quotient % 100);
}

DollarAmount DollarAmount::operator*(double rhs) const
{
	std::int64_t product{ 
		static_cast<std::int64_t>(this->amount * rhs)
	};

	return DollarAmount(product / 100, product % 100);
}


// Utility Function //

const DollarAmount& DollarAmount::addInterest(unsigned rate, unsigned divisor) {

	// Calculate the interest 
	std::int64_t total{ (amount * rate + divisor / 2) / divisor };

	amount += total;
	// Banker's rounding technique // 
	if ( amount % 100 > 0) {

		std::int64_t integer{ amount / 100 };
		std::int64_t cents{ amount % 100 };

		if (integer % 2 == 0) {
			amount -= cents;
		}
		else {
			amount += 100 - cents;
		}
	}

	return *this;
}


// Stream Insertion Operator //

std::ostream& operator<<(std::ostream& out, const DollarAmount& rhs) 
{
	out << rhs.amount / 100 << "."
		<< (std::abs(rhs.amount % 100) < 10 ? "0" : "") 
		<< std::abs(rhs.amount % 100);

	return out;
}

