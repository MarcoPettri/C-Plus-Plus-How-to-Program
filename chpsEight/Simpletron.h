//Simpletron.h
/*
	Simpletron class for Exercise 8.15 : Machine-Language Programming
*/
#ifndef SIMPLETRON_H
#define SIMPLETRON_H

#include<iostream>
#include<iomanip>
#include<cstddef>
#include<algorithm>


// Simpletron Machine Language Namespace
namespace SML {

	// Input/Output Operations
	const int READ{ 10 }; // Read a word from the keyboard into a specific location in memory.
	const int WRITE{ 11 }; // Write a word from a specific location in memory to the screen.

	// Load and Store Operations
	const int LOAD{ 20 }; // Load a word from a specific location in memory into the accumulator.
	const int STORE{ 21 }; // Store a word from the accumulator into a specific location in memory.

	// Arithmetic Operations
	const int ADD{ 30 }; // Add a word from a specific location in memory to the word in the accumulator(leave result in accumulator).
	const int SUBTRACT{ 31 }; //   Subtract a word from a specific location in memory from the word in the accumulator(leave result in accumulator).
	const int DIVIDE{ 32 }; // Divide a word from a specific location in memory into the word in the accumulator(leave result in accumulator).
	const int MULTIPLY{ 33 }; // Multiply a word from a specific location in memory by the word in the accumulator(leave result in accumulator).

	// Transfer-Of-Control Operations
	const int BRANCH{ 40 }; // Branch to a specific location in memory.
	const int BRANCHNEG{ 41 }; // Branch to a specific location in memory if the accumulator is negative
	const int BRANCHZERO{ 42 }; // Branch to a specific location in memory if the accumulator is zero.
	const int HALT{ 43 }; // Halt—the program has completed its task.

}

class Simpletron {
public:

	static const std::size_t MEMORY_SIZE{ 100 };

	Simpletron() {
		std::fill_n(MEMORY, MEMORY_SIZE, 0);
		ACUMULATOR = 0;
	}


	// Getters Functions 
	void displayMemory() const;
	void displayOperations() const;
	int max() const;
	int min() const;

	// Setter Functions
	bool perform(int operation, int address);
	void reset(); 


private:
	int ACUMULATOR;
	int MEMORY[MEMORY_SIZE];
};

#endif // SIMPLETRON_H