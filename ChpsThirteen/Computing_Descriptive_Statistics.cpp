//Exercise 13.17: Computing descriptive statistics for a data set
/*
		Write a program that reads a sequence of numbers from the user into a vector 
		and then calculates the mean, median, standard deviation, minimum, and maximum of the numbers.
		Consult a statistics book for formulas for mean, mode and standard deviation. 
		The program should display the numbers in two digits of precision.

*/


#include<iostream>
#include<vector>


double mean(const	std::vector<double>&);
double median(const std::vector<double>&);
double standard_deviation(const	std::vector<double>&);
double min(const	std::vector<double>&);
double max(const	std::vector<double>&);
double sqrt(double);


int Computing_Descriptive_Statistics()
{
	std::vector<double> data;

	double number;

	std::cout << "Enter the numbers separated by spaces (EOF to exit): ";

	// input -> 9 2 5 4 12 7 8 11 9 3 7 4 12 5 4 10 9 6 9 4 ^Z //
	while (std::cin >> number) {
		data.push_back(number);

	}

	std::cout.precision(2);

	std::cout << std::fixed
		<< "Mean: " << mean(data) << '\n'
		<< "Median: " << median(data) << '\n'
		<< "Standard Deviation: " << standard_deviation(data) << '\n'
		<< "Max: " << max(data) << '\n'
		<< "Min: " << min(data) << std::endl;

		return 0;
}

double mean(const std::vector<double>& rhs)
{
	double sum{ 0 };
	for (const double& elem : rhs) { sum += elem; }

	return sum / rhs.size();
}


double median(const std::vector<double>& rhs)
{

	if (rhs.size() % 2 == 0) {
		int first_middle{ static_cast<int>(rhs.size()) / 2 };
		int second_middle{ static_cast<int>(rhs.size()) / 2 - 1 };

		return (rhs[first_middle] + rhs[second_middle]) / 2;
	}

	return rhs[rhs.size() / 2];
}

double standard_deviation(const std::vector<double>& rhs)
{
	double mean_{ mean(rhs) };
	double sum { 0 };

	for (double elem : rhs) { 
		elem -= mean_; 
		elem *= elem;
		sum  += elem;
	}

	double varaince{ sum / rhs.size() };
	
	return std::sqrt(varaince);

}
double min(const std::vector<double>& rhs)
{
	double minimum{ rhs[0] };

	for (const double& elem : rhs) {

		if (elem < minimum) {
			minimum = elem;
		}
	}

	return minimum;
}
double max(const std::vector<double>& rhs) 
{
	double maximum{ rhs[0] };

	for (const double& elem : rhs) {

		if (elem > maximum) {
			maximum = elem;
		}
	}

	return maximum;

}

double sqrt(double rhs)
{
	const double precision = 0.000001;
	double		 increment = 1.0;
	double		 root	   = 0.0;

	while (increment > precision) {
		
		if (root * root > rhs) {
			root -= increment;
			increment *= 0.1;
		}
		else {
			root += increment;
		}
	}
	return root;

}