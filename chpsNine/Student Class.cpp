// Exercise 9.8: Student Class

/*
			Many universities have information systems which track their students'
			academic records. Create a class called Student that can be used in such systems. 
			The class should represent a student and should have data members to represent each student's firstName,
			middleName, lastName, sex, yearOfBirth, registrationNumber, and email. Decide on the appropriate 
			data type for each data member. Provide a constructor which takes seven parameters and
			initializes the seven data members. Also provide set and get functions for each data member.
	
*/

// Exercise 9.9:  Improving Class Student

/*
			Improve the Student class in the previous exercise by using the concept of composition. 
			Replace the three data members used to represent names with a data member 
			of the Name class you created in Exercise 9.7. In addition, replace the data member used to represent 
			the year of birth of a student with a full date of birth by making use of class Date.

*/

// Exercise 9.10: Returning Error Indicators from Class Student's set Functions

/*
			Modify the set functions in the Student class of Exercise 9.9 to report appropriate error messages when an attempt is made to
			set a data member to an invalid value such as an empty name. If any of these attempts is made, throw
			an invalid_argument exception and provide an appropriate error message.

*/

#include<iostream>
#include "Student.h"

int StudentClass()
{


	Student Eu{
		"Marco", "", "Pettri", "Male",
		 8, 11, 2000, "GB123456789", "MarcoP@goldsmiths.com"
	};


	std::cout << "Name: " << Eu.getFirstName() << " " << Eu.getLastName() << "\n"
		<< "Sex: " << Eu.getSex() << "\n"
		<< "Register Number: " << Eu.getRN() << "\n"
		<< "Year Of Birth: " << Eu.getBirth() << "\n"
		<< "Email: " << Eu.getEmail() << std::endl;




	return 0;
}