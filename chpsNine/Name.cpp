// Name.cpp

/*

		Name class member-functions definitions.

*/

#include "Name.h"

bool isValid(std::string s);

Name::Name(const std::string& firstNme, const std::string& middleNme,
	const std::string& lastNme, const std::string& sal)
{ 
	setFirstName(firstNme);
	setMiddleName(middleNme);
	setLastName(lastNme);
	setSaludation(sal);
}


std::string Name::toString() const
{
	std::string out{
		saludation + " " + lastName + ", "
		+ firstName + " " + middleName
	};

	return out;
}

// Setters Functions

void Name::setFirstName(const std::string& fNme)
{
	if (isValid(fNme)){
		firstName = fNme;
	}
	else {
		throw std::invalid_argument("Incorrect Argument!");
	}
}

void Name::setMiddleName(const std::string& mNme)
{

	middleName = mNme;


}

void Name::setLastName(const std::string& lNme)
{
	if (isValid(lNme)){
		lastName = lNme;
	}
	else {
		throw std::invalid_argument("Incorrect Argument!");
	}
}

void Name::setSaludation(const std::string& sal)
{
	saludation = sal;

}

bool isValid(std::string s)
{
	if (std::regex_match(s, std::regex("[A-Za-z]+"))) {
		return true;
	}

	return false;
}