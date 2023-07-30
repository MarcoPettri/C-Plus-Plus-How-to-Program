//BasePlusCommissionEmployee.cpp
/*
    BasePlusCommissionEmployee member-function definitions.
*/

#include <iomanip>
#include <stdexcept>
#include <sstream>
#include "BasePlusCommissionEmployee.h"

// Constructor 
BasePlusCommissionEmployee::BasePlusCommissionEmployee(const std::string& frst_nme, const std::string& lst_nme,
    const std::string& snn, const Date& dte, double grs_sls,
    double cms_rte, double bse_slry)
   : CommissionEmployee(frst_nme, lst_nme, snn, dte, grs_sls, cms_rte) 
{
    setBaseSalary(bse_slry); 
}

// set base salary
void BasePlusCommissionEmployee::setBaseSalary(double salary) {

   if (salary < 0.0f) {
      throw std::invalid_argument("Salary must be >= 0.0");
   }

   this->baseSalary = salary;
}

// calculate earnings;
// override virtual function earnings in CommissionEmployee
double BasePlusCommissionEmployee::earnings() const {
   return this->baseSalary + CommissionEmployee::earnings();
}

std::string BasePlusCommissionEmployee::toString() const {

   std::ostringstream output;

   output << std::fixed << std::setprecision(2)
   << "Base-Salaried " << CommissionEmployee::toString()
      << "\nBase Salary: " << this->baseSalary;

   return output.str();
}
