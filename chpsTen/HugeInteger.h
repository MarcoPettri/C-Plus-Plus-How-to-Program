//HugeInteger.h
/*

		HugeInteger Class for exercise 10.9: HugeInteger Class
		
*/

#ifndef HugeInteger_H
#define HugeInteger_H

#include<vector>
#include<string>
#include<iostream>
#include<stdexcept>
#include<cctype>
#include<cstddef>
#include<algorithm>

class HugeInteger {
	friend std::ostream& operator<<(std::ostream&, const HugeInteger&);

public:
	static const int MAX_SIZE{ 40 }; // maximum digits in a HugeInteger

	// Constructors //

	HugeInteger(unsigned long long = 0); // conversion/default constructor
	HugeInteger(const std::string&); // conversion constructor

	// Addition and subtraction operators //
	
	void operator+(const HugeInteger&) const;
	void operator+(unsigned long long) const;
	void operator-(const HugeInteger&) const;
	void operator-(unsigned long long) const;

	// HugeInteger + string that represents large integer value
	void operator+(const std::string&) const;	

	// HugeInteger - string that represents large integer value
	void operator-(const std::string&) const;


	// comparison operator //
	bool operator==(const HugeInteger&) const;
	bool operator!=(const HugeInteger& rhs) const { return !(*this == rhs); }

	bool operator<(const HugeInteger&) const;
	bool operator>(const HugeInteger& rhs) const { return  (rhs < *this); }
	bool operator<=(const HugeInteger& rhs) const { return !(*this > rhs); }
	bool operator>=(const HugeInteger& rhs) const { return !(*this < rhs); }

	// Utility functions // 
	bool isZero() const;
	int  at(int i) const; // Returns the i-th position (accepts negative index)
	std::size_t size() const; // Returns the current size of the HugeInteger

private:
	std::vector<int> integer;
	void setInteger(const std::string&);
};

#endif
