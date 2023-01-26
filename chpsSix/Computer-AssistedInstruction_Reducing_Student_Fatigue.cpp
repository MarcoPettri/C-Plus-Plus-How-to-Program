// Exercise 6.58: Computer-Assisted Instruction: Reducing Student Fatigue

/*
		One problem in CAI environments is student fatigue.
		This can be reduced by varying the computer's responses to hold the student's attention.
		Modify the program of Exercise 6.57 so that various comments are displayed for
		each answer as follows:
			Possible responses to a correct answer:
				Very good!
				Excellent!
				Nice work!
				Keep up the good work!

			Possible responses to an incorrect answer:
				No. Please try again.
				Wrong. Try once more.
				Don't give up!
				No. Keep trying.

		Use random-number generation to choose a number from 1 to 4 that will be used to select
		one of the four appropriate responses to each correct or incorrect answer. Use a switch statement to
		issue the responses.

*/


#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<vector>

void computerAI2();

int CAI_ReducingStudentFatigue() {

	char answer;

	do {
		computerAI2();

		std::cout << "\nAnother test?: (y/n) >> ",
			std::cin >> answer;
	} while (answer != 'n');

	return 0;
}

void computerAI2() {

	std::srand(static_cast<unsigned int>(std::time(0)));

	int factor1{ 1 + std::rand() % 10 };
	int factor2{ 1 + std::rand() % 10 };
	int answer;
	
	std::vector<std::string> possitiveResp{ "Very good!\n", "Excellent!\n",
											"Nice work! \n", "Keep up the good work!\n" };

	std::vector<std::string> negativeResp{ "No. Please try again.\n", "Wrong. Try once more. \n",
											"Don't give up! \n", "No. Keep trying.\n" };

	do {
		int random{ std::rand() % 4 };

		std::cout << "How much is " << factor1
			<< " times " << factor2 << "? -->  ",
			std::cin >> answer;

		if ((factor1 * factor2) == answer) { std::cout << possitiveResp.at(random) << std::endl; }
		else { std::cout << negativeResp.at(random) << std::endl; }


	} while ((factor1 * factor2) != answer);

}