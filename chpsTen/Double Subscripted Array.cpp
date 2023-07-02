// Double Subscripted Array.cpp
/*
		Double Subscripted Array class member-function definitions

*/

#include "DoubleSubscriptedArray.h"


// Default Constructor  //
DoubleSubscriptedArray::DoubleSubscriptedArray(int r, int c) {
	
	if (r < 0 || c < 0) {
		throw std::invalid_argument("Array size must be greater than 0");
	}

	shape = std::make_tuple(static_cast<std::size_t>(r),
							static_cast<std::size_t>(c));

	ptr = new int[r * c] {};
}


// Copy Constructor  //
DoubleSubscriptedArray::DoubleSubscriptedArray(const DoubleSubscriptedArray& arr)
	: shape{ arr.shape }, ptr{ new int[arr.getSize()] } {


	for (std::size_t i{ 0 }, size{ getSize() }; i < size; ++i) {
		ptr[i] = arr.ptr[i];
	}
}

// Destructor 
DoubleSubscriptedArray::~DoubleSubscriptedArray() {
	delete[] ptr;
}

// Assignment operator
const DoubleSubscriptedArray& DoubleSubscriptedArray::operator=(const DoubleSubscriptedArray& arr) {
	
	if (&arr != this) {

		if (this->getSize() != arr.getSize()) {

			delete[] ptr;

			shape = arr.shape;
			ptr = new int[getSize()];
		}

		for (std::size_t i{ 0 }, size{ getSize() }; i < size; ++i) {
			ptr[i] = arr.ptr[i];
		}
	}

	return *this;
}

// Overloaded () operator; return lvalue //
int& DoubleSubscriptedArray::operator()(int row, int column) {

	int n_row{ static_cast<int>(std::get<0>(shape)) };
	int n_column{ static_cast<int>(std::get<1>(shape)) };
	
	if ((row > -n_row && row < n_row) && (column > -n_column && column < n_column)) {

		if (row < 0) { row += n_row; }
		if (column < 0) { column += n_column; }

		int index{ n_column * row + column };

		return ptr[index];
	}
	else {
		throw std::out_of_range{ "Subscript out of range" };
	}
}

// Overloaded () operator; return rvalue //
int DoubleSubscriptedArray::operator()(int row, int column) const {

	int n_row{ static_cast<int>(std::get<0>(shape)) };
	int n_column{ static_cast<int>(std::get<1>(shape)) };
	
	if ((row > -n_row && row < n_row) && (column > -n_column && column < n_column)) {

		if (row < 0) { row += n_row; }
		if (column < 0) { column += n_column; }

		int index{ n_column * row + column };

		return ptr[index];
	}
	else {
		throw std::out_of_range{ "Subscript out of range" };
	}

}

// Equality operator
bool DoubleSubscriptedArray::operator==(const DoubleSubscriptedArray& arr) const {

	
	if (this->getSize() == arr.getSize()) {

		std::size_t size{ getSize() };

		for (std::size_t i{ 0 }; i < size; ++i) {
			if (this->ptr[i] != arr.ptr[i]) {
				return false;
			}
		}
		return true;
	}

	return false;
}
std::size_t DoubleSubscriptedArray::getSize() const {
	return std::get<0>(shape) * std::get<1>(shape);
}

// Utility functions //

// Return index of x
std::tuple<std::size_t, std::size_t>  DoubleSubscriptedArray::index(int x) const {

	std::size_t size{ getSize() };
	std::size_t numberColumns{ std::get<1>(getShape()) };
	for (std::size_t i{ 0 }; i < size; ++i) {
		if (ptr[i] == x) {
			return std::make_tuple(i / numberColumns, i % numberColumns);
		}
	}

	return std::make_tuple(-1, -1);
}

// Returns the count of x
int DoubleSubscriptedArray::count(int x) const {
	
	int times{ 0 };
	std::size_t size{ getSize() };

	for (std::size_t i{ 0 }; i < size; ++i) {

		if (x == ptr[i]) { ++times; }
	}
	return times;
}

//Returns the integer  with the highest value
int DoubleSubscriptedArray::max() const {

	int number{ ptr[0] };

	for (std::size_t i{ 1 }, size{ getSize() }; i < size; ++i) {
		if (ptr[i] > number) {
			number = ptr[i];
		}
	}
	return number;
}

//Returns the integer with the smallest value
int DoubleSubscriptedArray::min() const {

	int number{ ptr[0] };

	for (std::size_t i{ 1 }, size{ getSize() }; i < size; ++i) {
		if (ptr[i] < number) {
			number = ptr[i];
		}
	}
	return number;
}

// insertion and extraction operators  //

std::ostream& operator<<(std::ostream& out, const DoubleSubscriptedArray& self) {

	std::size_t size{ self.getSize() };
	std::size_t n_columns{ std::get<1>(self.getShape()) };
	int spaces{ 1 };

	for (int i{ self.max() }; i > 10; i /= 10, ++spaces);

	out << "[" << std::setw(spaces);

	for (std::size_t index{ 0 }; index < size; ++index) {
		
		out << self.ptr[index];

		if ((index +1) % n_columns == 0) {

			out << ']' << std::endl;

			if (index + 1 < size) { 
				out << "[" << std::setw(spaces); 
			}
		}
		else {
			out << ", " << std::setw(spaces); 
		}

	}
	
	return out;
}

std::istream& operator>>(std::istream& input, DoubleSubscriptedArray& self) {

	std::size_t size{ self.getSize() };

	for (size_t index{ 0 }; index < size; ++index) {

		input >> self.ptr[index];
	}

	return input;
}