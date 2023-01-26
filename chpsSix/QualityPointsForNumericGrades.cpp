//6.32 Exercise: Quality Points for Numeric Grades
/*
	Write a function qualityPoints that inputs a student’s average 
	and returns 4 if a student’s average is 90–100, 3 if the average is 80–89, 
	2 if the average is 70–79, 1 if the average is 60–69 and 0 if the average is lower than 60.
*/

#include<iostream>

int qualityPoints(int avg);

int QualityPoints() {

	int average;
	std::cout << "Enter the Average: ",
		std::cin >> average;

	std::cout << average << " = " << qualityPoints(average);

	return 0;
}


int qualityPoints(int avg) {
	
	if (avg >= 90) { return 4; }
	else if (avg >= 80) { return 3; }
	else if (avg >= 70) { return 2; }
	else if (avg >= 60) { return 2; }
	else { return 0; }

}