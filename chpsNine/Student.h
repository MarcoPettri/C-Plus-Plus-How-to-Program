// Student.h

/*
		Student class for exercise 9.8: Student Class
*/

#ifndef STUDENT_H
#define STUDENT_H

#include "Name.h"
#include "Date.h"


class Student
{
public:
	Student(const std::string& firstNme, const std::string& middleNme,
		const std::string& lastNme, const std::string& sex,
		unsigned dayBirth, unsigned monthBirth, unsigned yearBirth, 
		const std::string& RN,const std::string& email);

	// Getters Functions
	const std::string& getFirstName() const;
	const std::string& getMiddleName() const;
	const std::string& getLastName() const;
	const std::string& getSex() const { return sex; }
	const std::string& getRN()  const { return registrationNumber; }
	const std::string& getEmail()  const { return email; }
	std::string getBirth() const;

	// Setters Functions
	void setFirstName(const std::string&);
	void setMidlleName(const std::string&);
	void setLastName(const std::string&);
	void setSex(const std::string&);
	void setRN(const std::string&);
	void setEmail(const std::string&);
	void setBirth(unsigned, unsigned, unsigned);

private:
	Name name;
	std::string sex;
	Date birth;
	std::string registrationNumber;
	std::string email;

};
#endif // !STUDENT_H
