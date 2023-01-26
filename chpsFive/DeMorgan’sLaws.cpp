// 4.22 Exercise: De Morgan’s Laws

/*
		In this chapter, we discussed the logical operators &&, || and !. 
		De Morgan’s laws can sometimes make it more convenient for us to express a logical expression. 
		These laws state that the expression !(condition1 && condition2) is logically equivalent to the expression
		(!condition1 || !condition2). Also, the expression !(condition1 || condition2) is logically equivalent
		to the expression (!condition1 && !condition2). Use De Morgan’s laws to write equivalent expressions
		for each of the following, then write an application to show that both the original expression and
		the new expression in each case produce the same value:
		a) !((x <= 6) && (y % 2==1)) (a)
		b) !((a < 4) || (b >= 6)) (c)
		c) !(x < 3) && !(y >= 2)  (d)
		d) !(a == b) || !(b != 2) (b)
*/

#include<iostream>
#include<iomanip>


int DeMorgansLaws() {

	std::cout << std::boolalpha;

	unsigned int x{ 4 }, y{ 4 }, a{ 11 }, b{ 7 };


	bool expressionOne{ !((x <= 6) && (y % 2 == 1)) };
	bool expressionTwo{ !((a < 4) || (b >= 6)) };
	bool expressionThree{ !(x < 3) && !(y >= 2) };
	bool expressionFour{ !(a == b) || !(b != 2) };

	std::cout << "\nExpressions:" << std::setw(42) << "Values\n"
		<< "\na) !((x <= 6) && (y % 2 == 1)) " << std::setw(20) << "x = " << x
		<< "\nb) !((a < 4) || (b >= 6)) " << std::setw(25) << "y = " << y
		<< "\nc) !(x < 3) && !(y >= 2) " << std::setw(26) << "a = " << a
		<< "\nd) !(a == b) || !(b != 2) " << std::setw(25) << "b = " << b
		<< std::endl;


	std::cout << "\nThe expression (a) is equivalent to expression (d) \n\n" 
		<< "Expression (a): " << expressionOne
		<< "\nExpression (d): " << expressionFour
		<< std::endl;	


	std::cout << "\nThe expression (b) is equivalent to Expression (c) \n\n" 
		<< "Expression (b): " << expressionTwo
		<< "\nExpression (c): " << expressionThree;

	return 0;
}