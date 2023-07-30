// Payroll-System Modification.cpp


/*
			Modify the payroll system of Figs.12.9–12.17 to include private data member birthDate in class Employee.
		Use class Date from Figs.10.6–10.7 to represent an employee's birthday. Assume that payroll is processed once per month.
		Create a vector of Employee pointers to store the various employee objects. 
		In a loop, calculate the payroll for each Employee (polymorphically), and add a $100.00 bonus to the person's payroll amount 
		if the current month is the month in which the Employee's birthday occurs.

*/


#include"Employee.h"
#include"SalariedEmployee.h"
#include "CommissionEmployee.h"
#include"BasePlusCommissionEmployee.h"

#include<iostream>
#include<vector>


int Payroll_System_Modification()
{
	Date birthSue{ 4, 3, 2001 };
	std::vector<Employee* > employees{
		new SalariedEmployee("John", "Smith", "111-11-1111", {23, 8, 2004}, 800),
		new CommissionEmployee("Sue", "Jones", "333-33-3333", birthSue, 10000, .06),
		new BasePlusCommissionEmployee("Bob", "Lewis", "444-44-4444", {6, 5, 2003}, 5000, .04, 300)
	};

	

	for (const Employee* emplys : employees) {

		std::cout << emplys->toString() << "\n";

		std::cout << "Earnings: ";
		if (emplys->getDate() == birthSue) { std::cout << emplys->earnings() + 100.00f; }
		else { std::cout << emplys->earnings(); }

		std::cout << "\n\n";

		delete emplys;
	}
	return 0;
}