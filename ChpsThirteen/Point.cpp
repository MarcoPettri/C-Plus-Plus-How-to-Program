//Point.cpp

/*
		Point Class definitions
*/


#include "Point.h"
#include <regex>
#include <string>

std::istream& operator>>(std::istream& input, Point& rhs)
{
	
	const std::regex  PATTERN{ R"x(\((\d+)\,\s*(\d+)\))x" };
	std::smatch		  match;
	std::string		  string;
	
	std::getline(input, string, '\n');


	if (std::regex_match(string, match, PATTERN)) {
		
		rhs.xCoordinate = std::stoi(match[1]);
		rhs.yCoordinate = std::stoi(match[2]);

		return input;
	}

	 input.clear(std::ios::failbit); 

	return input;
}

std::ostream& operator<<(std::ostream& out, const Point& rhs)
{
	
	
	if (std::cin.fail()) {

		out << "Invalid Coordinates";

		return out;
	}

	out << "(" << rhs.xCoordinate << ", " << rhs.yCoordinate << ")";
	return out;
}
