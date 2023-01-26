// 6.61 Exercise: Computer-Assisted Instruction: Varying the Types of Problems
/*
	Modify the program of Exercise 6.60 to allow the user to pick a type of arithmetic problem to study.
	An option of 1 means addition problems only, 2 means subtraction problems only, 3 means multiplication problems only,
	4 means division problems only and 5 means a random mixture of all these types.
*/


#include<iostream>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<string>
#include<vector>
#include<locale>
#include<cmath>

int computerAI5(int lvl, int dgts);
int operations(int& lvl, int& num1, int& num2);


int CAI_Varying_The_Types_Of_Problems() {

	char answer;
	int level;
	int digits;
	std::cout << "1 for addition problems only\n"
		<< "2 for subtraction problems only\n"
		<< "3 for multiplication problems only\n"
		<< "4 for integer division problems only\n"
		<< "5 for a random mixture of all these types\n"
		<< "Enter the level >> ",
		std::cin >> level;
	std::cout << "Enter the maximum number of digits: ",
		std::cin >> digits;

	do {
		computerAI5(level, digits);

		std::cout << "\nAnother test?: (y/n) >> ",
			std::cin >> answer;

		if (answer != 'n') {
			std::cout << "\n1 for addition problems only\n"
				<< "2 for subtraction problems only\n"
				<< "3 for multiplication problems only\n"
				<< "4 for integer division problems only\n"
				<< "5 for a random mixture of all these types\n"
				<< "Enter the level >> ",
				std::cin >> level;
			std::cout << "Enter the maximum number of digits: ",
				std::cin >> digits;

			std::cout << std::endl;
		}

	} while (answer != 'n');

	return 0;
}
int operations(int& lvl, int& num1, int& num2) {

	std::srand(static_cast<unsigned int>(std::time(0)));
	int random{ std::rand() % 4 };
	int intRandom{ 2 + std::rand() % 10 };

	switch (random) {

	case 0:
		lvl = ((num1 + (num2 * num1)) / num2) - intRandom;
		std::cout << "((" << num1 << " + ("
			<< num2 << " * " << num1
			<< ") ) / " << num2 << ") - " << intRandom ;
		return lvl;

	case 1:
		lvl = ((intRandom + num1) * (num2 * intRandom / num1)) - num2;
		std::cout << "((" << intRandom << " + " << num1 << ") * ("
			<< num2 << " * " << intRandom << " / " << num1
			<< ") ) - " << num2;
		return lvl;

	case 2:
		lvl = (num2 - num1) * (intRandom * num1) / (intRandom + num2 );
		std::cout << "(" << num2 << " - "
			<< num1 << ") * (" << intRandom << " * " << num1
			<< ") / (" << intRandom << " + " << num2 << ")";
		return lvl;

	case 3:
		lvl = (num1 * num1 * num2) + (num2 + intRandom) / (intRandom * num1 - num2);
		std::cout << "(" << num1 << " * " << num1 << " * " << num2 << ") + ("
			<< num2 << " + " << intRandom << ") / ("
			<< intRandom << " * " << num1 << " - " << num2 << ")";
		return lvl;

	default:
		lvl = (intRandom * (num1 - num2)) + ((num1 * num2) / (intRandom - num1 * intRandom));
		std::cout << "(" << intRandom << " * (" << num1 << " - " << num2
			<< ")) + ((" << num1 << " * " << num2 
			<< ") / (" << intRandom << " - " << num1 
			<< " * " << intRandom << "))";
		return lvl;
	}

}

int computerAI5(int lvl, int dgts) {

	std::srand(static_cast<unsigned int>(std::time(0)));

	dgts = std::pow(10, dgts);

	int number1{ 1 + std::rand() % dgts };
	int number2{ 1 + std::rand() % dgts };
	int index{ std::rand() % 4 };
	int answer;

	std::vector<std::string> possitiveResp{ "Very good!\n", "Excellent!\n",
											"Nice work! \n", "Keep up the good work!\n" };

	std::vector<std::string> negativeResp{ "No. Please try again.\n", "Wrong. Try once more. \n",
											"Don't give up! \n", "No. Keep trying.\n" };
	std::cout.imbue(std::locale(""));


	switch (lvl) {

	case 1:
		lvl = number1 + number2;

		std::cout << number1 << " + "
			<< number2 << " = ",
			std::cin >> answer;
		break;

	case 2:
		lvl = number1 - number2;

		std::cout << number1 << " - "
			<< number2 << " = ",
			std::cin >> answer;
		break;

	case 3:
		lvl = number1 * number2;

		std::cout << number1 << " * "
			<< number2 << " = ",
			std::cin >> answer;
		break;

	case 4:

		lvl = number1 / number2;

		std::cout << number1 << " / "
			<< number2 << " = ",
			std::cin >> answer;
		break;

	case 5:
		lvl = operations(lvl, number1, number2);
		std::cout << " =  ",
			std::cin >> answer;
		break;


	default:
		return 0;
		break;
	}

	if (lvl == answer) { std::cout << possitiveResp.at(index) << std::endl; }
	else { std::cout << negativeResp.at(index) << std::endl; }

	return 1;
}