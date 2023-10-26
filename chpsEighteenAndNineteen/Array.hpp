//Array.hpp
/*
    Array Class Template for exercise 18.x: Array Class Template
*/


#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <memory> 

template<typename T>
class Array {

    friend std::ostream& operator<<(std::ostream& out, const Array<T>& rhs)
    {

        for (size_t i{ 0 }; i < rhs.size; ++i) {
            out << rhs.ptr[i] << "  ";
        }
        out << std::endl;
        return out;
    }

    friend std::istream& operator>>(std::istream& input, Array<T>& rhs)
    {
        for (size_t i{ 0 }; i < rhs.size; ++i) {
            input >> rhs.ptr[i];
        }
        return input;
    }

public:
    // Default Constructor
    explicit Array(std::size_t arraySize = 10)
        : size{ (arraySize > 0 ? static_cast<size_t>(arraySize) :
             throw std::invalid_argument{"Array size must be greater than 0"}) },
        ptr{ std::make_unique<int[]>(size) } { }

    //copy constructor
    Array(const Array<T>& arrayToCopy)
        : size{ arrayToCopy.size }, ptr{ std::make_unique<T[]>(size) }
    {
        for (size_t i{ 0 }; i < size; ++i) {
            ptr[i] = arrayToCopy.ptr[i]; // copy into object
        }
    }

    // assignment Operator
    const Array& operator=(const Array<T>& right)
    {
        if (&right != this) { // avoid self-assignment
            // for Arrays of different sizes, deallocate original
            // left-side Array, then allocate new left-side Array
            if (size != right.size) {
                size = right.size; // resize this object
                ptr = std::make_unique<T[]>(size); // create space for copy
            }

            for (size_t i{ 0 }; i < size; ++i) {
                ptr[i] = right.ptr[i];
            }
        }

        return *this;
    }

    // Equality Operator
    bool operator==(const Array<T>& right) const
    {
        if (size != right.size) {
            return false;
        }

        for (size_t i{ 0 }; i < size; ++i) {
            if (ptr[i] != right.ptr[i]) {
                return false;
            }
        }

        return true;
    }

    // inequality operator
    bool operator!=(const Array<T>& right) const {
        return !(*this == right); 
    }

    // subscript operator for non-const objects returns modifiable lvalue
    int& operator[](int subscript)
    {

        if (subscript < 0 || subscript >= size) {
            throw std::out_of_range{ "Subscript out of range" };
        }

        return ptr[subscript];
    }

    // subscript operator for const objects returns rvalue
    int operator[](int subscript) const
    {

        if (subscript < 0 || subscript >= size) {
            throw std::out_of_range{ "Subscript out of range" };
        }

        return ptr[subscript];
    }

    size_t getSize()const { return size; } // return size

private:
    size_t size;
    std::unique_ptr<T[]> ptr; 
};

#endif

