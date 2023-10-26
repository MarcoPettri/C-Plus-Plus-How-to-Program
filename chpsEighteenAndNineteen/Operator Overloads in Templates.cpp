// Exercise 18.x: Operator Overloads in Templates
/*
			Write a simple function template for predicate function
			isEqualTo that compares its two arguments of the same type with the equality operator (==) and
			returns true if they are equal and false otherwise. Use this function template in a program that
			calls isEqualTo only with a variety of fundamental types. Now write a separate version of the pro-
			gram that calls isEqualTo with a user-defined class type, but does not overload the equality operator.
			What happens when you attempt to run this program? Now overload the equality operator (with
			the operator function) operator==. Now what happens when you attempt to run this program?

*/

#include<iostream>
#include<vector>
#include<cstdlib>

// Function Template // 
template<typename T>
inline bool isEqual(T rhs, T lhs) { return rhs == lhs; }

//	Class with operator == overloaded
template<typename T>
class MyClass1
{
 friend std::ostream& operator<<(std::ostream& out, 
	 const MyClass1<T>& rhs) {

	 for (const T& elem : rhs.var) {
		 out << elem << " ";
	 }
	 return out;
 }

public:
	explicit MyClass1(std::size_t size)
		:var(size) { }

	~MyClass1() = default;

	bool operator==(const MyClass1<T>& rhs) const 
	{
		return var.size() == rhs.var.size();
	}

private:
	std::vector<T> var;
};

// Class without operator == overloaded
class MyClass2
{
public:
	explicit MyClass2(int j)
		: data{ j } { }

	~MyClass2() = default;

	int get() const { return data; }

private:
	int data;
};


int OPERATOR_OVERLOADS_IN_TEMPLATES()
{
	// test with fundamental types
	{
		std::cout << "Test With Fundamental Types:"  << std::boolalpha << std::endl;
		std::cout << "2 == 4: " << isEqual(2, 4) << std::endl;
		std::cout << "1/2  == 0.5: " << isEqual(1.f/2.f, 0.5f) << std::endl;
		std::cout << "true == (2 < 4): " << isEqual(true, (2 < 4)) << std::endl;
	}

	// Test with MyClass1
	{
		MyClass1<int> integers1 { 10 };
		MyClass1<int> integers2 { 5 };

		std::cout << "\nTest With MyClass1" << std::endl;
		
		std::cout << "Integers1: " << integers1 << std::endl;
		std::cout << "integers2: " << integers2 << std::endl;

		std::cout << "Integers1 == integers2: " << isEqual(integers1, integers2);

	}

	// Test with MyClass2
	{
		MyClass2 var1{ 3 };
		MyClass2 var2{ 3 };

		std::cout << "Test With MyClass2" << std::endl;
		
		std::cout << "var1: " << var1.get() << std::endl;
		std::cout << "var2: " << var2.get() << std::endl;

		std::cout << "var1 == var2: " << isEqual(var1, var2);

	}
	return 0;
}