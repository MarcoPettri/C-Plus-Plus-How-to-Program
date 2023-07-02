// MotorVehicle.h

/*
		MotorVehicle Class for exercise 10.8: Enhanced Motor Vehicle class
*/


#ifndef MOTOR_VEHICLE_H
#define MOTOR_VEHICLE_H

#include<iostream>
#include<string>

class MotorVehicle
{
	friend std::ostream& operator<<(std::ostream&, const MotorVehicle&);

public:

	MotorVehicle(std::string make, std::string full_type, 
		int yearOfManufacture, std::string color, int engineCapacity);

	// comparison operator
	bool operator==(const MotorVehicle&) const;
	bool operator!=(const MotorVehicle& rhs) const { return !(*this == rhs); }

	bool operator<(const MotorVehicle& rhs) const { return Year_Of_Manufacture < rhs.Year_Of_Manufacture; }
	
	bool operator>(const MotorVehicle& rhs) const { return  (rhs < *this); }

	bool operator<=(const MotorVehicle& rhs) const { return !(*this > rhs); }

	bool operator>=(const MotorVehicle& rhs) const { return !(*this < rhs); }

	// Getter Functions
	const std::string& make() const { return Make; }
	const std::string& full_type() const { return Full_Type; }
	const std::string& color() const { return Color; }

	int year_of_manufacture() const { return Year_Of_Manufacture; }
	int engine_capacity() const { return Engine_Capacity; }

	// Setter Functions

	void make(const std::string&);
	void full_type(const std::string&);
	void color(const std::string&);
	void year_of_manufacture(int);
	void engine_capacity(int);

private:
	std::string Make;
	std::string Full_Type;
	int Year_Of_Manufacture;
	std::string Color;
	int Engine_Capacity;

};

#endif // MOTOR_VEHICLE_H

