// Exercise 9.4 : Enhancing Class Time

/*
		Provide a constructor that's capable of using the current time from
		the time and localtime functions—declared in the C++ Standard Library header <ctime>
		—to initialize an object of the Time class.
*/

#include <iostream>
#include "Time.h" 


// displays a Time in 24-hour and 12-hour formats
void displayTime(const std::string& message, const Time& time) {
	std::cout << message << "\nUniversal time: " << time.toUniversalString()
		<< "\nStandard time: " << time.toStandardString() << "\n\n";
}

int EnhancingClassTime() {
	Time t{ std::time(nullptr) };

	displayTime("Initial time:", t); // display t's initial value

	t.setTime(13, 27, 6); // change time

	displayTime("After setTime:", t); // display t's new value

	// attempt to set the time with invalid values
	try {
		t.setTime(99, 99, 99); // all values out of range
	}
	catch (std::invalid_argument& e) {
		std::cout << "Exception: " << e.what() << "\n\n";
	}

	// display t's value after attempting to set an invalid time
	displayTime("After attempting to set an invalid time:", t);

	return 0;
}