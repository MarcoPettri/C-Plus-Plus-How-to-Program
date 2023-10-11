// Exercise 15.: Sieve of Eratosthenes

/*
		Modify Exercise 15.23, the Sieve of Eratosthenes, so that, if the
		number the user inputs into the program is not prime, the program displays the prime factors of the
		number. Remember that a prime number's factors are only 1 and the prime number itself. Every
		nonprime number has a unique prime factorization. For example, the factors of 54 are 2, 3, 3 and
		3. When these values are multiplied together, the result is 54. For the number 54, the prime factors
		output should be 2 and 3.
*/


#include<iostream>
#include<iomanip>
#include<bitset>
#include<set>
#include<cstdlib>
#include<limits>

const int SIZE{ 1024 };

void set_primes(std::bitset<SIZE>&);

int SIEVE_OF_ERATOSTHENES_2()
{
    std::bitset<SIZE> primes;

    primes.set();

    set_primes(primes);

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
        std::set<int, std::less<int>> factors{};

        while (number > 1) {
            if (not(number % divisor)) {
               
                number /= divisor;
                factors.insert(divisor);
     
            }
            else {
                ++divisor;
            }
        }

        for (const int& factor : factors) {
            std::cout << factor << (factor != *(factors.crbegin()) ? ", " : "\n ");
        }

    }

    return 0;
}
void set_primes(std::bitset<SIZE>& table)
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