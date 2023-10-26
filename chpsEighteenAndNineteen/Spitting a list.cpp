// Exercise 19.x: Spitting a list
/*
		Write a program that splits a linked list into two. The program should
		include a function split, which takes an integer indicating the splitting point (the node position
		from the list head). The split function should return a new list object consisting of the elements
		after the splitting point while leaving the original list with the remaining elements.

*/


#include "List.hpp"


template<typename T> List<T> split(List<T>&, int);

int SPITTING_A_LIST()
{

	List<int> list{ 
					1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
					11, 12, 13, 14, 15, 16, 17, 18, 19, 20 
	};

	list.print();

	List<int> list2{ split(list, 10) };

	list2.print();
	list.print();

	return 0;
}

template<typename T> 
List<T> split(List<T>& list, int nodePosition)
{
	List<T> newList;
	if (nodePosition >= list.size()) {
		std::cout << "Error: node position out of range";
		return newList;
	}
	
	
	int point{};
	for (auto it{ list.begin() }, end{ list.end() };
		it != end; ++it, ++point) {

		if (point >= nodePosition) {
			
			T elem{ *it };
			newList.insertAtBack(elem);

		}
	}
	point = 0;

	for (auto it{ list.begin() }, end{ list.end() }; 
		 it != end;
		++it, ++point) {
		
		if (point >= nodePosition) {

			list.removeFromFront(*it);
		}
	}

	return newList;


}