// TwoDayPackage2.cpp

/*
	TwoDayPackage2 Class Definitions

*/

#include "TwoDayPackage2.h"

#include<sstream>

TwoDayPackage2::TwoDayPackage2(const std::string& from_nme, const std::string& to_nme,
	const std::string& from_addr, const std::string& to_addr,
	const std::string& from_cty, const std::string& to_cty,
	const std::string& from_stat, const std::string& to_stat,
	const std::string& from_zip, const std::string& to_zip,
	double wght, double cst, double _fee)
	: Package2(from_nme, to_nme, from_addr, to_addr,
		from_cty, to_cty, from_stat, to_stat,
		from_zip, to_zip, wght, cst), fee{ _fee } { }

double TwoDayPackage2::calculateCost() const
{
	return Package2::calculateCost() + this->fee;
}

std::string TwoDayPackage2::to_string() const
{
	std::ostringstream out;

	out << Package2::to_string()  << "\nFlat Fee: " << this->fee;

	return out.str();
}
