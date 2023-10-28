// 21.x: string Concatenation
/*

	Write a program that separately inputs a first name and a last name
	and concatenates the two into a new string. Show two techniques for accomplishing this task
*/

#include<iostream>
#include<string>

int STRING_CONCATENATION()
{
	std::string firstName;
	std::string lastName;
	std::string name;
	std::string name2;

	std::cout << "First name: ",
		std::cin >> firstName;

	std::cout << "Last name: ",
		std::cin >> lastName;

	
	name.append(firstName + " " + lastName);
	name += '\n';

	name2.assign(firstName + " " + lastName);

	std::cout << name << name2 << std::endl;

	return 0;
}