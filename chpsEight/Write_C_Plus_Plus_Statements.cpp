// Exercise 8.8: Write C++ Statements 

/*
	8.8 (Write C++ Statements) For each of the following, write C++ statements that perform the
	specified task. Assume that unsigned integers are stored in four bytes and that the starting address
	of the built-in array is at location 1002500 in memory.

		a) Declare a built-in array of type unsigned int called values with five elements, and
			initialize the elements to the even integers from 2 to 10. Assume that the constant SIZE
			has been defined as 5.
		
		b) Declare a pointer vPtr that points to an object of type unsigned int.
		
		c) Use a for statement to display the elements of built-in array values using array sub-
			script notation.
		
		d) Write two separate statements that assign the starting address of built-in array values
			to pointer variable vPtr.
		
		e) Use a for statement to display the elements of built-in array values using pointer/offset
			notation.
		
		f) Use a for statement to display the elements of built-in array values using pointer/offset
			notation with the built-in array's name as the pointer.
		
		g) Use a for statement to display the elements of built-in array values by subscripting the
			pointer to the built-in array.
		
		h) Refer to the fifth element of values using array subscript notation, pointer/offset notation 
			with the built-in array name's as the pointer, pointer subscript notation and pointer/offset notation.

		i) What address is referenced by vPtr + 3? What value is stored at that location?

		j) Assuming that vPtr points to values[ 4 ], what address is referenced by vPtr -= 3?
			What value is stored at that location?
*/


#include <iostream>
#include <iomanip>
#include <cstddef>

int Write_C_PlusPlus_Statements() {

// A)
	const int SIZE{ 5 };   
	unsigned values[SIZE];

	for (unsigned value{ 2 }; value <= 10; value += 2) { 

		std::size_t index{ value / 2 - 1 };
		values[index] = value; 
	}

// B)
	unsigned* vPtr;

// C)
	std::cout << "C)" << std::endl;
	std::cout << "\nThe elements of built - in array using array subscript notation.\n" << std::endl;
	std::cout << "--> ";

	for (std::size_t index{ 0 }; index < SIZE; ++index) {
		std::cout << values[index] << " "; }

// D)
	vPtr = values;
	// OR
	vPtr = &values[0];

// E)
	std::cout << "\n\nE)" << std::endl;
	std::cout << "\nThe elements of built - in array using pointer / offset notation.\n " << std::endl;
	std::cout << "--> ";

	for (std::size_t offset{ 0 }; offset < SIZE; ++offset) {
		std::cout << *(vPtr + offset) << " ";
	}
	
// F)
	std::cout << "\n\nF)" << std::endl;
	std::cout << "\nThe elements of built - in array using pointer / offset notation" 
		<< "\n    with the built-in array's name as the pointer.\n" << std::endl;
	std::cout << "--> ";

	for (std::size_t offset{ 0 }; offset < SIZE; ++offset) {
		std::cout << *(values + offset) << " ";
	}

// G)
	std::cout << "\n\nG)" << std::endl;
	std::cout << "\nThe elements of built - in array using pointer / subscript notation" 
		<< "\n    with pointer vPtr\n" << std::endl;
	std::cout << "--> ";

	for (std::size_t index{ 0 }; index < SIZE; ++index) {
		std::cout << vPtr[index] << " ";
	}

// H)
	std::cout << "\n\nH)" << std::endl;
	std::cout << "\nThe fifth element of 'values' using array subscript notation, \n"
		<< "   pointer/offset notation with the built-n array name's as the pointer, \n"
		<< "   pointer subscript notation and pointer/offset notation" << std::endl;

	std::cout << "\nH)-1. Using array subscript notation: " << values[4] << std::endl;
	std::cout << "\nH)-2. Using pointer/offset notation \n "
		<< "      with the built-in array name's as the pointer: " << *(values + 4) << std::endl;

	std::cout << "\nH)-3. Using pointer subscript notation: " << vPtr[4] << std::endl;
	std::cout << "\nH)-4. Pointer/offset notation: " << *(vPtr + 4) << std::endl;

// I)
	std::cout << "\n\nI)" << std::endl;
	std::cout << "\aAssuming that unsigned integers are stored in four bytes \n"
		"  and that the starting address  of the built-in array is\n"
		"  at location 1,002,500 in memory" << std::endl;

	std::cout << "\n The Address of vPtr + 3 is 1,002,500 + 3 * 4 = " << (1'002'500 + 3 * 4)
		<< "\n The value is " << *(vPtr + 3);

// J)
	std::cout << "\n\nJ)" << std::endl;
	std::cout << "\n The address of values[4] is 1,002,500 + 4 * 4 = " << (1'002'500 + 4 * 4);
	std::cout << "\n The address of  vPtr -= 3 is " << (1'002'500 + 4 * 4) << " - 3 * 4 = "
		<< (1'002'500 + 4 * 4) - (3 * 4);

	vPtr = &values[4];
	vPtr -= 3;

	std::cout << "\n The value at that location is " << *vPtr;


	return 0;
}