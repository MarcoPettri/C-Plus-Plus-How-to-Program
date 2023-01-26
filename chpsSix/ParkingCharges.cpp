 //6.12 Exercise: Parking Charges
 /*
	A parking garage charges a $20.00 minimum fee to park for up to three
	hours.The garage charges an additional $5.00 per hour for each hour or part thereof in excess of three
	hours.The maximum charge for any given 24-hour period is $50.00.Assume that no car parks for
	longer than 24 hours at a time.Write a program that calculates and prints the parking charges for each
	of three customers who parked their cars in this garage yesterday.You should enter the hours parked
	for each customer.Your program should print the results in a neat tabular format and should calculate
	and print the total of yesterday’s receipts.The program should use the function calculateCharges to
	determine the charge for each customer.Your outputs should appear in the following format:

							Car		Hours	Charge
							1		1.5		20.00
							2		4.0		25.00
							3		24.0	50.00
							TOTAL	29.5	95.00
*/
#include<iostream>
#include<iomanip>

double calculateCharges(double const hours);

int ParkingCharges() {

	double const cars[]{ 1.5, 4.0, 24.0 };
	double total{ 0 };
	double totalHours{ 0 };

	std::cout << std::fixed << std::setprecision(2);

	std::cout << "Car " 
		<< std::setw(10) << "Hours" 
		<< std::setw(10) << "Charge"
		<< std::endl;

	for (int i{ 0 }; i < 3; i++) {

		std::cout << i
			<< std::setw(13) << cars[i]
			<< std::setw(10) << calculateCharges(cars[i])
			<< std::endl;

		total += calculateCharges(cars[i]);
		totalHours += cars[i];

	}
	std::cout << "Total" << std::setw(9) << totalHours
		<< std::setw(10) << total;

	return 0;
}

double calculateCharges(double const hours) {

	if (3 >= hours) {

		return 20.00;
	}
	else if (24 > hours) {
		return 5.00 * ( hours - 3 ) + 20.00;
	}
	else {
		return 50.00;
	}
}