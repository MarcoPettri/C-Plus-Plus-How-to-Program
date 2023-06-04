// HugeInteger.h

/*
		HugeInteger class for exercise 9.12: HugeInteger class
*/

#ifndef HUGE_INTEGER_H
#define HUGE_INTEGER_H

#include<string>
#include<iostream>
#include<cstddef>
#include<algorithm>
#include<vector>
#include<stdexcept>
#include<cctype>

class HugeInteger
{
public:

	HugeInteger(const std::string& integer);

	static const int MAX_SIZE{ 40 };

// Utility functions
	void output() const; // Display HugeInteger
	void input(const std::string& integer); // Update HugeInteger
	int  at(int i) const; // Returns the i-th position (accepts negative index)
	std::size_t size() const; // Returns the current size of the HugeInteger
// Operation Functions
	void add(const HugeInteger&) const; 
	void subtract(const HugeInteger&) const;
// Predicate Functions
	bool isEqualTo(const HugeInteger&) const;
	bool isNotEqualTo(const HugeInteger&) const;
	bool isGreaterThan(const HugeInteger&) const;
	bool isLessThan(const HugeInteger&) const;
	bool isGreaterThanOrEqualTo(const HugeInteger&) const;
	bool isLessThanOrEqualTo(const HugeInteger&) const;
	bool isZero() const;

private:
	std::vector<int> integer;
	void setInteger(const std::string&);
};


#endif // !HUGE_INTEGER_H
