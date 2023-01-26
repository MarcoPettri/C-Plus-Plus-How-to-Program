// 4.17 Exercise: Calculating Sales

/*
	An online retailer sells five products whose retail prices are as follows:
	Product 1, $2.98; product 2, $4.50; product 3, $9.98; product 4, $4.49 and product 5, $6.87.
	Write an application that reads a series of pairs of numbers as follows
		a) product number
		b) quantity sold
	Your program should use a switch statement to determine the retail price for each product. It
	should calculate and display the total retail value of all products sold. Use a sentinel-controlled
	loop to determine when the program should stop looping and display the final results.
*/

#include<iostream>

int CalculatingSales() {

	double total{ 0.0 };


	int productNumber;

	std::cout << "Enter the Product Number: ";

	while(std::cin >> productNumber) {

		int quantity;

		std::cout << "Enter the quantity of product sold: ",
			std::cin >> quantity;

		switch (productNumber) {

		case 1:
			total += (quantity * 2.98);
			break;
		case 2:
			total += (quantity * 4.50);
			break;
		case 3:
			total += (quantity * 9.98);
			break;
		case 4:
			total += (quantity * 4.49);
			break;
		case 5:
			total += (quantity * 6.87);
			break;
		default:
			std::cout << "The Number " << productNumber
				<< " doesn't match any product number in the system" << std::endl ;

			break;
		}
		
		std::cout << "\nType the end-of-file indicator to terminate input:\n" 
			<< " On UNIX/Linux/Mac OS X type <Ctrl> d then press Enter\n"
			<< " On Windows type <Ctrl> z then press Enter\n"
			<< std:: endl << "Enter the Product Number: ";
	}


	std::cout << "Total: " << total;

	return 0;
}