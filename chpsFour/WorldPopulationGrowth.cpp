// 4.38 Exercise: World Population Growth

#include<iostream>
#include<iomanip>
#include<locale>

using std::cout; using std::endl;
using std::setw; using std::locale;

int WorldPopulationGrowth() {
	
	int64_t currentPopulation{ 7'794'798'739 };
	double rate{ 1.05 };

	cout.imbue(locale(""));
	cout << "Years"
		<< setw(35) << "World Population Projection"
		<< setw(30) << "World Population Growth\n" 
		<< endl;
	for (unsigned int year{ 1 }; year <= 75; year++) {

		int64_t population = (currentPopulation * (pow(rate , year) /100)) + currentPopulation;

		cout << setw(3) << year
			<< setw(27) << population
			<< setw(33) << population - currentPopulation
			<< endl;

	}
	
	return 0;
}