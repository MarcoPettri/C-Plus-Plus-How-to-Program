// 4.19 Exercise: Find Two Largest Numbers

#include<iostream>
#include<algorithm>
#include<vector>

using std::cout; using std::cin; 
using std::sort; using std::greater;

int LargestNumbers() {

	std::vector<int> numbers(10, 0);

	for (int i = 0; i < 10; i++) {

		int number;
		cout << "Enter the number: ",
			cin >> number;

		numbers[i] = number;

	}

	sort(numbers.begin(), numbers.end(), greater<int>());

	cout << "\nThe two largest numbers are: " 
		<< numbers[0] << ", " << numbers[1];


	return 0;
}

