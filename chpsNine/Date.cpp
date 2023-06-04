// Date.cpp
// Date Class Member-Function definitions.

#include "Date.h"

Date::Date(unsigned d, unsigned m, unsigned y)
{
	setYear(y);
	setMonth(m);
	setDay(d);
}

//Print date in the format dd/mm/yyyy
std::string Date::toString() const
{
	std::ostringstream output;
	output << day << '/' << month << '/' << year;
	return output.str();
}


void Date::setYear(unsigned y)
{
	if (y > 1900)
	{
		year = y;
	}
	else {
		throw std::invalid_argument(
			"The year must be after 1900"
		);
	}
}
void Date::setMonth(unsigned m)
{
	if (0 < m && m < 13)
	{
		month = m;
	}
	else {
		throw std::invalid_argument(
			"Month must be in the range  1 <= m <= 12"
		);
	}
}

void Date::setDay(unsigned d)
{
	if (0 < d && d < 32) 
	{
		if (month == 2)
		{
			if (not(year % 400) || (not(year % 4) && (year % 100))) // leap
			{
				if (d <= 29)
				{
					day = d;
				}
				else {
					
					throw std::invalid_argument(
						"Leap Year: The day must be less than or equal to 29"
					);
				}
			}
			else if (d <= 28) // non-leap
			{
				day = d;
			}
			else {
				throw std::invalid_argument(
					"Non-leap Year: The day must be less than or equal to 28"
				);
			}
		}
		else {
			day = d;
		}
	}
	else {
		throw std::invalid_argument(
			"Day must be in the range  1 <= m <= 31"
		);
	}
}