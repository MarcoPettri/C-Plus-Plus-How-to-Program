//PhoneNumber.cpp
/*
	PhoneNumber Class definitions
*/


#include "PhoneNumber.h"
#include <regex>
#include <stdexcept>


std::ostream& operator<<(std::ostream& out, const PhoneNumber& rhs)
{
	
	out << "Area code: " << rhs.areaCode
		<< "\nExchange: " << rhs.exchange 
		<< "\nLine: " << rhs.line << "\n"
		<< "(" << rhs.areaCode << ") " 
		<< rhs.exchange << "-" << rhs.line << std::endl;

	return out;
}

std::istream& operator>>(std::istream& input, PhoneNumber& rhs)
{
	// Pattern in the format = (555) 555-5555
	const std::regex PATTERN{ R"x(\((\d{3})\)\s(\d{3})\-(\d{4}))x" }; 
	std::cmatch match; 

	const int MAX_CHAR{ 15 }; // taking into account the null character ('\0') is added 1 
	char string[MAX_CHAR]; 

	input.getline(string, MAX_CHAR, '\n');

	// Test that the proper pattern and numbers of characters has been entered
	if (std::regex_match(string, match, PATTERN)) {

		/* 
		*   Test the first digit of the area-code and exchange.
		*   The area code and exchange do not begin with 0 or 1.
		*/
		if (match[1].str().front() > 1 && 
			match[2].str().front() > 1) {

			// Test the middle digit for a value of 0 or 1.
			if (match[1].str().at(1) > 1) {

				rhs.areaCode = match[1];
				rhs.exchange = match[2];
				rhs.line	 = match[3];
			}
			else { input.clear(std::ios::failbit); }
		}
		else { input.clear(std::ios::failbit); }
	

	}
	else { input.clear(std::ios::failbit); }
	

	if(input.fail()){ 

		using std::string_literals::operator""s;
		throw std::invalid_argument("Invalid Phone Number: "s + string);
	}

	return input;

}