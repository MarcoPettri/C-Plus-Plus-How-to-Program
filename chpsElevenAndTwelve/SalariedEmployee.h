//SalariedEmployee.h

/*
    SalariedEmployee class for exercise 12.11: Payroll-System Modification.
*/

#ifndef SALARIED_H
#define SALARIED_H


#include "Employee.h" 

class SalariedEmployee : public Employee {
public:
   SalariedEmployee(const std::string& frst_nme, const std::string& lst_nme,
					const std::string& ssn, const Date& dte, double wkly_slry = 0.0);

   virtual ~SalariedEmployee() = default; 

   void setWeeklySalary(double); 
   double getWeeklySalary() const { return weeklySalary; }

   virtual double earnings() const override; // calculate earnings        
   virtual std::string toString() const override; 

private:
   double weeklySalary; // salary per week
};

#endif // SALARIED_H

