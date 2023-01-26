// 6.23 Exercise: Rectangle of Any Character
/*
	Modify the function created in Exercise 6.22 to form 
	the rectangle out of whatever character is contained in character parameter fillCharacter. 
	Thus, if width is 6, height is 2 and fillCharacter is %, then this function should print the following:

				% % % % % %
				% % % % % %
*/


#include<string>
#include<iostream>

void rectangleOfAnyCharacter(char& fillCharacter, int& width, int& height);

int Rectangle_0f_Any_Character() {

	int width, height;
	char character;
	std::cout << "Enter the character: ",
		std::cin >> character;
	std::cout << "Enter the width: ",
		std::cin >> width;
	std::cout << "Enter the height: ",
		std::cin >> height;

	rectangleOfAnyCharacter(character, width, height);

	return 0;
}

void rectangleOfAnyCharacter(char& fillCharacter, int& width, int& height) {

	for (int i{ 0 }; i < height; i++) {
		std::cout << std::string(width, fillCharacter) << std::endl;
	}
}