// Exercise 15.: Palindromes

/*
		Write a function template palindrome that takes a vector parameter and returns
		true or false according to whether the vector does or does not read the same forward as backward
		(e.g., a vector containing 1, 2, 3, 2, 1 is a palindrome, but a vector containing 1, 2, 3, 4 is
		not).

*/

#include<iostream>
#include<vector>

template<typename T>
bool isPalindrome(const std::vector<T>& vect)
{

	auto begin{ vect.cbegin() };
	auto rbegin(vect.crbegin());

	for (; begin != vect.cend() && rbegin != vect.crend();
			++begin, rbegin++) {

		if (*begin != *rbegin) { return false; }


	}

	return true;

}

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& rhs)
{
	for (auto elem : rhs) {
		out << elem << " ";
	}
	return out;
}

int PALINDROMES()
{

	
	std::vector<int>  test{ 1, 2, 3, 2, 1 };
	std::vector<char> test2{ 'r', 'o', 't', 'a', 't', 'o', 'r' };
	std::vector<int>  test3{ 1, 2, 3, 4, 5, 6 };


	std::cout << test  <<  (isPalindrome(test)  ? ": is a" : ": is not a") << " palindrome\n" << std::endl;
	std::cout << test2 <<  (isPalindrome(test2) ? ": is a" : ": is not a") << " palindrome\n" << std::endl;
	std::cout << test3 <<  (isPalindrome(test3) ? ": is a" : ": is not a") << " palindrome" << std::endl;

	return 0;
}