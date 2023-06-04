// Date.h
// Date Class declaration

#ifndef DATE_H
#define DATE_H

#include<string>
#include<sstream>
#include <stdexcept>

class Date {
public:
	explicit Date(unsigned d = 1, unsigned m = 1, unsigned y = 2000);
	std::string toString() const;
	
	void setYear(unsigned);
	void setMonth(unsigned);
	void setDay(unsigned);

private:
	unsigned year;
	unsigned month;
	unsigned day;
};

#endif // !DATE_H

