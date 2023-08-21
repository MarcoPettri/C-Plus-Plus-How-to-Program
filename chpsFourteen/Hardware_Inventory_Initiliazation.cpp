//Hardware_Inventory_Initiliazation.cpp
/*
	Hardware_Inventory_Initiliazation for exercise 14.11: Hardware Inventory
*/

#include<iostream>
#include<fstream>
#include<cstdlib>
#include "Tool.h"

int Hardware_Inventory_Initiliazation()
{
	
	std::ofstream outHardware{ "hardware.dat", std::ios::out | std::ios::binary };

	if (!outHardware) {
		std::cerr << "File could not be opened." << std::endl;
		std::exit(EXIT_FAILURE);
	}

	Tool blankTool{ };

	for (int i{ 0 }; i < 100; ++i) {
		outHardware.write(
			reinterpret_cast<const char*>(&blankTool), sizeof(Tool)
		);
	}

	outHardware.close();

	return 0;
}