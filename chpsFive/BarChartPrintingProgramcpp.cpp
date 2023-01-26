// 5.13 Exercise: Bar-Chart Printing Program
/*
	One interesting application of computers is to display graphs
	and bar charts. Write an application that reads five numbers between 1 and 9. For each number that’s
	read, your program should display a double row of the same number repeated as many times as the
	number read. For example, if your program reads the number 7, it should display 7777777 followed
	by 7777777 on the next line. Display the bars of numbers after you read all five numbers.
*/
#include<iostream>
#include<string>
#include<algorithm>

int BarChartPrinting() {

	std::string numbers;

	std::cout << "Enter five number between 1 and 9, separated by commas: ",
		std::getline(std::cin, numbers);

	numbers.erase(std::remove(numbers.begin(), numbers.end(), ','), numbers.end());

	for (auto number : numbers) {

		for (unsigned i{ 0 }; i < 2; i++) {

			int times = static_cast<int>(number - 48);
			std::cout << std::string(times, number) << std::endl;
		}
	}
	return  0;
}

