// Name.h
/*
		Name Class for Exercise 9.7: Name Class
*/

#ifndef NAME_H
#define NAME_H

#include<string>
#include<stdexcept>
#include<regex>

bool isValid(std::string s); // Check if string isn't space or empty

class Name
{
public:

	Name(const std::string& firstName, const std::string& middleName,
		const std::string& lastName, const std::string& saludation);

	/* 
	Return  the person's full name in the form 
	"salutation lastName, firstName middleName”"
	*/
	std::string toString() const; 

// Setters Functions
	void setFirstName(const std::string&);
	void setMiddleName(const std::string&);
	void setLastName(const std::string&);
	void setSaludation(const std::string&);

// Getters Functions

	const std::string& getFirstName() const { return firstName; }
	const std::string& getMiddleName() const { return middleName; }
	const std::string& getLastName() const { return lastName; }
	const std::string& getSaludation() const { return saludation; }


private:
	std::string firstName;
	std::string middleName;
	std::string lastName;
	std::string saludation;
};
#endif // !NAME_H
