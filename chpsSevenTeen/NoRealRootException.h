//NoRealRootException.h
/*
	NoRealRootException Class for exercise 17.x: Exception Handling and Program Control
*/

#ifndef NO_REAL_ROOT_EXCEPTION_H
#define NO_REAL_ROOT_EXCEPTION_H


#include<stdexcept>
#include<string>

class NoRealRootException : public std::runtime_error
{
public:
	NoRealRootException(const char* what_arg)
		:std::runtime_error{ what_arg } {}

	NoRealRootException(const std::string& what_arg)
		:std::runtime_error{ what_arg } {}

	NoRealRootException()
		:std::runtime_error{ "No Real Roots" } {}


};

#endif // !NO_REAL_ROOT_EXCEPTION_H

