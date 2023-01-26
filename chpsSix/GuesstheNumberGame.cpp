// 6.34 Exercise: Guess-the-Number Game
/*
	Write a program that plays the game of “guess the number” as
	follows: Your program chooses the number to be guessed by selecting an integer at random in the
	range 1 to 1000. The program then displays the following:

				I have a number between 1 and 1000.
				Can you guess my number?
				Please type your first guess.

	The player then types a first guess. The program responds with one of the following:

				1. Excellent! You guessed the number!
					Would you like to play again (y or n)?
				2. Too low. Try again.
				3. Too high. Try again.

	If the player’s guess is incorrect, your program should loop until the player finally gets the number
	right. Your program should keep telling the player Too high or Too low to help the player “zero in”
	on the correct answer.
*/

#include<iostream>
#include<random>
#include<ctime>

void guessGamme();
bool test(int guess, int answer);

int GuessTheNumberGame() {

	std::srand(std::time(0));
	guessGamme();
	return 0;
}

void guessGamme() {

	char response;
	do {
		
		int guess;
		int answer{ 1 + std::rand() % 1000 };
		
		std::cout << "I have number between 1 and 100.\n"
			<< "Can you guess my number?\n"
			<< "Please type your first guess."
			<< std::endl << ">> ",
			std::cin >> guess;

		while (!test(guess, answer)) {std::cout << ">> ", std::cin >> guess; }

		std::cout << "\nExcellent! You guess the number !\n"
			<< "Would you like to play again (y or n)?: ",
			std::cin >> response;

		std::cout << std::endl;

	} while (response == 'y');
}

bool test(int guess, int answer) {

	if (guess == answer) { return true; }

	if (guess < answer) { std::cout << "too low. Try again. \n"; }
	else { std::cout << "Too high. Try again. \n"; }

	return false;
}

