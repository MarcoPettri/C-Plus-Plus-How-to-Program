// BucketSort.hpp
/*
	BucketSort Template Class
*/

#ifndef BucketSort_HPP
#define BucketSort_HPP

#include<iostream>
#include<array>
#include<initializer_list>
#include<vector>
#include<cstdint>

template<std::size_t size>
class BucketSort
{
	friend std::ostream& operator<<(std::ostream& out, const BucketSort& rhs) {

		out << "< ";
		for (const int& item : rhs.arr) {
			out << item << (item == rhs.arr.back() ? " >" : ", ");
		}

		return out;
	}

public:
	BucketSort(const std::array<int, size>& arg)
		: arr(arg) { }

	BucketSort(const std::initializer_list<int>& list) {

		auto it_list{ list.begin() };

		for (auto it_self{ arr.begin() }, end{arr.end()};
				it_self != end;  ++it_self, ++it_list) {

			*it_self = *it_list;
		}
	}


	~BucketSort() = default;

	void sort() {

		int  max{ maximum() };
		int  length_of_max{};

		while (max > 0) { max /= 10; ++length_of_max; }

		for (int exponent{ 1 }; exponent <= length_of_max; ++exponent) {

			std::array<std::vector<int>, 10> bucket;
			std::int64_t place_value{ power(10, exponent) };
			std::int64_t divisor{ place_value / 10 };

			for (const int& elem : arr) {

				std::size_t index{
					static_cast<std::size_t>(elem % place_value / divisor) 
				};

				bucket[index].push_back(elem); // Distribution Pass
			}

			// gathering pass //

			auto it{ arr.begin() };

			for (const auto& row : bucket) {
				for (const int& elem : row) {
					*it = elem;
					++it;
				}
			}
		}


	}

	int maximum() const {

		int max{ arr[0] };

		for (const int& item : arr) {
			if (item > max) {
				max = item;
			}
		}
		return max;
	}
	int minimum() const {
		int min{ arr[0] };
		
		for (const int& item : arr) {
			if (item < min) {
				min = item;
			}
		}
		return min;
	}

private:
	std::array<int, size> arr;

	std::int64_t power(int base, int exp)
	{
		if (not exp) { return 1; }
		else if (exp == 1) { return base; }

		std::int64_t result{ 1 };

		do {
			if (exp & 1) {
				result *= base;
			}
			base *= base;

		} while (exp >>= 1);


		return result;
	}
};

#endif // BucketSort
