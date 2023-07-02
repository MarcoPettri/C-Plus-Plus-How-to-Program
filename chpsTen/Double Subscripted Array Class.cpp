
// Exercise 10.7: Overloading the Parentheses Operator
/*

		One nice example of overloading the function call
		operator () is to allow another form of double-array subscripting popular in some programming
		languages. Instead of saying

				chessBoard[row][column]

		for an array of objects, overload the function call operator to allow the alternate form

				chessBoard(row, column)

		Create a class DoubleSubscriptedArray that has similar features to class Array in Figs. 10.10–
		10.11. At construction time, the class should be able to create a DoubleSubscriptedArray of any
		number of rows and columns. The class should supply operator() to perform double-subscripting
		operations. For example, in a 3-by-5 DoubleSubscriptedArray called chessBoard, the user could
		write chessBoard(1, 3) to access the element at row 1 and column 3. Remember that operator()
		can receive any number of arguments. The underlying representation of the DoubleSubscriptedArray
		could be a single-subscripted array of integers with rows * columns number of elements. Function
		operator() should perform the proper pointer arithmetic to access each element of the underlying
		array. There should be two versions of operator()—one that returns int& (so that an element of a
		DoubleSubscriptedArray can be used as an lvalue) and one that returns int. The class should also
		provide the following operators: ==, !=, =, << (for outputting the DoubleSubscriptedArray in row and
		column format) and >> (for inputting the entire DoubleSubscriptedArray contents).
*/

#include"DoubleSubscriptedArray.h"


void displayTuple(const std::tuple<int, int>);

int Double_Subscripted_Array_class() {


	DoubleSubscriptedArray arr1{ 4, 3 };
	DoubleSubscriptedArray arr2{ 2, 5 };

	std::cout << "\t\tArray1 \nShape: ";
	displayTuple(arr1.getShape());
	std::cout <<  "\nSize: " << arr1.getSize() << std::endl
		<< arr1 << std::endl;	

	std::cout << "\t\tArray2 \nShape: ";
	displayTuple(arr2.getShape());
	std::cout << "\nSize: " << arr2.getSize() << std::endl
		<< arr2 << std::endl;

	
	// input and print arr1 
	// 76 163 1 55 192 114 36 105 6 990 133 95 //
	std::cout << "\nEnter 12 integers: ",
		std::cin >> arr1;

	std::cout << "\nThe Array1 now contain:\n" << arr1;	

	// input and print arr2
	// 6733 188 153 21 5 3 133 184 185 1954 //
	std::cout << "\nEnter 10 integers: ",
		std::cin >> arr2;

	std::cout << "\nThe Array2 now contain:\n" << arr2 << std::endl;

	// Use overloaded inequality != operator
	if (arr1 != arr2) {
		std::cout << "Array1 and Array2 aren't equal" << std::endl;
	}
	

	std::cout << "\nCreate Array3 using Array1 " << std::endl;
	DoubleSubscriptedArray arr3{ arr1 };

	std::cout << "\n   Array3" << std::endl << arr3;


	// use overloaded assignment (=) operator
	std::cout << "\nAssigning Array2 to Array1:" << std::endl;
	arr1 = arr2; 

	// use overloaded equality (==) operator
	std::cout << "\nEvaluating: Array1 == Array2" << std::endl;

	if (arr1 == arr2) {
		std::cout << "\n\tArray 1\n" << arr1 << std::endl
			<< "\tArray 2\n" << arr2 << std::endl;
	}
	
	//Use overloaded () operator to create rvalue;
	std::cout << "\nArray1 row:1; column:3 = " << arr1(1, 3) << std::endl;

	// use overloaded subscript operator to create lvalue
	std:: cout << "\n\nAssigning 1000 to Array1 row: 1; column:3" << std::endl;
	arr1(1, 3) = 1000;
	std::cout << "\n\tArray1 \n" << arr1 << std::endl;


	// attempt to use out-of-range subscript
	try {
		std::cout << "\nAttempt to assign 34 to Array1 row 4: column: 9" << std::endl;
		arr1(4, 9) = 34; // ERROR: subscript out of range
	}
	catch (std::out_of_range& ex) {
		std::cout << "An exception occurred: " << ex.what() << std::endl;
	}


	arr3(3, 2) = 1;

	std::cout << "\n   Array3\n" << arr3 << std::endl;

	std::cout << "Using negative index\n" << "row: -3; column -2 = "
		<< arr3(-3, -2) << std::endl;

	std::cout << "\nCount of 1 in Array3: " << arr3.count(1) << std::endl;

	
	std::cout << "\nindex of 6 in Array3: ";
	displayTuple(arr3.index(6));
	std::cout << std::endl;
	
	return 0;
}
void displayTuple(std::tuple<int, int> tpl) {
	std::cout << "(" << std::get<0>(tpl) << ", " << std::get<1>(tpl) << ")";
}