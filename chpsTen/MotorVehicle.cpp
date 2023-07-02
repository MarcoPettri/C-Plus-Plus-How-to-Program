// MotorVehicle.cpp

/*

		MotorVehicle class Member-function definitions
*/

#include "MotorVehicle.h"


// Constructor
MotorVehicle::MotorVehicle(std::string make, std::string full_type,
	int yearOfManufacture, std::string color, int engineCapacity)
	:Make{ make }, Full_Type{ full_type }, Year_Of_Manufacture{ yearOfManufacture },
	Color{ color }, Engine_Capacity{ engineCapacity } { }


bool MotorVehicle::operator==(const MotorVehicle& rhs) const {
	return (
		this->Make == rhs.Make &&
		this->Full_Type == rhs.Full_Type &&
		this->Year_Of_Manufacture == rhs.Year_Of_Manufacture &&
		this->Color == rhs.Color &&
		this->Engine_Capacity == rhs.Engine_Capacity
		);
}


// Setter Functions

void MotorVehicle::make(const std::string& make) { this->Make = make; }
void MotorVehicle::full_type(const std::string& type) { this->Full_Type = type; }
void MotorVehicle::color(const std::string& col) { this->Color = col; }
void MotorVehicle::year_of_manufacture(int year) { this->Year_Of_Manufacture = year; }
void MotorVehicle::engine_capacity(int capacity) { this->Engine_Capacity = capacity; }

// Insertion Operator 

std::ostream& operator<<(std::ostream& out, const MotorVehicle& rhs) {

	out << "Make: " << rhs.Make << std::endl
		<< "Full Type: " << rhs.Full_Type << std::endl
		<< "Year OF Manufacture: " << rhs.Year_Of_Manufacture << std::endl
		<< "Color: " << rhs.Color << std::endl
		<< "Engine Capacity: " << rhs.Engine_Capacity << std::endl;

	return out;
}
