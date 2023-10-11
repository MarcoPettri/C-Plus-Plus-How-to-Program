// Exercise 15.: Prime Factors

/*

		 Modify Exercise 15.24 so that, if the number the user inputs into the program is not prime, 
         the program displays the prime factors of the number and the number of times each prime factor 
         appears in the unique prime factorization. For example, the output for the number 54 should be
			The unique prime factorization of 54 is: 2 * 3 * 3 * 3
*/


#include<iostream>
#include<iomanip>
#include<bitset>
#include<set>
#include<cstdlib>
#include<limits>

const int SIZE{ 1024 };

void set_primes2(std::bitset<SIZE>&);

int main()
{
    std::bitset<SIZE> primes;

    primes.set();

    set_primes2(primes);

    int number;

    do
    {

        std::cout << "Enter a number between 2 and 1023 to find out if it's prime: ";

        std::cin >> number;

        if (std::cin.fail() || number < 2 || number > 1023) {

            std::cout << "Enter a valid integer value!\n\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

    } while (number < 2 || number > 1023);

    if (primes[number]) {
        std::cout << number << " is prime" << std::endl;
    }
    else {
        std::cout << "Factors of " << number << ": ";

        int divisor{ 2 };

        while (number > 1) {
            if (not(number % divisor)) {

                number /= divisor;
                std::cout << divisor << (number > 1 ? " * " : "\n");

            }
            else {
                ++divisor;
            }
        }

    }

    return 0;
}


void set_primes2(std::bitset<SIZE>& table)
{


    for (std::size_t i{ 2 }; i * i < table.size(); ++i) {

        if (table[i]) {
            for (std::size_t j = i * i; j < table.size(); j += i)
                table.reset(j);
        }
    }
    std::cout << "Primes from 2 to 1023:\n\n";

    for (std::size_t index{ 2 }; index < table.size(); ++index) {
        if (table[index]) {
            std::cout << std::setw(10) << index << " ";
        }
    }
    std::cout << "\n\n";
}