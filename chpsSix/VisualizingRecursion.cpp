// 6.40 Exercise: Visualizing Recursion

/*
	It's interesting to watch recursion "in action." Modify the factorial
	function of Fig. 6.25 to print its local variable and recursive call parameter. For each recursive call,
	display the outputs on a separate line and add a level of indentation. Do your utmost to make the
	outputs clear, interesting and meaningful. Your goal here is to design and implement an output for-
	mat that helps a person understand recursion better. You may want to add such display capabilities
	to the many other recursion examples and exercises throughout the text.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <locale>


unsigned long long factorial(unsigned long long); 

int VisualizingRecursion() {
	
	int number{ 22 };
	std::cout.imbue(std::locale(""));
	std::cout << std::setw(2) << number << "! = " << factorial(number)
			<< std::endl;

	return 0;
	
}


unsigned long long factorial(unsigned long long number) {
	
	static unsigned long long tab = 0 ;


	if (number <= 1) {    

		std::cout << std::setw(tab +4)
			<< " " << number << std::endl;
		return 1;
	}
	else { 
		tab += 5 ;
		std::cout << std::setw(tab)
			<< number
			<< " * " 
			<< number - 1 << "! "
			<< std::endl;

		return number * factorial(number - 1);
		
	}
}