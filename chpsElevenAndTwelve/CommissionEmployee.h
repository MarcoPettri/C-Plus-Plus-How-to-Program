//CommissionEmployee.h

/*
     CommissionEmployee class For exercise 12.11: Payroll-System Modification
*/

#ifndef COMMISSION_H
#define COMMISSION_H

#include "Employee.h" 

class CommissionEmployee : public Employee {

public:
   CommissionEmployee(const std::string& frst_nme, const std::string& lst_nme,
                      const std::string& snn, const Date& dte, 
                      double grs_sls = 0.0, double cms_rte = 0.0);

   virtual ~CommissionEmployee() = default; 

   void setCommissionRate(double); // set commission rate
   double getCommissionRate()  const { return commissionRate; }

   void setGrossSales(double); // set gross sales amount
   double getGrossSales() const { return grossSales; }

       
   virtual double earnings() const override; // calculate earnings        
   virtual std::string toString() const override; 

private:
   double grossSales; 
   double commissionRate; 
};

#endif // COMMISSION_H
