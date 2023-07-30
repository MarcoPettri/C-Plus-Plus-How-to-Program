//Employee.h

/*
	Employee abstract base class for exercise 12.11: Payroll-System Modification

*/

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "Date.h"

class Employee {
public:
   Employee(const std::string& frst_nme, const std::string& lst_nme,
			const std::string& ssn, const Date& dte);

   virtual ~Employee() = default; // compiler generates virtual destructor

   void setFirstName(const std::string&); 
   const std::string& getFirstName() const { return firstName; }

   void setLastName(const std::string&); 
   const std::string& getLastName() const { return lastName; }

   void setSocialSecurityNumber(const std::string&);
   const std::string& getSocialSecurityNumber() const { return socialSecurityNumber; }

   void setDate(const Date&); 
   const Date& getDate() const { return birthDate; }

   
   virtual double earnings() const = 0; // pure virtual          
   virtual std::string toString() const; // virtual      

private:
   std::string firstName;
   std::string lastName;
   std::string socialSecurityNumber;
   Date		   birthDate;

};

#endif // EMPLOYEE_H
