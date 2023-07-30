// Date.h
/*
	Date class for exercise 12.11 : Payroll - System Modification
*/

#ifndef DATE_H
#define DATE_H

#include <array>
#include <iostream>

class Date {
   friend std::ostream& operator<<(std::ostream&, const Date&);
   

public:
   Date(int d = 1, int m = 1, int y = 1900); // default constructor
   void setDate(int, int, int); 
   Date& operator++();              
   Date operator++(int);
   Date& operator+=(unsigned int); // add days, modify object
   bool operator==(const Date& rhs) const; // equality operator
   bool operator!=(const Date& rhs) const { return !(*this == rhs); }

   static bool leapYear(int); // is year a leap year?
   bool endOfMonth(int) const; // is day at the end of month?

private:
   unsigned int day;
   unsigned int month;
   unsigned int year;

   static const std::array<unsigned int, 13> days; // days per month
   void helpIncrement(); // utility function for incrementing date
};

#endif

