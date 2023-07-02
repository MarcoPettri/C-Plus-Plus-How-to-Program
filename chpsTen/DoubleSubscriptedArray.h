//DoubleSubscriptedArray.H

/*
	Double Subscripted Array Class for Exercise 10.7: Overloading the Parentheses Operator

*/

#ifndef Double_Subscripted_Array_H
#define Double_Subscripted_Array_H

#include<iostream>
#include<cstddef>
#include<tuple>
#include<stdexcept>
#include<iomanip>

class DoubleSubscriptedArray {

	friend std::ostream& operator<<(std::ostream&, const DoubleSubscriptedArray&);
	friend std::istream& operator>>(std::istream&, DoubleSubscriptedArray&);

public:

	DoubleSubscriptedArray(int row, int column); // Default Constructor

	DoubleSubscriptedArray(const DoubleSubscriptedArray&); // Copy Constructor

	~DoubleSubscriptedArray(); // Destructor

	const DoubleSubscriptedArray& operator=(const DoubleSubscriptedArray&); // assignment operator

	// Parentheses Operator, Returns the i-th, j-th position (accepts negative index) 
	int& operator()(int row, int column);
	int operator()(int row, int column) const;


	// Equality  and inequality Operator
	bool operator==(const DoubleSubscriptedArray&) const; 

	bool operator!=(const DoubleSubscriptedArray& right) const {
		return !(*this == right);
	}

	// Return zero-based index in the array of the first item whose value is equal to x, 
	// otherwise (-1,-1)
	std::tuple<std::size_t, std::size_t> index(int) const;

	// Return shape (row, column)
	std::tuple<std::size_t, std::size_t> getShape() const { return shape; } 

	// Return Size of the array
	std::size_t getSize() const;

	// Return the number of times x appears in the array
	int count(int x) const;

	//Returns the integer  with the highest value
	int max() const;
	//Returns the integer with the smallest value
	int min() const;


private:
	std::tuple<std::size_t, std::size_t> shape;
	int* ptr;

};


#endif // !Double_Subscripted_Array_H

