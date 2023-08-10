// Complex.cpp
/*

	Complex class definitions
*/

#include "Complex.h"
#include <regex>



std::istream& operator>>(std::istream& input, Complex& rhs)
{
	// Match Complex numbers in format: Real + IMG or Real + nImag, where n is a integer number

	std::regex PATTERN{ "(?:\\-|\\+)|(?:\\d+i|i)|(?:(\\-\\d+|\\d+))" };
	std::smatch match;
	std::string str;

	std::getline(input, str, '\n');

	auto begin{ std::sregex_iterator(str.begin(), str.end(), PATTERN )};
	auto end{ std::sregex_iterator() };

	char sign{ '+' };


	if (begin == end) { 
		input.clear(std::ios::failbit); 
		return input;
	}

	for (std::sregex_iterator term = begin; term != end; ++term) {

		if (term->str() == "-" || term->str() == "+") {

			if (sign != '+') 
			{ sign = *term->str().data(); }

			else if (sign != *term->str().data() && sign != '-') 
			{ sign = '-'; }
		}
		else if (std::regex_match(term->str(), std::regex("\\d+"))) {
			if (rhs.real == 0 && term->str() != "0") {

				rhs.real = std::stoi(sign + term->str());
				sign = '+';
			}
			else {
				input.clear(std::ios::failbit);
				break;
			}
		}
		else if (std::regex_match(term->str(), std::regex("\\d+i|i"))) {
			
			if (term->str() != "i" && term->str()[0] != '0') {
			
				//is subtracted from 1 to remove "i" from the string 
				int length{ static_cast<int>(term->length()) -1};

				rhs.imaginary = std::stoi(sign + term->str().substr(0, length));
				sign = '+';
			}
			else if (sign == '-') {
				rhs.imaginary *= -1;
			}
			else {
				input.clear(std::ios::failbit);
				break;
			}
			
		}
		else {
			input.clear(std::ios::failbit);
			break;
		}
	}

	return input;
}
	
	



std::ostream& operator<<(std::ostream& out, const Complex& rhs)
{
	if (std::cin.fail()) {
		
		out << "Invalid Complex Number";
		return out;
	}

	if (rhs.real) { out << rhs.real << " "; }
	
	if (rhs.imaginary > 0) {
		{
			rhs.imaginary != 1 ?
				out << "+ " << rhs.imaginary << "i" :
				out << "+ i";
		}	
	}
	else {
		
		{
			rhs.imaginary != -1 ?
				out << rhs.imaginary << "i" :
				out << "-i";
		}
	}


	return out;
}
