// Employee.cpp

/*
    Abstract-base-class Employee member-function definitions.
*/



#include <sstream>
#include "Employee.h" 


// constructor
Employee::Employee(const std::string& first, const std::string& last,
   const std::string& ssn, const Date& dte)
    : firstName(first), lastName(last), 
       socialSecurityNumber(ssn), birthDate{ dte } { }

//set first name
void Employee::setFirstName(const std::string& first) { this->firstName = first; }

// set last name
void Employee::setLastName(const std::string& last) { this->lastName = last; }


// set social security number
void Employee::setSocialSecurityNumber(const std::string& ssn) 
{
   this->socialSecurityNumber = ssn; // should validate
}

//set birth date
void Employee::setDate(const Date& rhs)
{
   this->birthDate = rhs;
}


// toString Employee's information (virtual, but not pure virtual)
std::string Employee::toString() const 
{

    std::ostringstream out;

    out << firstName << " " << lastName
        << "\nSocial Security Number : " << this->getSocialSecurityNumber()
        << "\nBirth Date: " << birthDate;

    return out.str();
}

