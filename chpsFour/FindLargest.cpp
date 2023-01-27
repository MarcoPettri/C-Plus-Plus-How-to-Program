// 4.17 Find The Largest exercise 

#include <iostream>
#include <algorithm>
#include <vector>

using std::cout; using std::cin; using std::endl;
using std::max_element; 


int findLargest() {
	
	std::vector<int> numbers(10, 0);

	unsigned int counter{ 0 };

	while (counter < 10) {


		int sales;
		cout << "Enter the number of units sold: ",
			cin >> sales;

		cout << endl;

		numbers[counter] = sales;

		counter++;
	}
	
	cout << "The largest number of units sold is " 
		<< *max_element(numbers.begin(), numbers.end());

	return 0;
}