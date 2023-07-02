
// Exercise 10.8: Enhanced MotorVehicle class
/*
		Enhance the MotorVehicle class of Exercise 3.11 by overloading the following operators:

				a) Equality (==) : two MotorVehicle objects are equal (identical) if all their attributes are
				identical, that is, they of the same make, they use the same type of fuel, they were manu-
				factured in the same year, they are of the same color and they have the same engine capacity.

				b) Not equal (!=) : two MotorVehicle objects are not equal (not identical) if any of their
				attributes do not match.

				c) Greater than (>): A MotorVehicle object is greater than another MotorVehicle object if
				the former was manufactured before the latter.

				d) Output operator (<<): displays a MotorVehicle in a similar fashion to the displayCarDetails
				function.

		Write a test program to demonstrate the capabilities of the enhanced MotorVehicle class.
*/


#include "MotorVehicle.h"

int MOTOR_VEHICLE_CLASS() {


	MotorVehicle bmw{ "BMW X", "Hybrid", 2017, "Black", 250 };
	MotorVehicle urus{ "Urus", "Petrol", 2018, "Black", 306 };


	std::cout << bmw << std::endl << urus << std::endl;

	std::cout << "\nTest Comparison Operator \n" << std::boolalpha;

	std::cout << "\nBMW X < URUS: " << (bmw < urus) << std::endl
		<< "BMW X > URUS: " << (bmw > urus) << std::endl
		<< "BMW X <= URUS: " << (bmw <= urus) << std::endl
		<< "BMW X >= URUS: " << (bmw >= urus) << std::endl
		<< "BMW X == URUS: " << (bmw == urus) << std::endl
		<< "BMW X != URUS: " << (bmw != urus) << std::endl;

	std::cout << "\nTest Getters Functions" << std::endl;

	std::cout << "\nBMW X Make: " << bmw.make() << std::endl
		<< "BMW X Full Type: " << bmw.full_type() << std::endl
		<< "Urus Color: " << urus.color() << std::endl
		<< "Urus Year Of Manufacture: " << urus.year_of_manufacture() << std::endl
		<< "Urus Engine Capacity: " << urus.engine_capacity() << std::endl;


	std::cout << "\nTest Setters Functions in Urus\n" << std::endl;

	urus.make("BMW XM");
	urus.full_type("Hybrid");
	urus.color("Red/Black");
	urus.year_of_manufacture(2023);
	urus.engine_capacity(360);

	std::cout << urus << std::endl;

	return 0;
}