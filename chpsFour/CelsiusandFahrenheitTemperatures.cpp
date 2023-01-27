// 6. 26  Exercises: Celsius and Fahrenheit Temperatures

/*
		Implement the following integer functions :
		a) Function Celsius returns the Celsius equivalent of a Fahrenheit temperature.
		b) Function Fahrenheit returns the Fahrenheit equivalent of a Celsius temperature.
		c) Use these functions to write a program that prints charts showing the Fahrenheit equivalents
		of all Celsius temperatures from 0 to 100 degrees, and the Celsius equivalents of
		all Fahrenheit temperatures from 32 to 212 degrees.Print the outputs in a neat tabular
		format that minimizes the number of lines of output while remaining readable.
*/

#include<iostream>
#include<iomanip>


inline float celsius(float& temperture) { return (temperture - 32) / 1.8; }
inline float fahrenheit(float& temperature) { return (temperature * 1.8) + 32; }

int Celsius_And_Fahrenheit() {

	std::cout << std::setw(10) 
		<< "*C \t\t  *F\n";

	for (float temp{ 0 }; temp <= 100; temp++) {

			std::cout << std::setw(3) << temp
			<< std::setw(17) << fahrenheit(temp)
			<< std::endl;
	}

	std::cout << std::setw(10) 
		<< "\n*F \t\t  *C\n";

	for (float temp{ 32 }; temp <= 212; temp++) {

			std::cout << std::setw(3) << temp
			<< std::setw(17) << celsius(temp)
			<< std::endl;
	}

	return 0;
}