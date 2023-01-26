// 6.16 Random Numbers:
/*
	 Write statements that assign random integers to the variable $n$ in the  following ranges:

	 a) 0 <= n <= 3
	 b) 1  <=  n  <=  50
	 c) 2  <=  n  <=  44
	 d) 500  <=  n  <=  678
	 e) -2  <=  n  <=  2
	 f) -3  <=  n  <=  12
*/

#include<iostream>
#include<random>
#include<vector>
#include<ctime>


int RandomNumbers() {
	
	std::default_random_engine engine{ static_cast<unsigned int>(std::time(0)) };
	typedef std::uniform_int_distribution<int> RandomInt;

	RandomInt n1{ 0, 3 };
	RandomInt n2{ 1, 50 };
	RandomInt n3{ 2, 44 };
	RandomInt n4{ 500, 678 };
	RandomInt n5{ -2, 2 };
	RandomInt n6{ -3, 12 };

	std::vector<RandomInt*> randomNumbers{&n1, &n2, &n3, &n4, &n5, &n6};

	std::cout << "Random Numbers: ";

	for (auto numbers: randomNumbers ) { std::cout << (*numbers)(engine) << ", "; }

	return 0;
}