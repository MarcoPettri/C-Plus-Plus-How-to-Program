// Exercise 12.12: Package Inheritance Hierarchy

/*
		
				Use the Package inheritance hierarchy created in Exercise 11.9 to create a program
			that displays the address information and calculates the shipping costs for several Packages. 
			The program should contain a vector of Package pointers to objects of classes TwoDayPackage and OvernightPackage. 
			Loop through the vector to process the Packages polymorphically. For each Package, invoke get functions to obtain 
			the address information of the sender and the recipient, then print the two addresses as they would appear on mailing labels. 
			Also, call each Package's calculateCost member function and print the result. Keep track of the total
			shipping cost for all Packages in the vector, and display this total when the loop terminates.
*/

#include<iostream>
#include "Package2.h"
#include "TwoDayPackage2.h"
#include "OvernightPackage2.h"

int Package_Inheritance_Hierarchy2()
{
	std::vector<Package2*> packages{
		new TwoDayPackage2{
		"Jenna", "Lanna",
		"Rua E 312", "Rua Louro 1521",
		"Brasília", "Santa Cruz Do Sul",
		"Distrito Federal", "Rio Grande do Sul",
		"70631-025", "96825-710",
		50.26 , 74.44, 1.43
		},
		new OvernightPackage2{
		"Lua", "Aurora",
		"Rua Presidente Vargas 1997", "Avenida Jornalista Rubens de Arruda Ramos",
		"Fortaleza", "Florianópolis",
		"Ceará", "Santa Catarina",
		"60765-760", "88015-700",
		24.12 , 33.545, 2.43
		}
	};


	double totalCost{ 0 };

	for (Package2* packgs : packages) {

		double cost{ packgs->calculateCost() };
		totalCost += cost;

		std::cout << packgs->to_string()
			<< "\nCost: " << cost << "\n\n";

	}

	std::cout << "Total cost: " << totalCost << std::endl;


	return 0;
}