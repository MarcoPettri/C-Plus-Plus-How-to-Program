//HugeInteger.cpp

// HugeInteger class member-functions definitions

#include "HugeInteger.h"

// Constructors //

// default constructor
HugeInteger::HugeInteger(unsigned long long value) {
	
	setInteger(std::to_string(value));
}

// conversion constructor
HugeInteger::HugeInteger(const std::string& integ)
{
	setInteger(integ);
}


// Addition and subtraction operators //


// HugeInteger + int
void HugeInteger::operator+(unsigned long long rhs) const { return *this + HugeInteger(rhs); }


// HugeInteger + string that represents large integer value
void HugeInteger::operator+(const std::string& rhs) const {

	return *this + HugeInteger(rhs);
}

void HugeInteger::operator+(const HugeInteger& rhs) const
{

	std::vector<int>total;

	int self_length{ static_cast<int>(integer.size()) - 1 };
	int rhs_length{ static_cast<int>(rhs.integer.size()) - 1 };
	int carry{ 0 };

	for (; (self_length >= 0) && (rhs_length >= 0);
		self_length--, rhs_length--) {

		int x = integer.at(self_length) + rhs.integer.at(rhs_length) + carry;
		total.push_back(x % 10);
		carry = x / 10;  // The carry  is the remaining number after forming the digit of final sum.

	}
	// If the self_length > rhs_length or rhs_length > self_length, then there must be some digits to be taken care off.
	if (self_length || rhs_length) {

		// Add the remaining digits to the carry one by one and store the unit digit.
		while (self_length >= 0) {
			int x{ integer.at(self_length) + carry };
			total.push_back(x % 10);
			carry = x / 10;
			self_length--;
		}

		while (rhs_length >= 0) {
			int x{ rhs.integer.at(rhs_length) + carry };
			total.push_back(x % 10);
			carry = x / 10;
			rhs_length--;
		}
	}

	//If after finishing the addition of the two numbers, there is still carry then it is stored digit by digit.
	while (carry) {
		total.push_back(carry % 10);
		carry /= 10;
	}

	//the most significant digits starts at the end of the vector. Therefore, it prints backwards.
	for (int i{ static_cast<int>(total.size()) - 1 }; i >= 0; i--) {

		std::cout << total[i];
		if (not(i % 3) && i != 0) { std::cout << ','; }

	}
	std::cout << std::endl;
}


// HugeInteger - unsigned
void HugeInteger::operator-(unsigned long long rhs) const { return *this - HugeInteger(rhs); }


// HugeInteger - string that represents large integer value
void HugeInteger::operator-(const std::string& rhs) const { return *this - HugeInteger(rhs); }

// HugeInteger - HugeInteger
void HugeInteger::operator-(const HugeInteger& rhs) const {
	

	int left_operando_length { static_cast<int>(integer.size()) - 1 };
	int rhs_operando_length { static_cast<int>(rhs.integer.size()) - 1 };
	bool isLess { false };
	std::vector<int> leftOperand { integer };
	std::vector<int> rhsOperand { rhs.integer };
	std::vector<int> total;

	
	if (rhs_operando_length >= left_operando_length ) {

		if (rhs_operando_length > left_operando_length 
			|| rhs > *this) {

			std::swap(leftOperand, rhsOperand);
			std::swap(left_operando_length, rhs_operando_length);

			isLess = true;
		}
		else if (*this == rhs) {
			std::cout << '0';
			return;
		}
	}


	for (int minuend{ 0 }, subtrahend{ 0 }, difference{ 0 }; 
		(left_operando_length >= 0) && (rhs_operando_length >= 0);
		--left_operando_length, --rhs_operando_length) {
	
		minuend = leftOperand[left_operando_length];
		subtrahend = rhsOperand[rhs_operando_length];

		if (minuend >= subtrahend) {
			difference = minuend - subtrahend;
		}
		else {
			difference = 10 + minuend - subtrahend;
	
			if (left_operando_length != 0) { leftOperand[left_operando_length -1] -= 1; }
		}
		total.push_back(difference);
	}
	
	while (left_operando_length >= 0) {
			total.push_back(leftOperand[left_operando_length]);
			left_operando_length--;
	}

	if (isLess) { std::cout << '-'; }

	for (int i{ static_cast<int>(total.size()) -1 }; i >= 0; --i) {
		
	
		std::cout << total[i]; 

		if (not(i % 3) && i != 0) { std::cout << ','; }
	}

	std::cout << std::endl;

}


// comparison and equality operators //


bool HugeInteger::operator==(const HugeInteger& rhs) const
{
	std::size_t self_length{ integer.size() };

	if (self_length == rhs.integer.size()) {

		for (int i{ 0 }; i < self_length; ++i) {
			if (integer.at(i) != rhs.integer.at(i)) { return false; }
		}
		return true;
	}
	return false;
}

bool HugeInteger::operator<(const HugeInteger& rhs) const
{

	std::size_t self_length{ integer.size() };
	std::size_t rhs_length{ rhs.integer.size() };

	if (self_length == rhs_length) {

		for (int i{ 0 }; i < self_length; ++i) {

			if (integer.at(i) < rhs.integer.at(i)) { return true; }
			else if (integer.at(i) > rhs.integer.at(i)) { return false; }
		}
	}
	else if (integer.size() < rhs.integer.size()) { return true; }

	return false;
}


// Utility functions //


void HugeInteger::setInteger(const std::string& integ)
{
	
	std::size_t length{ integ.length() };

	if (length <= MAX_SIZE) {


		for (std::size_t index{ 0 }; index < length; ++index) {

			char digit{ integ[index] };

			if (std::isdigit(digit)) {
				integer.push_back(int(digit) - '0');
			}
			else {
				throw std::invalid_argument(
					"TypeError: All elements in the string must be integers "
				);
			}
		}

	}
	else {
		throw std::invalid_argument(
			"ValueError: HugeInteger cannot contain more than 40 digits"
		);
	}
}

bool HugeInteger::isZero() const {
	for (const int& n : integer) {
		if (n) { return false; }
	}
	return true;
}

int HugeInteger::at(int i) const
{
	if (-MAX_SIZE < i && i < MAX_SIZE) {
		return (i >= 0 ? integer[i] : integer[MAX_SIZE + i]);
	}
	else {
		throw std::out_of_range(
			"IndexError: index out of range"
		);
	}
}

std::size_t HugeInteger::size() const
{
	return integer.size();
}


std::ostream& operator<<(std::ostream& out, const HugeInteger& rhs) {
	
	std::size_t size{ rhs.integer.size() };

	if (size <= 3) {
		for (std::size_t i{ 0 }; i < size; i++) {
			out << rhs.integer[i];
		}
	}
	else {
		for (std::size_t i{ 0 }, tenths{ size - 1 };
			i < size; i++, tenths--) {

			out << rhs.integer[i];

			if (not(tenths % 3) && (i + 1) < size) {
				out << ',';
			}
		}
	}

	out << std::endl;

	return out;

}