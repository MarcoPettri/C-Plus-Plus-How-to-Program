//6.60  Exercise: Computer-Assisted Instruction: Difficulty Levels

/*
	Exercises 6.57–6.59 developed a computer-assisted instruction program 
	to help teach an elementary-school student multiplication. 
	Modify the program to allow the user to enter a difficulty level. 
	At a difficulty level of 1, the program should use only single-digit numbers in the problems; 
	at a difficulty level of 2, numbers as large as two digits, and so on.
*/


#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<vector>
#include<locale>
#include<cmath>

void computerAI4(int lvl);

int CAI_DifficultyLevels() {

	char answer;
	int level;
	std::cout << "Enter the level >> ",
		std::cin >> level;

	do {
		computerAI4(level);

		std::cout << "\nAnother test?: (y/n) >> ",
			std::cin >> answer;

		if (answer != 'n') {
			std::cout << "Enter the level >> ",
				std::cin >> level;
		}

	} while (answer != 'n');

	return 0;
}

void computerAI4(int lvl) {

	std::srand(static_cast<unsigned int>(std::time(0)));

	lvl = std::pow(10, lvl);

	int factor1{ 1 + std::rand() % lvl};
	int factor2{ 1 + std::rand() % lvl };
	int answer;

	std::vector<std::string> possitiveResp{ "Very good!\n", "Excellent!\n",
											"Nice work! \n", "Keep up the good work!\n" };

	std::vector<std::string> negativeResp{ "No. Please try again.\n", "Wrong. Try once more. \n",
											"Don't give up! \n", "No. Keep trying.\n" };
	std::cout.imbue(std::locale(""));
	do {
		int random{ std::rand() % 4 };

		std::cout << "How much is " << factor1
			<< " times " << factor2 << "? -->  ",
			std::cin >> answer;

		if ((factor1 * factor2) == answer) { std::cout << possitiveResp.at(random) << std::endl; }
		else { std::cout << negativeResp.at(random) << std::endl; }

		
	} while ((factor1 * factor2) != answer);

}

