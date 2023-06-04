// Student.cpp

// Student Class Member-function definitions

#include "Student.h"



Student::Student(const std::string& firstNme, const std::string& middleNme,
	const std::string& lastNme, const std::string& gender,
	unsigned dayBirth, unsigned monthBirth, unsigned yearBirth,
	const std::string& RN,const std::string& eml)
	: name(firstNme, middleNme, lastNme, " "), sex(gender),
	 birth(dayBirth,monthBirth, yearBirth), 
	registrationNumber(RN), email(eml) { }

//Setters Functions

void Student::setFirstName(const std::string& firstNme)
{
	name.setFirstName(firstNme);
}

void Student::setMidlleName(const std::string& middleNme)
{
	name.setMiddleName(middleNme);
}

void Student::setLastName(const std::string& lastNme)
{
	name.setLastName(lastNme);
}

void Student::setSex(const std::string& gender)
{
	if (isValid(gender)) {
		sex = gender;
	}
	else {
		throw std::invalid_argument("Incorrect Argument!");
	}
}

void Student::setBirth(unsigned y, unsigned m, unsigned d)
{
	birth.setYear(y);
	birth.setMonth(m);
	birth.setDay(d);
}

void Student::setRN(const std::string& RN)
{
	if (isValid(RN)) {
		registrationNumber = RN;
	}
	else {
		throw std::invalid_argument("Incorrect Argument!");
	}
}

void Student::setEmail(const std::string& eml)
{
	if (isValid(eml)) {
		email = eml;
	}
	else {
		throw std::invalid_argument("Incorrect Argument!");
	}

}

// Getters Functions

const std::string& Student::getFirstName() const
{
	return name.getFirstName();
}
const std::string& Student::getMiddleName() const
{
	return name.getMiddleName();
}
const std::string& Student::getLastName() const
{
	return name.getLastName();
}

std::string Student::getBirth() const
{
	return birth.toString();
}
