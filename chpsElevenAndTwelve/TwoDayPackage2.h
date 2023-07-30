// TwoDayPackage2.h

/*
	
	TwoDayPackage2 Class for exercise 12.12: Package Inheritance Hierarchy

*/


#ifndef TWO_DAY_PACKAGE2_H
#define TWO_DAY_PACKAGE2_H

#include "Package2.h"

class TwoDayPackage2: public Package2
{
public:
	TwoDayPackage2(const std::string& from_nme, const std::string& to_nme,
		const std::string& from_addr, const std::string& to_addr,
		const std::string& from_cty, const std::string& to_cty,
		const std::string& from_stat, const std::string& to_stat,
		const std::string& from_zip, const std::string& to_zip,
		double wght, double cst, double fee);

	virtual ~TwoDayPackage2() = default;

	virtual double calculateCost() const override;
	virtual std::string to_string() const override;

private:
	double fee;

};

#endif // !TWO_DAY_PACKAGE2_H



