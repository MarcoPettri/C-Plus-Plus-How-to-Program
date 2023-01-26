// 6.22 Exercise: Rectangle of Asterisks
/*	
	Write a function that displays at the left margin of the screen a solid
	rectangle of asterisks whose width and height are specified in integer parameters width and height.
	For example, if width is 10 and height is 3, the function displays the following:

				**********
				**********
				**********
*/ 

#include<string>
#include<iostream>

void rectangleOfAsterisks(int& width, int& height);

int Rectangle_Of_Asterisks() {

	int width, height;
	std::cout << "Enter the width: ",
		std::cin >> width;	
	std::cout << "Enter the height: ",
		std::cin >> height;

	rectangleOfAsterisks(width, height);

	return 0;
}

void rectangleOfAsterisks(int& width, int& height) {

	for (int i{ 0 }; i < height; i++) {
		std::cout << std::string(width, '*') << std::endl;
	}
}


