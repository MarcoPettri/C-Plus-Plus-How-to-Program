// Time.cpp
// Time class member-function definitions.

#define _CRT_SECURE_NO_WARNINGS
#include "Time.h" 


Time::Time(std::time_t now)
{
    std::tm* time{ std::localtime(&now) };

    setTime(time->tm_hour, time->tm_min, time->tm_sec);
}

// set new Time value using universal time
void Time::setTime(int h, int m, int s) 
{
    // validate hour, minute and second
    if ((h >= 0 && h < 24) && (m >= 0 && m < 60) && (s >= 0 && s < 60)) 
    {
        hour = h;
        minute = m;
        second = s;
    }
    else {
        throw std::invalid_argument(
            "hour, minute and/or second was out of range"
        );
    }
}

// return Time as a string in universal-time format (HH:MM:SS)
std::string Time::toUniversalString() const 
{
    std::ostringstream output;

    output << std::setfill('0') << std::setw(2) << hour << ":"
        << std::setw(2) << minute << ":" << std::setw(2) << second;

    return output.str(); // returns the formatted string
}

// return Time as string in standard-time format (HH:MM:SS AM or PM)
std::string Time::toStandardString() const 
{
    std::ostringstream output;

    output << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
        << std::setfill('0') << std::setw(2) << minute << ":" << std::setw(2)
        << second << (hour < 12 ? " AM" : " PM");

    return output.str(); // returns the formatted string
}
