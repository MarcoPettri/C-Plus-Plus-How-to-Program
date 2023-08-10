// Exercise 13.14: Reading Phone Numbers with an Overloaded Stream Extraction Operator

/*
		In Fig. 10.5, the stream extraction and stream insertion operators were overloaded for input and output of objects
		of the PhoneNumber class. Rewrite the stream extraction operator to perform the following error
		checking on input. The operator >> function will need to be reimplemented.

			a) Input the entire phone number into an array. Test that the proper number of characters
				has been entered. There should be a total of 14 characters read for a phone number of
				the form (800) 555-1212. Use istream member-function clear to set failbit for improper input.

			b) The area code and exchange do not begin with 0 or 1. Test the first digit of the area-
				code and exchange portions of the phone number to be sure that neither begins with 0
				or 1. Use istream member-function clear to set failbit for improper input.

			c) The middle digit of an area code used to be limited to 0 or 1 (though this has changed).
				Test the middle digit for a value of 0 or 1. Use the istream member-function clear to
				set failbit for improper input. If none of the above operations results in failbit being
				set for improper input, copy the parts of the telephone number into the PhoneNumber
				object’s areaCode, exchange and line members. If failbit has been set on the input,
				have the program print an error message and end, rather than print the phone number.

		
*/


#include "PhoneNumber.h"
#include <stdexcept>

int  Reading_Phone_Numbers()
{
	PhoneNumber phone; 

	std::cout << "Enter Phone Number in the form (555) 555-5555: " ,
		std::cin >> phone;

	std::cout << "\nThe Phone Number entered was:\n" << phone << std::endl;

	//testing invalid input
	try {

		std::cout << "Enter Phone Number in the form (555) 555-5555: ",
			std::cin >> phone;

		std::cout << "\nThe Phone Number entered was:\n" << phone << std::endl;
	}
	catch (const std::invalid_argument& e) {

		std::cout << e.what() << "\n"
			<< "\n rdstate(): " << std::cin.rdstate()
			<< "\n     eof(): " << std::cin.eof()
			<< "\n    fail(): " << std::cin.fail()
			<< "\n     bad(): " << std::cin.bad()
			<< "\n    good(): " << std::cin.good() 
			<< std::endl;

			// Restoring standard input stream
			std::cin.clear();
	}

	return 0;
}
