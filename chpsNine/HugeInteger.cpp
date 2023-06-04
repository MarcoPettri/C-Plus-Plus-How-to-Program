//HugeInteger.cpp

// HugeInteger class member-functions definitions

#include "HugeInteger.h"

// constructor
HugeInteger::HugeInteger(const std::string& integ)
{
	setInteger(integ);
}

// Utility functions
void HugeInteger::setInteger(const std::string& integ)
{
	if (integ.length() <= MAX_SIZE) {


		for (std::size_t index{ 0 }; index < integ.length(); index++) {

			char str{ integ[index] };

			if (std::isdigit(str)) {
				integer.push_back( int(str) - '0');
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

void HugeInteger::input(const std::string& integ)
{
	integer.clear();
	setInteger(integ);
}

void HugeInteger::output() const 
{
	std::size_t size{ integer.size() };

	if (size <= 3) {
		for (std::size_t i{ 0 }; i < size; i++) {
			std::cout << integer[i];
		}
	}
	else {
		for (std::size_t i{ 0 }, tenths{ size - 1 };
			i < size; i++, tenths--) {

			std::cout << integer[i];

			if (not(tenths % 3) && (i + 1) < size) {
				std::cout << ',';
			}
		}
	}

	std::cout << std::endl;
}

int HugeInteger::at(int i) const
{
	if (i > -MAX_SIZE &&  i < MAX_SIZE) {
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

// Operation Functions

void HugeInteger::add(const HugeInteger& other) const
{

    std::vector<int>total; 

	int selfLength { static_cast<int>(integer.size()) - 1 };
	int otherLength { static_cast<int>(other.integer.size()) - 1 };
	int carry { 0 };

	for (; (selfLength >= 0) && (otherLength >= 0); 
		selfLength--, otherLength--) {    

        int x = integer.at(selfLength)  + other.integer.at(otherLength) + carry;
        total.push_back(x % 10); 
        carry = x / 10;  // The carry  is the remaining number after forming the digit of final sum.

    }
	// If the selfLength > otherLength or otherLength > selfLength, then there must be some digits to be taken care off.
	if (selfLength || otherLength) {

		// Add the remaining digits to the carry one by one and store the unit digit.
		while (selfLength >= 0) {          
			int x{ integer.at(selfLength) + carry };
			total.push_back(x % 10);
			carry = x / 10;            
			selfLength--;
		}

		while (otherLength >= 0) {  
			int x { other.integer.at(otherLength)  + carry };
			total.push_back(x % 10);
			carry = x / 10;       
			otherLength--;
		}
	}

	//If after finishing the addition of the two numbers, there is still carry then it is stored digit by digit.
    while (carry) {   
        total.push_back(carry % 10); 
        carry /=  10;       
    }
     //the most significant digits starts at the end of the vector. Therefore, it prints backwards.
	for (int i{ static_cast<int>(total.size()) -1 }; i >= 0; i--) {

		std::cout << total[i];
		if (not(i % 3) && i != 0) { std::cout << ','; }

    }
    std::cout << std::endl;
}

void HugeInteger::subtract(const HugeInteger& rigth) const
{	

	int leftOperandoLength { static_cast<int>(integer.size()) - 1 };
	int rigthOperandoLength { static_cast<int>(rigth.integer.size()) - 1 };
	bool isLess { false };
	std::vector<int> leftOperand { integer };
	std::vector<int> rigthOperand { rigth.integer };
	std::vector<int> total;

	
	if (rigthOperandoLength >= leftOperandoLength ) {

		if (rigthOperandoLength > leftOperandoLength 
			|| this->isLessThan(rigth)) {

			leftOperandoLength = static_cast<int>(rigth.integer.size())-1;
			rigthOperandoLength = static_cast<int>(integer.size()) -1;
			leftOperand = rigth.integer;
			rigthOperand = integer;
			isLess = true;
		}
		else if (this->isEqualTo(rigth)) {
			std::cout << '0';
			return;
		}
	}


	for (int minuend{ 0 }, subtrahend{ 0 }, difference{ 0 }; 
		(leftOperandoLength >= 0) && (rigthOperandoLength >= 0);
		leftOperandoLength--, rigthOperandoLength--) {
	
		minuend = leftOperand[leftOperandoLength];
		subtrahend = rigthOperand[rigthOperandoLength];

		if (minuend >= subtrahend) {
			difference = minuend - subtrahend;
		}
		else {
			difference = 10 + minuend - subtrahend;
	
			if (leftOperandoLength != 0) { leftOperand[leftOperandoLength -1] -= 1; }
		}
		total.push_back(difference);
	}
	
	while (leftOperandoLength >= 0) {
			total.push_back(leftOperand[leftOperandoLength]);
			leftOperandoLength--;
	}

	if (isLess) { std::cout << '-'; }

	for (int i{ static_cast<int>(total.size()) -1 }; i >= 0; i--) {
		
	
		std::cout << total[i]; 

		if (not(i % 3) && i != 0) { std::cout << ','; }
	}

	std::cout << std::endl;
}


// Predicate Functions

bool HugeInteger::isLessThan(const HugeInteger& other) const
{

	std::size_t selfLength{ integer.size() };
	std::size_t otherLength{ other.integer.size() };

	if (selfLength == otherLength) {

		for (int i{ 0 }; i < selfLength; i++) {

			if (integer.at(i) < other.integer.at(i)) { return true; }
			else if (integer.at(i) > other.integer.at(i)) { return false; }
		}
	}
	else if (integer.size() < other.integer.size()) { return true; }

	return false;
}

bool HugeInteger::isZero() const
{
	for (const int& n : integer) {
		if (n) { return false; }
	}
	return true;
}

bool HugeInteger::isEqualTo(const HugeInteger& other) const 
{
	std::size_t selfLength{ integer.size() };

	if (selfLength == other.integer.size()) {

		for (int i{ 0 }; i < selfLength; i++) {
			if (integer.at(i) != other.integer.at(i)) { return false; }
		}
		return true;
	}
	return false;
}

bool HugeInteger::isNotEqualTo(const HugeInteger& other) const
{
	return not this->isEqualTo(other);
}

bool HugeInteger::isGreaterThan(const HugeInteger& other) const
{
	std::size_t selfLength{ integer.size() };
	std::size_t otherLength{ other.integer.size() };

	if (selfLength == otherLength) {

		for (int i{ 0 }; i < selfLength; i++) {

			if (integer.at(i) > other.integer.at(i)) { return true; }
			else if (integer.at(i) < other.integer.at(i)) { return false; }
		}
	}
	else if (integer.size() > other.integer.size()) { return true; }

	return false;
}

bool HugeInteger::isGreaterThanOrEqualTo(const HugeInteger& other) const
{
	if (this->isGreaterThan(other) 
		|| this->isEqualTo(other)) {
		return true;
	}
	return false;
}

bool HugeInteger::isLessThanOrEqualTo(const HugeInteger& other) const
{
	if (this->isLessThan(other) 
		|| this->isEqualTo(other)) { return true; }

	return false;

}




