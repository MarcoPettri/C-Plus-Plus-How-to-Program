// 6.25 (Calculating Number of Minutes) 
/*
	Write a function that takes the time as three integer arguments, days, hours, and minutes, 
	and returns the number of minutes since the start of the current month, 
	i.e., days = 0; hours = 0 and months = 0; Use this function to calculate the amount of time in
	minutes between two times, both of which are within the same calendar month
 */


#include<iostream>
#include<locale>

int numberOfMinutes(int& day, int& hours, int& minutes);

int Number_Of_Minutes() {

	int day, hours, minutes;

	std::cout << "Enter the day, hours and minutes separated by spaces: ",
		std::cin >> day >> hours >> minutes;

	std::cout.imbue(std::locale(""));
	
	std::cout << "the number of minutes elapsed since the beginning of the month is: "
		<< numberOfMinutes(day, hours, minutes)
		<< std::endl;
	
	std::cout << "\nEnter the day, hours and minutes of the first date separated by spaces: ",
		std::cin >> day >> hours >> minutes;	

	int dateOne = numberOfMinutes(day, hours, minutes);

	std::cout << "\nEnter the day, hours and minutes of the second date separated by spaces: ",
		std::cin >> day >> hours >> minutes;

	int dateTwo = numberOfMinutes(day, hours, minutes);

	std::cout << "\nThe amount of time in minutes elapsed between the dates is: "
		<< dateTwo - dateOne << std::endl;

	return 0;
}

int numberOfMinutes(int& day, int& hours, int& minutes) {

	int const minutesInOneDay{ 1'440 };

	return ((day +1) * minutesInOneDay) + (hours * 60) + minutes;
}