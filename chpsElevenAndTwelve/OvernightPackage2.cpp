// OvernightPackage2.cpp

/*
	OvernigthPackage2 Class Definitions

*/

#include "OvernightPackage2.h"
#include<sstream>

OvernightPackage2::OvernightPackage2(const std::string& from_nme, const std::string& to_nme,
	const std::string& from_addr, const std::string& to_addr,
	const std::string& from_cty, const std::string& to_cty,
	const std::string& from_stat, const std::string& to_stat,
	const std::string& from_zip, const std::string& to_zip,
	double wght, double cst, double _fee)
	: Package2(from_nme, to_nme, from_addr, to_addr,
		from_cty, to_cty, from_stat, to_stat,
		from_zip, to_zip, wght, cst), fee{ _fee } { }

double OvernightPackage2::calculateCost() const
{
	return (this->get_weight() + this->fee) * this->get_cost();
}

std::string OvernightPackage2::to_string() const
{
	std::ostringstream out;

	out << Package2::to_string()  << "\nFee Per Ounce: " << this->fee;

	return out.str();
}
