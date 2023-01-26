// Exercise 7.21: Workshop Summary
/*
	Use a two-dimensional array to solve the following problem. A craft
	workshop has three craftspeople (1 to 3) who produce four different products (1 to 4). Once a day,
	each craftsperson passes in a slip for each different type of product completed. Each slip contains
	the following:
				a) The craft-person's number
				b) The product number
				c) The quantity of items completed
	Thus, each craftsperson passes in between 0 and 4 production slips per day. Write a program that
	will read in the information as supplied on each individual production slip and summarize the total
	items manufactured by a craftsperson by product. All totals should be stored in the two-dimensional
	array stock. After processing all the information for the last month, print the results in tabular
	format with each column representing a particular product and each row representing a particular
	craftsperson. Total across each row to get the total quantity manufactured by each craftsperson for
	last month; total across each column to get the total quantity manufactured of each product for last
	month. Display all this information in a tabular format

*/

#include<iostream>
#include<iomanip>
#include<cstddef>
#include<array>

const std::size_t  products{ 4 };
const std::size_t  craftspeople{ 3 };

int sum(const std::array<int, products>&);

int WorkshopSummary() {

	// Workshop Summary
	std::array<std::array<int, products>, craftspeople> summary{};

// Processing Phase: 

	int craftsmanNumber;
	std::cout << "Enter the craft-person's number(-1 to exit): ",
		std::cin >> craftsmanNumber;

	while (-1 != craftsmanNumber) {

		//the workshop has three craftspeople (1 to 3), so 0 < craft-person's number < 4
		if (craftsmanNumber < 4 && craftsmanNumber > 0) {

			int productNumber;
			std::cout << "Enter the Product number: ",
				std::cin >> productNumber;

			// Each craftsman produces four different products, so 0 < Product number < 5
			if (productNumber > 0 && productNumber < 5) {

				int quantity;
				std::cout << "Enter the quantity of items completed ",
					std::cin >> quantity;

				//The number of products produced must be positive
				if (quantity > 0) {
					--craftsmanNumber, --productNumber;
					summary[craftsmanNumber][productNumber] = quantity;
				}
				else {
					std::cout << "The quantity must be positive\n\n";
				}
			}
			else {
				std::cout << "The Product Number must be between 1 and 4.\n\n";
			}
		}
		else {
			std::cout << "The number of the craftsman must be between 1 and 3..\n\n";

		}

		std::cout << "\n\nEnter the craft-person's number(-1 to exit): ",
			std::cin >> craftsmanNumber;
	}

// Termination Phase: 
	std::cout << "\n\n" << std::setw(60) << "Workshop Summary \n\n";

	std::cout << "\n\t\t Product 1" 
		<< std::setw(15) << "Product 2" 
		<< std::setw(15) << "Product 3" 
		<< std::setw(15) << "Product 4"
		<< std::setw(17) << "Total\n\n";

	int craftsman{ 1 };

	for (auto const& rows : summary) {

		int total = sum(rows);

		std::cout << "Craftsman " << craftsman++;

		for (const int& product : rows) { 
			std::cout << std::setw(15) << product ;
		}

		std::cout << std::setw(15) << total << std::endl;
	}
	return 0;
}

int sum(const std::array<int, products>& arr) {
	//Returns the sum of all elements in the array

	int total{ 0 };

	for (int const& elem : arr) { total += elem; }
	return total;
}