// Exercise 20.x: Quicksort
/*

		The recursive sorting technique called quicksort uses the following basic algorithm for a one-dimensional array of values:

					a) Partitioning Step: Take the first element of the unsorted array and determine its final location in the sorted array 
						(i.e., all values to the left of the element in the array are less than the element, and all values to the right of the element in 
						the array are greater than the element). We now have one element in its proper location and two unsorted sub-arrays.

					b) Recursive Step: Perform Step 1 on each unsorted sub-array. Each time Step 1 is performed on a sub-array, 
						another element is placed in its final location of the sorted array, and two unsorted sub-arrays are created.
						When a sub-array consists of one element, that element is in its final location
						(because a one-element array is already sorted).
		
		Write recursive function quick_sort to sort a one-dimensional integer array
*/

#include<iostream>
#include<array>
#include<algorithm>
#include<cstddef>

template<std::size_t size> 
void quick_sort(std::array<int, size>&, int, int);

template<std::size_t size> 
int	 partition(std::array<int, size>&, int, int);

template<std::size_t size>
std::ostream& operator<<(std::ostream& out, const std::array<int, size>& rhs) {
	
	out << "{";
	for (const auto& elem : rhs) {
		out << elem 
			<< (elem == rhs.back() ? "}" : ", ");
	}
	return out;
}

int QUICKSORT() {

	const int SIZE{ 10 };

	std::array<int, SIZE> arr{ 46, 55, 69,  1, 87, 72, 50,  9, 58, 94 };

	std::cout << arr << std::endl;

	quick_sort(arr, 0, SIZE -1);

	std::cout << arr << std::endl;
	
	return 0;
}

template<std::size_t size>
void quick_sort(std::array<int, size>& arr, int low , int high) {

	if (low < high) {
		int pi{ partition(arr, low, high) };

		quick_sort(arr, low, pi - 1);
		quick_sort(arr,  pi +1, high);
	}
}


template<std::size_t size>
int	partition(std::array<int, size>& arr, int low, int high) {

	int pivot{ arr[high] };
	int index{ low };

	for (int j{ low }; j < high; ++j) {

		if (arr[j] <= pivot) {

			std::swap(arr[index], arr[j]);
			++index;
		}
	}

	std::swap(arr[index], arr[high]);

	return index;
}