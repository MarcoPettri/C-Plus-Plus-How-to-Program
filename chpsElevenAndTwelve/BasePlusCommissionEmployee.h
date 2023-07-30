//BasePlusCommissionEmployee.h

/*
     BasePlusCommissionEmployee class for exercise 12.11: Payroll-System Modification.
*/ 

#ifndef BASEPLUS_H
#define BASEPLUS_H


#include "CommissionEmployee.h" 

class BasePlusCommissionEmployee : public CommissionEmployee {
public:
   BasePlusCommissionEmployee(const std::string& frst_nme, const std::string& lst_nme,
                              const std::string& snn, const Date& dte, double grs_sls = 0.0, 
                              double cms_rte = 0.0, double bse_slry = 0.0);

   virtual ~BasePlusCommissionEmployee() = default; 

   void setBaseSalary(double); 
   double getBaseSalary() const { return baseSalary; }
                 
   virtual double earnings() const override; 
   virtual std::string toString() const override; 

private:
   double baseSalary; // base salary per week
};

#endif // BASEPLUS_H
