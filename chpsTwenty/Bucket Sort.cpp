// Exercise 20.x: Bucket Sort
/*
		A bucket sort begins with a one-dimensional array of positive integers to be
		sorted and a two-dimensional array of integers with rows index based from 0 to 9 and columns index based
		from 0 to n -1, where n is the number of values to be sorted. Each row of the two-dimensional
		array is referred to as a bucket. Write a class named BucketSort containing a function called sort
		that operates as follows:

				a) Place each value of the one-dimensional array into a row of the bucket array, based on
				the value's "ones" (rightmost) digit. For example, 97 is placed in row 7, 3 is placed in
				row 3 and 100 is placed in row 0. This procedure is called a distribution pass.

				b) Loop through the bucket array row by row, and copy the values back to the original
				array. This procedure is called a gathering pass. The new order of the preceding values
				in the one-dimensional array is 100, 3 and 97.

				c) Repeat this process for each subsequent digit position (tens, hundreds, thousands, etc.).

		On the second (tens digit) pass, 100 is placed in row 0, 3 is placed in row 0 (because 3 has no
		tens digit) and 97 is placed in row 9. After the gathering pass, the order of the values in the one-
		dimensional array is 100, 3 and 97. On the third (hundreds digit) pass, 100 is placed in row 1, 3 is
		placed in row 0 and 97 is placed in row 0 (after the 3). After this last gathering pass, the original
		array is in sorted order.
			Note that the two-dimensional array of buckets is 10 times the length of the integer array
		being sorted. This sorting technique provides better performance than a bubble sort, but requires
		much more memory—the bubble sort requires space for only one additional element of data. This
		comparison is an exampled of the space-time trade-off: The bucket sort uses more memory than the
		bubble sort, but performs better. This version of the bucket sort requires copying all the data back
		to the original array on each pass. Another possibility is to create a second two-dimensional bucket
		array and repeatedly swap the data between the two bucket arrays.

*/

#include "BucketSort.hpp"
#include<list>


std::ostream& operator<<(std::ostream& out, const std::list<int>& rhs) {

	std::cout << "[ ";
	for (const int& elem : rhs) {
		out << elem << (elem == rhs.back() ? " ]" : ", ");
	}
	return out;
}

int BUCKET_SORT() {

	std::list<int> list{ 407, 316, 658, 375, 430, 318, 942, 652, 409, 598 };
	BucketSort<10> array_bucket{ 407, 316, 658, 375, 430, 318, 942, 652, 409, 598 };
	
	std::cout << "\nList Template Class (STL):\n" << list << std::endl;
	std::cout << "\nBucket Template Class:\n" << array_bucket << std::endl;

	list.sort();
	array_bucket.sort();

	std::cout << "\nAfter sorting the containers" << std::endl;
	std::cout << list << std::endl;
	std::cout << array_bucket << std::endl;

	return 0;
}