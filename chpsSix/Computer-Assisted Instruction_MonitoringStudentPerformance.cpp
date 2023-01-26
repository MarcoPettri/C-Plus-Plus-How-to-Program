// 6.59 Exercise: Computer-Assisted Instruction: Monitoring Student Performance
/*
	More sophisticated computer-assisted instruction systems monitor the student's performance over a period of time. 
	The decision to begin a new topic is often based on the student's success with previous topics. 
	Modify the program of Exercise 6.58 to count the number of correct and incorrect responses typed by the student. 
	After the student types 10 answers, your program should calculate the percentage that are correct. 
	If the percentage is lower than 75%, display "Please ask your teacher for extra help.",
	then reset the program so another student can try it. If the percentage is 75% or higher, display
	"Congratulations, you are ready to go to the next level!", then reset the program so another
	student can try it.
*/

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<vector>

int computerAI3();

int CAI_MonitoringStudentPerformance() {

	double count{ 0 };

	for (int i = 0; i < 10; i++) { count += computerAI3(); }

	if ((100 * count / 10) >= 75) { std::cout << "Congratulations, you are ready to go to the next level!"; }
	else { std::cout << "Please ask your teacher for extra help."; }

	return 0;
}

int computerAI3() {

	std::srand(static_cast<unsigned int>(std::time(0)));

	int factor1{ 1 + std::rand() % 10 };
	int factor2{ 1 + std::rand() % 10 };
	int answer;

	std::vector<std::string> possitiveResp{ "Very good!\n", "Excellent!\n",
											"Nice work! \n", "Keep up the good work!\n" };

	std::vector<std::string> negativeResp{ "No. Please try again.\n", "Wrong. Try once more. \n",
											"Don't give up! \n", "No. Keep trying.\n" };

	int random{ std::rand() % 4 };

	std::cout << "How much is " << factor1
		<< " times " << factor2 << "? -->  ",
		std::cin >> answer;

	if ((factor1 * factor2) == answer) { 

		std::cout << possitiveResp.at(random) << std::endl; 
		return 1;
	}
	else {
		std::cout << negativeResp.at(random) << std::endl;
		return 0;
	}


	

}