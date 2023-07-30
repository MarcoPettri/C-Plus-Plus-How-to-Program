//CommissionEmployee.cpp

/*
    CommissionEmployee class member-function definitions.
*/ 

#include <iomanip>
#include <stdexcept>
#include <sstream>
#include "CommissionEmployee.h"


// constructor 
CommissionEmployee::CommissionEmployee(const std::string& frst_nme, const std::string& lst_nme,
    const std::string& snn, const Date& dte,
    double grs_sls, double cms_rte)
   : Employee(frst_nme, lst_nme, snn, dte)
{
   setGrossSales(grs_sls);
   setCommissionRate(cms_rte);
}

// set gross sales amount
void CommissionEmployee::setGrossSales(double rhs) 
{

   if (rhs < 0.0) {
      throw std::invalid_argument("Gross sales must be >= 0.0");
   }

   this->grossSales = rhs;
}


// set commission rate
void CommissionEmployee::setCommissionRate(double rhs) 
{
   if (rhs <= 0.0 || rhs > 1.0) {
      throw std::invalid_argument("Commission rate must be > 0.0 and < 1.0");
   }

   this->commissionRate = rhs;
}

// calculate earnings; override pure virtual function earnings in Employee
double CommissionEmployee::earnings() const 
{
   return this->commissionRate * this->grossSales;
}

std::string CommissionEmployee::toString() const 
{

   std::ostringstream out;

   out << std::fixed << std::setprecision(2)
       << "Commission Employee: " << Employee::toString()
      << "\nGross Sales: " << this->grossSales
      << "\nCommission Rate: " << this->commissionRate;

   return out.str();
}


