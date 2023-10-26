//Exercise 19.x:Copying a List in Reverse Order with Singly Linked Lists
/*

		Write a program that creates a singly linked list of 10 characters 
		and creates a second singly linked list containing a copy of the first
		list, but in reverse order.
*/

#include "List.hpp"
#include<iterator>
#include<vector>


int COPYING_A_LIST_IN_REVERSE_ORDER_WITH_SINGLY_LINKED_LISTS()
{

	List<char> list1{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
	List<char> list2;


	for (auto it{ list1.rbegin() }, end{ list1.rend() }; it != end; ++it) {
		char chr{ *it };
		list2.insertAtBack(chr);
	}

	list1.print();
	list2.print();



	
}