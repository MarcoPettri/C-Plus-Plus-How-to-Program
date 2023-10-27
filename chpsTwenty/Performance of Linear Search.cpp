// Exercise 20.x: Performance of Linear Search
/*
		 In this exercise, you are going to experiment with the linear
		search algorithm to study its performance. Modify Fig. 20.2 to make the program generate many
		random integers and store them in an vector by accepting two command-line parameters n and i.
		These specify the number of random integers to generate and the index of the value to search for
		in the vector. Compile and run the program with different values of n and i and note the time
		taken to search the value at index i. To appreciate the effect of n on the algorithm, use relatively
		large values of n.

*/


#include<iostream>
#include<vector>
#include<cstddef>
#include<random>
#include<ctime>

          
template <typename T>
int linearSearch(const std::vector<T>& items,  T key) {

	for (std::size_t i{ 0 }; i < items.size(); ++i) {

		if (key == items[i]) {
			return i;
		}
	}
	
	return -1;                            
}


int PERFORMANCE_OF_LINEAR_SEARCH(int n, int i) {

	
	std::vector<int> vect(n);

	std::default_random_engine engine{
		static_cast<unsigned int>(std::time(nullptr)) 
	};

	std::uniform_int_distribution<unsigned int> randomInt{ 0, 10'000'000 };


	for (int& item : vect) {
		item = randomInt(engine);
		std::cout << item << " ";
	}

	int element{ linearSearch(vect, i)};

	// display results
	if (element != -1) {
		std::cout << "Found value in element " << element << std::endl;
	}
	else {
		std::cout << "Value not found" << std::endl;
	}

	return 0;
}