// Date.cpp

/*

    Date class definitions

*/ 

#include <string>
#include<stdexcept>

#include "Date.h"


const std::array<unsigned int, 13> Date::days{
   0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Date constructor
Date::Date(int day, int month, int year) {
   setDate(day, month, year);
}

// set month, day and year
void Date::setDate(int dd, int mm, int yy) {
   if (mm >= 1 && mm <= 12) {
      month = mm;
   }
   else {
      throw std::invalid_argument{"Month must be 1-12"};
   }

   if (yy >= 1900 && yy <= 2100) {
      year = yy;
   }
   else {
      throw std::invalid_argument{"Year must be >= 1900 and <= 2100"};
   }

   // test for a leap year
   if ((month == 2 && leapYear(year) && dd >= 1 && dd <= 29) ||
      (dd >= 1 && dd <= days[month])) {
      day = dd;
   }
   else {
      throw std::invalid_argument{
         "Day is out of range for current month and year"};
   }
}

// overloaded prefix increment operator                 
Date& Date::operator++() {
   helpIncrement();               
   return *this; // reference return to create an lvalue
}

// overloaded postfix increment operator;  
// dummy integer parameter does not have a parameter name

Date Date::operator++(int) {
   Date temp{*this}; 
   helpIncrement();

   
   return temp; // value return; not a reference return  
}

// add specified number of days to date                    
Date& Date::operator+=(unsigned int additionalDays) {
   for (unsigned int i = 0; i < additionalDays; ++i) {
      helpIncrement();
   }

   return *this;                
}
// overloaded equality operator 
bool Date::operator==(const Date& rhs) const
{
    return { 
        this->day == rhs.day && 
        this->month == rhs.month && 
        this->year == rhs.year 
    };
}

// if the year is a leap year, return true; otherwise, return false
bool Date::leapYear(int testYear) {
   return (testYear % 400 == 0 ||
      (testYear % 100 != 0 && testYear % 4 == 0));
}

// determine whether the day is the last day of the month
bool Date::endOfMonth(int testDay) const {
   if (month == 2 && leapYear(year)) {
      return testDay == 29; // last day of Feb. in leap year
   }
   else {
      return testDay == days[month];
   }
}

// function to help increment the date
void Date::helpIncrement() {

   // day is not end of month
   if (!endOfMonth(day)) {
      ++day;
   }
   else {
      if (month < 12) { 
         ++month; 
         day = 1;
      }
      else { // last day of year
         ++year; 
         month = 1; 
         day = 1; 
      }
   }
}

// overloaded output operator
std::ostream& operator<<(std::ostream& output, const Date& d) {

   static std::string monthName[13]{"", "January", "February",
      "March", "April", "May", "June", "July", "August",
      "September", "October", "November", "December"};

   output << monthName[d.month] << " " << d.day << ", " << d.year;
   return output;
}

