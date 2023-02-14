// Simpletron.cpp

/*
  Contains the definition of the member functions of the Simpletron class
*/

#include "Simpletron.h"

bool Simpletron::perform(int operation, int address) {

	if (MEMORY_SIZE > address && operation > 9) {
		switch (operation)
		{
		case SML::READ: 
			std::cout << ">>: ", std::cin >> MEMORY[address]; 
			return true;

		case SML::WRITE: 
			std::cout << MEMORY[address]; 
			return true;

		case SML::LOAD: 
			ACUMULATOR = MEMORY[address]; 
			return true;

		case SML::STORE:
			MEMORY[address] = ACUMULATOR;
			return true;

		case SML::ADD:
			ACUMULATOR += MEMORY[address];
			return true;

		case SML::SUBTRACT:
			ACUMULATOR -= MEMORY[address];
			return true;

		case SML::DIVIDE:
			ACUMULATOR /= MEMORY[address];
			return true;

		case SML::MULTIPLY:
			ACUMULATOR *= MEMORY[address];
			return true;

		case SML::BRANCH:
			MEMORY[address] = ACUMULATOR;
			return true;

		case SML::BRANCHNEG:
			if(ACUMULATOR < 0) { MEMORY[address] = ACUMULATOR; }
			return true;

		case SML::BRANCHZERO:
			if (ACUMULATOR == 0) { MEMORY[address] = ACUMULATOR; }
			return true;

		case SML::HALT:
			reset();
			return true;

		default:
			return false;
		}
	}
	else {
		if (MEMORY_SIZE <= address) { std::cout << "MEMORY ERROR: Subscript out of range" << std::endl; }
		else { std::cout << "OPERATION ERROR: '" << operation << "' is not defined" << std::endl; }

		return false;
	}
}

void Simpletron::reset() {
	std::fill_n(MEMORY, MEMORY_SIZE, 0);
	ACUMULATOR = 0;
}

int Simpletron::max() const {

	static int largest{ 0 };
	for (std::size_t index{ 0 }; index < MEMORY_SIZE; index++) {

		if (MEMORY[index]) {
			if (MEMORY[index] > largest) {
				largest = MEMORY[index];
			}
		}
	}
	return largest;
}
int Simpletron::min() const {

	static int smallest{ 0 };
	for (std::size_t index{ 0 }; index < MEMORY_SIZE; index++) {

		if (MEMORY[index]) {
			if (MEMORY[index] > smallest) {
				smallest = MEMORY[index];
			}
		}
	}
	return smallest;
}
void Simpletron::displayMemory() const {

	std::cout << "MEMORY:\n\n" << std::setw(4);

	for (int i{ 0 }; i < 10; i++) {
		std::cout << "  " << std::setfill(' ')
			<< std::setw(4) << i << " ";
	}

	std::cout << std::endl;
	for (int i{ 0 }; i < MEMORY_SIZE; i++) {


		if (i % 10 == 0) { std::cout << std::setw(2) << i; }

		std::cout << " +" << std::setfill('0')
			<< std::setw(4) << MEMORY[i];

		std::cout << ((i + 1) % 10 == 0 ? '\n' : ' ');

	}
	std::cout << std::setfill(' ') << std::endl;
}

void Simpletron::displayOperations() const {

	std::cout << "\t\tOperations Code\n"

		<< "\nInput/Output Operations: \n"
		<< "\tRead -> 10\n"
		<< "\twrite -> 10\n"

		<< "\nLoad and Store Operations: \n"
		<< "\tload -> 10\n"
		<< "\tstore -> 10\n"

		<< "\nArithmetic Operations: \n"
		<< "\tadd -> 10\n"
		<< "\tsubtract -> 10\n"
		<< "\tdivide -> 10\n"
		<< "\tmultiply -> 10\n"

		<< "\nTransfer-Of-Control Operations: \n"
		<< "\tbranch -> 10\n"
		<< "\tbranchneg -> 10\n"
		<< "\tbranchzero -> 10\n"
		<< "\thalt -> 10"
		<< std::endl;

}

