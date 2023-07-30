//SalariedEmployee.cpp

/*
    SalariedEmployee class definitions.
*/ 

#include <stdexcept>
#include<iomanip>
#include <sstream>
#include "SalariedEmployee.h" 

// constructor 
SalariedEmployee::SalariedEmployee(const std::string& frst_nme, const std::string& lst_nme,
    const std::string& ssn, const Date& dte, double wkly_slry)
   : Employee(frst_nme, lst_nme, ssn, dte)
{
    setWeeklySalary(wkly_slry);
}

// set salary
void SalariedEmployee::setWeeklySalary(double rhs) 
{

   if (rhs < 0.0f) {
      throw std::invalid_argument("Weekly salary must be >= 0.0");
   }

   this->weeklySalary = rhs;
}

// override pure virtual function earnings in Employee
double SalariedEmployee::earnings() const { return this->weeklySalary; }

std::string SalariedEmployee::toString() const 
{

   std::ostringstream out;

   out << std::fixed << std::setprecision(2)
       << "Salaried Employee: " << Employee::toString() 
      << "\nWeekly Salary: " << this->weeklySalary;

   return out.str();
}


