// Exercise 14.11: Hardware Inventory
/*

		You own a hardware store and need to keep an inventory that can tell
	you what different tools you have, how many of each you have on hand and the cost of each one. Write
	a program that initializes the random-access file hardware.dat to 100 empty records, lets you input
	the data concerning each tool, enables you to list all your tools, lets you delete a record for a tool that
	you no longer have and lets you update any information in the file. The tool identification number
	should be the record number. Use the information in Fig. 14.17 to start your file.


*/


// Note: This program assumes that the Hardware_Inventory_Initiliazation.cpp file has been compiled

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip>
#include<vector>
#include "Tool.h"

enum class Choice { PRINT = 1, UPDATE, NEW, DELETE, END };


void	start_file();
void	outputLine(const Tool&);
int		get_record(const char* const);
Choice  enterChoice();

void	display_inventory(std::fstream&);
void	update_inventory(std::fstream&);
void	add_tool(std::fstream&);
void	delete_tool(std::fstream&);



int	Hardware_Inventory()
{
	start_file();

	std::fstream inOutInventory{ "hardware.dat", std::ios::in | std::ios::out | std::ios::binary };

	if (!inOutInventory) {

		std::cerr << "File could not be opened." << std::endl;
		std::exit(EXIT_FAILURE);
	}
	
	Choice choice;

	while ((choice = enterChoice()) != Choice::END) {

		switch (choice) {

		case Choice::PRINT:
			display_inventory(inOutInventory);
			break;

		case Choice::UPDATE:
			update_inventory(inOutInventory);
			break;

		case Choice::NEW:
			add_tool(inOutInventory);
			break;

		case Choice::DELETE:
			delete_tool(inOutInventory);
			break;

		case Choice::END:
			inOutInventory.close();
			break;

		default:
			std::cerr << "Incorrect Choice" << std::endl;
			break;
		}
	}

	return 0;

}

void start_file() 
{
	std::ofstream outHardware{ "hardware.dat", std::ios::out | std::ios::binary };

	if (!outHardware) {
		std::cerr << "File could not be opened." << std::endl;
		std::exit(EXIT_FAILURE);
	}

	std::vector<Tool*> inventory{
		new Tool{ 3,  "Electric sander",	7,	 57.98},
		new Tool{ 17, "Hammer",				76,  11.99},
		new Tool{ 24, "Jig saw",			21,  11.00},
		new Tool{ 39, "Lawn mower",			3,	 79.50},
		new Tool{ 56, "Power saw",			18,	 99.99},
		new Tool{ 68, "Screwdriver",		106, 6.99 },
		new Tool{ 77, "Sledge hammer",		11,	 21.50},
		new Tool{ 83, "Wrench",				34,  7.50 }
	};

	for (const Tool* tools : inventory) {

		outHardware.seekp( (tools->get_record_number() -1) * sizeof(Tool));

		outHardware.write(reinterpret_cast<const char*>(tools), sizeof(Tool));

		delete tools;
	}

	outHardware.close();

}

Choice enterChoice()
{
	int choice{ 0 };

	while (choice < 1 || choice > 5) {

		std::cout << "\nEnter your choice\n"
			<< "1 - Display Inventory\n"
			<< "2 - Update Inventory\n"
			<< "3 - Add new tool\n"
			<< "4 - Delete tool\n"
			<< "5 - End program\n"
			<< "-> ";
		std::cin >> choice;
	}

	return static_cast<Choice>(choice);
}

void outputLine(const Tool& tool)
{
	std::cout << std::left << std::setw(10)
		<< tool.get_record_number() << std::setw(16)
		<< tool.get_name() << std::right << std::setw(10)
		<< tool.get_quantity() << std::setw(10)
		<< tool.get_cost() << std::endl;

}

int	get_record(const char* const prompt)
{
	int record_number;

	do {
		std::cout << prompt << " (1 to 100): ",
			std::cin >> record_number;

	} while (record_number < 1 || record_number > 100);

	return record_number;
}

void display_inventory(std::fstream& inventory)
{
	// Display Column heads

	std::cout << std::left << std::setw(10)
		<< "Record #" << std::setw(16)
		<< "Tool Name" << std::right << std::setw(10)
		<< "Quantity" << std::setw(10)
		<< "Cost" << std::endl;

	Tool tool;
	inventory.seekg(0);
	inventory.read(reinterpret_cast<char*>(&tool), sizeof(Tool));

	while (!inventory.eof()) {

		// skip empty records
		if (tool.get_record_number() != 0) {

			outputLine(tool);
		}

		inventory.read(reinterpret_cast<char*>(&tool), sizeof(Tool));
	}
}

void update_inventory(std::fstream& inventory)
{
	int record_number{ get_record("Enter the number of the record to update") };

	Tool tool;
	inventory.seekg((record_number -1) * sizeof(Tool));
	inventory.read(reinterpret_cast<char*>(&tool), sizeof(Tool));

	if (tool.get_record_number() != 0) {

		outputLine(tool); // Display Tool information

		while (true) {

			std::cout << "\nEnter your choice\n"
				<< "1 - Update Tool Name\n"
				<< "2 - Update Quantity\n"
				<< "3 - Update Cost\n"
				<< "4 - End\n"
				<< "-> ";

			int option;
			std::cin >> option;

			switch (option) {

				case 1: {

					std::string newName;
					std::cout << "New Name -> ",
						std::cin >> newName;
					tool.set_name(newName);
					break;
				}
				case 2: {

					int newQuantity;
					std::cout << "New Quantity -> ",
						std::cin >> newQuantity;
					tool.set_quantity(newQuantity);
					break;
				}
				case 3: {

					double newCost;
					std::cout << "New Cost -> ",
						std::cin >> newCost;
					tool.set_cost(newCost);
					break;
				}
				case 4: {

					std::cout << "Updated." << std::endl;
					outputLine(tool);
					inventory.seekp((record_number -1) * sizeof(Tool));
					inventory.write(reinterpret_cast<const char*>(&tool), sizeof(Tool));

					std::cout << "\nExit...." << std::endl;
					return;
				}
				default: {

					std::cout << "Invalid Option" << std::endl;
					break;
				}
			}
		}
	}
	else {
		std::cerr << "Record Number #" << record_number
			<< " doesn't exist" << std::endl;
	}
}

void add_tool(std::fstream& inventory)
{
	int record_number{ get_record("Enter the new record number") };

	Tool newTool;

	inventory.seekg((record_number -1) * sizeof(Tool));
	inventory.read(reinterpret_cast<char*>(&newTool), sizeof(Tool));

	if (newTool.get_record_number() == 0) {

		std::string name;
		double		cost;
		int			quantity;

		std::cout << "Tool Name -> ";
		std::getline(std::cin, name, '\n');
		
		std::cout << "Quantity -> ",
			std::cin >> quantity;
		
		std::cout << "Cost -> ",
			std::cin >> cost;

		newTool.set_record_number(record_number);
		newTool.set_name(name);
		newTool.set_quantity(quantity);
		newTool.set_cost(cost);

		inventory.seekp((record_number - 1) * sizeof(Tool));
		inventory.write(reinterpret_cast<const char*>(&newTool), sizeof(Tool));

		std::cout << "Added." << std::endl;
		outputLine(newTool);

	}
	else {
		std::cerr << "Record Number #" << record_number
			<< " Already contains information" << std::endl;
	}

}

void delete_tool(std::fstream& inventory)
{
	int record_number{ get_record("Enter the number of the record to delete") };

	Tool tool;
	inventory.seekg((record_number -1) * sizeof(Tool));
	inventory.read(reinterpret_cast<char*>(&tool), sizeof(Tool));

	if (tool.get_record_number()) {

		Tool blankTool{};
		inventory.seekp((record_number -1) * sizeof(Tool));
		inventory.write(reinterpret_cast<const char*>(&blankTool), sizeof(Tool));
		
		std::cout << "Deleted." << std::endl;
		outputLine(tool);
	}
	else {
		std::cerr << "Record Number #" << record_number
			<< " doesn't exist" << std::endl;
	}

}