// 6.49 Exercise: Pass-by-Value vs. Pass-by-Reference

/*
	 Write a complete C++ program with the two alternate
	functions specified below, each of which simply triples the variable count defined in main. Then
	compare and contrast the two approaches. These two functions are

	a) function tripleByValue that passes a copy of count by value, 
		triples the copy and returns the new value and
	b) function tripleByReference that passes count by reference via a reference parameter
		and triples the original value of count through its alias (i.e., the reference parameter)
*/

#include<iostream>

inline int tripleByValue(int number) { return number *= 3; }
inline int tripleByReference(int& number) { return number *= 3; }

int PassByValue_PassByReference() {
	
	int count{ 3 };


	std::cout << "Count = " << count << std::endl
		<< "Pass By value: " << tripleByValue(count);
	std::cout << "\nCount = " << count << std::endl;


	std::cout << "\nCount = " << count << std::endl
		<< "Pass by Reference: " << tripleByReference(count)
		<< "\nCount = " << count;


	return 0;
}