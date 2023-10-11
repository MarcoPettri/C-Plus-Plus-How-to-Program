// Exercise 15.: Sieve of Eratosthenes with bitset

/*

		This exercise revisits the Sieve of Eratosthenes for finding
		prime numbers that we discussed in Exercise 7.27. Use a bitset to implement the algorithm. Your
		program should display all the prime numbers from 2 to 1023, then allow the user to enter a number
		to determine whether that number is prime.
*/


#include<iostream>
#include<iomanip>
#include<bitset>
#include<cstdlib>
#include<limits>

const int SIZE{ 1024 };

void setPrimes(std::bitset<SIZE>&);

int SIEVE_OF_ERATOSTHENES()
{
	std::bitset<SIZE> primes;

	primes.set();

    setPrimes(primes);
    
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

    std::cout << number << (primes[number] ? " is" : " is not") << " prime" << std::endl;

	return 0;
}
void setPrimes(std::bitset<SIZE>& table)
{


    for (std::size_t i{ 2 }; i * i < table.size(); ++i) {

        if (table[i]) {
            for (std::size_t j = i * i; j < table.size(); j += i)
                table.reset(j);
        }
    }
    std::cout << "Primes from 2 to 1023:\n\n";

    for (std::size_t index{ 2 }; index < table.size(); ++index){
        if (table[index]) {
            std::cout << std::setw(10) << index << " ";
        }
    }
    std::cout << "\n\n" ;
}