// Exercise 11.9: Package Inheritance Hierarchy

/*
		
			Package-delivery services, such as FedEx, DHL and UPS, offer a number of different shipping options, 
		each with specific costs associated. Create an inheritance hierarchy to represent various types of packages. 
		Use class Package as the base class of the hierarchy, then include classes TwoDayPackage 
		and OvernightPackage that derive from Package
			Base-class Package should include data members representing the name, address, city, state
		and ZIP code for both the sender and the recipient of the package, in addition to data members
		that store the weight (in ounces) and cost per ounce to ship the package. Package's constructor
		should initialize these data members. Ensure that the weight and cost per ounce contain positive
		values. Package should provide a public member function calculateCost that returns a double
		indicating the cost associated with shipping the package. Package's calculateCost function should
		determine the cost by multiplying the weight by the cost per ounce.
			Derived-class TwoDayPackage should inherit the functionality of base-class Package, but also
		include a data member that represents a flat fee that the shipping company charges for two-day-
		delivery service. TwoDayPackage's constructor should receive a value to initialize this data member.
		TwoDayPackage should redefine member function calculateCost so that it computes the shipping
		cost by adding the flat fee to the weight-based cost calculated by base-class Package's calculate-Cost function.
			Class OvernightPackage should inherit directly from class Package and contain an additional
		data member representing an additional fee per ounce charged for overnight-delivery service. Over-
		nightPackage should redefine member function calculateCost so that it adds the additional fee
		per ounce to the standard cost per ounce before calculating the shipping cost. Write a test program
		that creates objects of each type of Package and tests member function calculateCost.
*/

#include<iostream>
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

int Package_Inheritance_Hierarchy()
{
	Package base_package{ 
		"Marco", "kiro",
		"Avenida Paulista 460", "Rua Helena Ferrante Borghi 1074",
		"São Paulo", "Presidente Prudente",
		"São Paulo", "São Paulo",
		"01310-904", "19043-080",
		35.27396   , 23.34
	}; 
	TwoDayPackage two_day_package{ 
		"Jenna", "Lanna",
		"Rua E 312", "Rua Louro 1521",
		"Brasília", "Santa Cruz Do Sul",
		"Distrito Federal", "Rio Grande do Sul",
		"70631-025", "96825-710",
		50.26 , 74.44, 1.43
	};
	OvernightPackage overnight_package{ 
		"Lua", "Aurora",
		"Rua Presidente Vargas 1997", "Avenida Jornalista Rubens de Arruda Ramos",
		"Fortaleza", "Florianópolis",
		"Ceará", "Santa Catarina",
		"60765-760", "88015-700",
		24.12 , 33.545, 2.43
	};


	std::cout << "\t\t Base Package\n" << base_package.to_string() << "\n\n"
		<< "\t\t TwoDayPackage\n" << two_day_package.to_string() << "\n\n"
		<< "\t\t OvernightPackage\n" << overnight_package.to_string() << std::endl;	
	
	
	std::cout << "\n\nBase Package Calculate Cost: " << base_package.calculateCost() << "\n\n"
		<< "TwoDayPackage Calculate Cost: " << two_day_package.calculateCost() << "\n\n"
		<< "OvernightPackage Calculate Cost: " << overnight_package.calculateCost() << std::endl;



	return 0;
}