// 6.57 Exercise: Computer-Assisted Instruction

/* 
	The use of computers in education is referred to as computer-assisted instruction (CAI).
	Write a program that will help an elementary-school student learn multiplication. 
	Use the rand function to produce two positive one-digit integers. 
	The program should then prompt the user with a question, such as

				How much is 6 times 7?

	The student then inputs the answer. Next, the program checks the student's answer. 
	If it's correct, display the message "Very good!"  and ask another multiplication question. 
	If the answer is wrong, display the message "No. Please try again." 
	and let the student try the same question repeatedly until the student finally gets it right. 
	A separate function should be used to generate each new question. 
	This function should be called once when the application begins execution and each time 
	the user answers the question correctly.
*/

#include<iostream>
#include<cstdlib>
#include<ctime>

int computerAI();

int Computer_Assisted_Instruction() {

	int sintinela{};
	int answer;

	do {
		sintinela = computerAI();

		if (!sintinela) {
			std::cout << "\nOther test?\n" 
				<< "Enter 0 to exit and any number to continue: ",
				std::cin >> answer;
		}
		else {
			do {
				std::cout << "How much is?: ",
					std::cin >> answer;

				if (sintinela != answer) {
					std::cout << "No. Please try again." << std::endl;
				}
				else { std::cout << "Very good!\n"; }

			} while (answer != sintinela);
		}
		
	} while (answer);

	return 0;
}

int computerAI() {
	
	std::srand(static_cast<unsigned int>(std::time(0)));

	int factor1{ 1 + std::rand() % 10 };
	int factor2{ 1 + std::rand() % 10 };
	int answer;

	std::cout << "How much is " << factor1
		<< " times " << factor2 << "?: ",
		std::cin >> answer;
	
	if (answer == (factor1 * factor2)) { 
		std::cout << "Very Good!\n"; 
		return 0;
	}
	else { 
		std::cout << "No, Please try again." << std::endl; 
		return factor1 * factor2;
	}
}

