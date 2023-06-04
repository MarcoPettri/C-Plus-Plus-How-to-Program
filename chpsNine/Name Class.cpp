// Exercise 9.7: Name Class
/*

		
			A Name can find uses in many applications that involve people, for example
			payroll and banking. Create a class called Name that contains data members of type string called
			firstName, middleName, lastName, and salutation. Add a constructor that takes four parameters
			which are used to initialize the four data members and a member function called toString that re-
			turns the person's full name in the form "salutation lastName, firstName middleName". Finally,
			add set and get functions for all data member.
*/

#include<iostream>
#include "Name.h"

int NAME_CLASS()
{
	Name eu{ "Marco", "", "Pettri", "Oi! meu nome \x82" };

	std::cout << eu.toString() << std::endl;

	return 0;
}