// Exercise 13.13: Dealing with extra input characters
/*
			When reading user input from the standard input using
		cin, the user can provide more data than is needed. For example, if you ask a user to enter their first
		name, they could type their first name followed by extra characters, such as "James foo". In such
		cases, cin will read the string "James" and leave the rest, foo, in the input stream to be read by the
		next input statement, which is probably not what you want. Write a program that asks a user for
		their first name, last name, and year of birth, one after another in this order, and try to supply extra
		characters after you type the last name. Can you explain what is going on? Correct this problem by
		discarding all characters up to the end of the line after you read the first name and last name.

*/


#include<iostream>
#include<string>
#include<limits>

int Dealing_With_Extra_Input_Characters()
{

	std::string frst_nme, lst_nme, yr_brth;
	
	std::cout << "First Name: ",
		std::cin >> frst_nme;

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Last Name: ",
		std::cin >> lst_nme;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Year of Birth: ",
		std::cin >> yr_brth;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Name: " << frst_nme << " " << lst_nme
		<< "\nYear of Birth: " << yr_brth << std::endl;



	return 0;
}