// 6.43-6.44 Exercise: mystery
/*
	After you determine what the program of Exercise 6.43 does, modify the program to 
	function properly after removing the restriction that the second argument be nonnegative.

*/


#include <iostream>


int mystery(int, int); 

int Mystery() {
	std::cout << "Enter two integers:\n";
	int x{ 0 };
	int y{ 0 };
	std::cin >> x >> y;
	std::cout << "The result is " << mystery(x, y) << std::endl;

	return 0;
}


int mystery(int a, int b) {
	if (1 == b || -1 == b) { 

		return (b > 0 ? a : -a);
	}
	else { 
		b = (b > 0 ? b - 1 : b + 1 );
		return  mystery(a, b) + ( b > 0 ? a : -a);
	}
}