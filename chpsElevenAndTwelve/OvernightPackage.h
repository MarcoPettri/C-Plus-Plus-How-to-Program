// OvernightPackage.cpp

/*
	OvernigthPackage Class for exercise 11.9: Package Inheritance Hierarchy

*/


#ifndef OVERNIGHT_PACKAGE_H
#define OVERNIGTH_PACKAGE_H

#include "Package.h"

class OvernightPackage: public Package
{

public:
	OvernightPackage(const std::string& from_nme, const std::string& to_nme,
		const std::string& from_addr, const std::string& to_addr,
		const std::string& from_cty, const std::string& to_cty,
		const std::string& from_stat, const std::string& to_stat,
		const std::string& from_zip, const std::string& to_zip,
		double wght, double cst, double fee);

	double calculateCost() const ;
	std::string to_string() const;

private:
	double fee;
};

#endif // !OVERNIGHT_PACKAGE_H

