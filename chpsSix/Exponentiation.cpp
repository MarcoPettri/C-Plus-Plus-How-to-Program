//6.18 (Exponentiation) 

/*
	Write a function integerPower(base, exponent) that returns the value of base^exponent
	For example, integerPower(3, 4) = 3 * 3 * 3 * 3. Assume that exponent is a positive, nonzero
	integer and that base is an integer.Do not use any math library functions.
*/

#include<iostream>
#include<locale>

int64_t intergerPower(const int& base, const unsigned& exponent);

 int Exponentation() {

	 int base, exponent;
	 std::cout << "Enter the Base: ",
		 std::cin >> base;
		 
	 std::cout << "Enter the Exponent: ",
		 std::cin >> exponent;

	 std::cout.imbue(std::locale(""));
	 std::cout << "The Result is: ";

	 if (base < 0) {
		 
		 if (exponent % 2 != 0) {

			std::cout << intergerPower(base * -1, exponent) * -1;
		 }
		 else {
			 std::cout << intergerPower(base * -1, exponent);
		 }
	 }

	 else {
		 std::cout << intergerPower(base, exponent);
	 }

	 return 0;
 }

int64_t intergerPower(const int& base, const unsigned& exponent) {

	unsigned long long value{ 1 };

	for (int i{ 0 }; i < exponent; i++) {
		value *= base;
	}
	return value;
}

