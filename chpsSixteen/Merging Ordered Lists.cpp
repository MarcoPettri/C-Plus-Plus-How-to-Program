// Exercise 16.x: Merging Ordered Lists
/*

		Write a program that uses Standard Library algorithms to merge
		two ordered lists of strings into a single ordered list of strings,
		then displays the resulting list.
*/


#include<list>
#include<string>
#include<iostream>
#include<algorithm>
#include<iterator>

template <typename T> void printList(const std::list<T>&);

int MERGING_ORDERED_LISTS()
{
	std::list<std::string> list_one{ "red", "orange", "yellow", "green", "blue", "purple" };
	std::list<std::string> list_two{ "pink", "white", "grey", "brown", "black"};
	std::list<std::string> result;

	list_one.sort();
	list_two.sort();

	std::cout << "List 1:" << std::endl;
	printList(list_one);

	std::cout << "\nList 2:" << std::endl;
	printList(list_two);


	std::merge(list_one.cbegin(),  list_one.cend(), 
				list_two.cbegin(), list_two.cend(),
				std::back_inserter(result));

	std::cout << "\nMerged lists: " << std::endl;
	printList(result);

	

	return 0;
}

template<typename T>
void printList(const std::list<T>& rhs)
{
	if (rhs.empty()) {
		std::cout << "List is empty" << std::endl;
		return;
	}
	std::ostream_iterator<T> out{ std::cout, " " };
	std::copy(rhs.cbegin(), rhs.cend(), out);
	std::cout << std::endl;
}