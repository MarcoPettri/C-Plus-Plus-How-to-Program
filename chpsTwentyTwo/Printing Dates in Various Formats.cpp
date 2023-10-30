// Exercise 22.x: Printing Dates in Various Formats
/*
	Dates are commonly printed in several different formats in business correspondence. 
	Two of the more common formats are:
				07/21/1955
				July 21, 1955
	Write a program that reads a date in the first format and prints that date in the second format.
*/

#include<iostream>
#include<string>
#include<array>
#include<cstddef>

int PRINTING_DATES_IN_VARIOUS_FORMATS()
{

	std::string date;
	std::cout << "Data(mm/dd/yyyy): ",
		std::cin >> date;
	
	std::size_t firstIndex{ date.find('/') };
	std::size_t lastIndex{ date.rfind('/') };



	if (firstIndex != std::string::npos && 
		lastIndex != firstIndex) {

		
		const char* MONTHS[13] { "\0",
			"January", "February", "March", "April", "May", "June",
			"July", "August", "September", "October", "November", "December"
		};

		int monthIndex{ std::stoi(date.substr()) };
		int day{ std::stoi(date.substr(++firstIndex)) };


		std::cout << MONTHS[monthIndex] << " "
			<< day << ", "
			<< date.substr(++lastIndex) << std::endl;
	}
	else {
		std::cout << "Invalid date" << std::endl;
	}

	
	return 0;
}