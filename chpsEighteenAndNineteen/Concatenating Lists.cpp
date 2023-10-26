// Exercise 19.x: Concatenating Lists
/*
		Write a program that concatenates two linked lists of characters. The
		program should include a function concatenate, which takes const references to both list objects
		as arguments and returns a new list which is a concatenation of the specified lists.

*/


#include<iostream>

#include "List.hpp"


List<char> concatenate(const List<char>&, const List<char>&);

int CONCATENATING_LISTS()
{
	List<char> firstList;
	List<char> secondList;

	firstList.insertAtBack('T');
	firstList.insertAtBack('h');
	firstList.insertAtBack('i');
	firstList.insertAtBack('s');	
	firstList.insertAtBack('i');	
	firstList.insertAtBack('s');	
	
	
	secondList.insertAtBack('a');
	secondList.insertAtBack('t');
	secondList.insertAtBack('e');
	secondList.insertAtBack('s');
	secondList.insertAtBack('t');

	concatenate(firstList, secondList).print();

	return 0;

}

List<char> concatenate(const List<char>& list1, const List<char>& list2)
{
	List<char> newList;

	if (list1.isEmpty() || list2.isEmpty()) {

		std::cout << (list1.isEmpty() ? "First " : "Second ") 
			<< "list is empty" << std::endl;
		
		return newList;

	}

	for (auto item{ list1.begin() }; item != list1.end(); ++item) {
		newList.insertAtBack(*item);

	}	
	for (auto item{ list2.begin() }; item != list2.end(); ++item) {
		newList.insertAtBack(*item);
	
	}
	
	return newList;
}