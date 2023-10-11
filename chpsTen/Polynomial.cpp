//Polynomial.cpp
/*

	Polynomial class Member-Function Definitions.
*/

#include"Polynomial.h"
#include<regex>
#include<locale>
#include<stdexcept>


// pattern for matching monomials and constants
const std::regex PATTERN{ "([+-]?(?:\\d+\\.\\d+|\\d+)?)((?:x\\^\\d+|x)?)" };

// Default Constructor //
Polynomial::Polynomial(const std::string& arg)
{

	const std::regex PATTERN(R"x([^x\s\d\^\.\+-])x"); // Gets invalid characters in the polynomial
	const std::regex PATTERN2(R"x(\S+)x"); // Gets any character that isn't a whitespace character

	// Gets Monomials
	const std::regex PATTERN3{
		"(?:(?:\\d+\\.\\d+x\\^\\d+|\\d+x\\^\\d+|x\\^\\d+)" // Gets the term in the form: a.bx^n or ax^n or x^n (if exist)
		"|(?:\\d+\\.\\d+x|\\d+x|x)" // Gets the lineal term in the form: a.bx or ax or x (if exist)
		"|(?:\\d+\\.\\d+|\\d+))" // Gets the constant term in the form: a.b or a (if exist)
	};



	//Checks if the polynomial contains any invalid characters or contains no spaces between the monomials
	if (std::regex_search(arg.begin(), arg.end(), PATTERN)) {

		throw std::invalid_argument("Invalid Polynomial: " + arg);
	}
	else if (not std::regex_search(arg.begin(), arg.end(), std::regex("\\s+"))) {
		throw std::invalid_argument("No spaces between the monomials: " + arg);
	}

	// splits the polynomial into signs and monomials
	auto begin{ std::sregex_iterator(arg.begin(), arg.end(), PATTERN2) };
	auto end{ std::sregex_iterator() };

	char sign = '\0';

	for (std::sregex_iterator monomial = begin; monomial != end; ++monomial) {

		if (std::regex_search(monomial->str(), PATTERN3)) {

			//If in the previous interaction it was a sign, it is concatenated with the term
			if (sign) {
				// If the monomial has 1 as a coefficient (e.g. x or x^n), 
				if (monomial->str().front() == 'x') {

					//then "1" is added to the monomial(e.g. 1x, -1x or -1x ^ n)
					poly.push_back(sign + ("1" + monomial->str()));
				}
				// else If the input was "+ -x" or " - -4x^3" etc.; then the signs multiply
				else if (monomial->str().front() == '+' || monomial->str().front() == '-') {

					std::string term{ monomial->str() };
					term.erase(0, 1);
					{
						sign == monomial->str().front() ?
							term.insert(0, "+") :
							term.insert(0, "-");
					}
					//If the monomial has 1 as a coefficient "1" is added
					if (term[1] == 'x') { term.insert(1, "1"); }

					poly.push_back(term);

				}
				// otherwise, the sign and monomial are concatenated(e.g +33, -3.44x^3)
				else { poly.push_back(sign + monomial->str()); }

				sign = '\0'; //The signal is set to null again
			}
			else {
				//If the monomial has 1 as a coefficient(e.g. x or -x^2, +x^n),
				if (monomial->str()[1] == 'x' &&
					(monomial->str().front() == '-' || monomial->str().front() == '+')) {

					//then "1" is added to the monomial.
					std::string term{ monomial->str() };
					term.insert(1, "1");
					poly.push_back(term);

				}
				// monomial = 33x, +94, -89.23x^4, etc
				else if (monomial->length() > 1) {
					poly.push_back(monomial->str());
				}

				else {
					throw std::invalid_argument("Invalid term: " + monomial->str() + '\n');
				}
			}

		}
		else if (monomial->str() == "-" || monomial->str() == "+") {
			sign = *monomial->str().data();

		}
		else {
			throw std::invalid_argument("Invalid character: " + monomial->str() + '\n');
		}

	}

	this->simplify();
	this->simplify();


}

Polynomial::Polynomial(const std::vector<std::string>& arg)
{
	for (const std::string& term : arg) {

		std::smatch match;
		if (std::regex_search(term, match, PATTERN)
			&& term != "-" && term != "+") {

			if (not match[2].str().empty()
				&& match[2].str().front() == 'x') {

				if (match[1].str().empty()) {
					this->poly.push_back("1" + term);
				}
				else if (match[1].str() == "-" || match[1].str() == "+") {
					this->poly.push_back(match[1].str() + "1" + match[2].str());
				}
				else {
					this->poly.push_back(term);
				}
			}
			else { this->poly.push_back(term); }
		}
		else {
			throw std::invalid_argument("Invalid term: " + term);
		}
	}

	this->simplify();
	this->simplify();

}


// Copy Constructor //
Polynomial::Polynomial(const Polynomial& rhs)
{
	this->poly = rhs.poly;

}

// Assignment Operators // 

const Polynomial& Polynomial::operator=(const Polynomial& rhs)
{
	this->poly = rhs.poly;

	return *this;
}


const Polynomial& Polynomial::operator+=(const Polynomial& rhs)
{

	this->poly = (*this + rhs).poly;

	return *this;
}

const Polynomial& Polynomial::operator-=(const Polynomial& rhs)
{

	this->poly = (*this - rhs).poly;

	return *this;
}


const Polynomial& Polynomial::operator*=(const Polynomial& rhs)
{
	this->poly = (*this * rhs).poly;

	return *this;
}


const Polynomial& Polynomial::operator*=(double rhs)
{
	std::smatch match;


	if (rhs) {
		for (std::string& terms : this->poly) {

			std::regex_search(terms, match, PATTERN);

			double new_coeff{ std::stod(match[1].str()) * rhs };

			terms = std::to_string(new_coeff) + match[2].str();

		}
	}
	else {
		this->poly.clear();
		this->poly.push_back("0");
	}

	return *this;
}


// Arithmetic Operators //


Polynomial Polynomial::operator+(const Polynomial& rhs) const
{

	std::vector<std::string> result;

	for (const std::string& terms_rhs : rhs.poly) {

		std::smatch match_rhs;
		bool not_matchs{ true };

		std::regex_search(terms_rhs, match_rhs, PATTERN);

		for (const std::string& terms_self : this->poly) {

			std::smatch match_self;
			std::regex_search(terms_self, match_self, PATTERN);
			// Only if exponents are equal or both are constant, addition is performed 
			if (match_rhs[2] == match_self[2]) {

				double coeff_rhs{ std::stod(match_rhs[1].str()) };
				double coeff_self{ std::stod(match_self[1].str()) };
				double new_coeff{ coeff_self + coeff_rhs };

				if (new_coeff) {

					result.push_back(std::to_string(new_coeff)
						+ match_self[2].str());
				}

				not_matchs = false;
				break;
			}

		}
		if (not_matchs) { result.push_back(match_rhs.str()); }

	}
	if (result.empty()) { result.push_back("0"); }

	return Polynomial(result);
}

Polynomial Polynomial::operator-(const Polynomial& rhs) const
{

	std::vector<std::string> result;

	for (const std::string& terms_rhs : rhs.poly) {

		std::smatch match_rhs;
		bool not_matchs{ true };
		std::regex_search(terms_rhs, match_rhs, PATTERN);

		for (const std::string& terms_self : this->poly) {

			std::smatch match_self;
			std::regex_search(terms_self, match_self, PATTERN);
			// Only if exponents are equal or both are constant, subtraction is performed 
			if (match_rhs[2] == match_self[2]) {

				double coeff_rhs{ std::stod(match_rhs[1].str()) };
				double coeff_self{ std::stod(match_self[1].str()) };
				double new_coeff{ coeff_self - coeff_rhs };

				if (new_coeff) {
					result.push_back(std::to_string(new_coeff)
						+ match_self[2].str());
				}

				not_matchs = false;
				break;
			}

		}
		if (not_matchs) {
			// if neither exponent is equal or there are no constants in both polynomials,
			// multiply the right-hand term (rhs) by -1 
			// e.g. (4x^3 + 3x) - (x^3 -x^2 -2x + 22) = 3x^3 + x^2 + 5x -22
			double new_ceef{ std::stod(match_rhs[1].str()) * -1 };
			result.push_back(std::to_string(new_ceef) + match_rhs[2].str());
		}

	}
	if (result.empty()) { result.push_back("0"); }

	return Polynomial(result);
}


Polynomial Polynomial::operator*(const Polynomial& rhs) const
{
	std::vector<std::string> result;

	if (rhs.poly.front() != "0") {

		for (const std::string& terms_rhs : rhs.poly) {

			std::smatch match_rhs;

			std::regex_search(terms_rhs, match_rhs, PATTERN);

			for (const std::string& terms_self : this->poly) {

				std::smatch match_self;
				std::regex_search(terms_self, match_self, PATTERN);

				double coeff_self{ std::stod(match_self[1].str()) };
				double coeff_rhs{ std::stod(match_rhs[1].str()) };
				double new_coeff{ coeff_self * coeff_rhs };

				std::string var_exp_self{ match_self[2].str() };
				std::string var_exp_rhs{ match_rhs[2].str() };

				if (var_exp_self.empty() || var_exp_rhs.empty()) {

					if (var_exp_self.empty() &&
						not var_exp_rhs.empty()) {

						var_exp_self.append(var_exp_rhs);
					}
				}
				else {
					std::smatch exp_self;
					std::smatch exp_rhs;
					int new_exp;

					std::regex_search(var_exp_self, exp_self, std::regex("x\\^(\\d+)"));
					std::regex_search(var_exp_rhs, exp_rhs, std::regex("x\\^(\\d+)"));

					// var_exp_self = x^n and var_exp_rhs = x^n, so x^(n + n)
					if (not exp_self[1].str().empty() &&
						not exp_rhs[1].str().empty()) {

						new_exp = std::stoi(exp_self[1]) + std::stoi(exp_rhs[1]);
					}
					//var_exp_self = x and var_exp_rhs = x^n, so x * x^n = x^(n +1)
					else if (exp_self[1].str().empty() && not exp_rhs[1].str().empty()) {

						new_exp = std::stoi(exp_rhs[1]) + 1;
					}
					// var_exp_rhs = x and var_exp_self = x^n, so x * x^n = x^(n +1)
					else if (exp_rhs[1].str().empty() && not exp_self[1].str().empty()) {

						new_exp = std::stoi(exp_self[1]) + 1;
					}
					else { // var_exp_self = var_exp_rhs (i.e. x * x = x^2)
						new_exp = 2;
					}

					var_exp_self.clear();
					var_exp_self = "x^" + std::to_string(new_exp);
				}

				if (new_coeff) {
					result.push_back(std::to_string(new_coeff)
						+ var_exp_self);
				}
			}

		}
	}
	else { return rhs; }

	return Polynomial(result);
}


Polynomial Polynomial::operator*(double rhs) const
{
	std::smatch match;
	std::vector<std::string> result{};

	if (rhs) {
		for (const std::string& terms : this->poly) {

			std::regex_search(terms, match, PATTERN);

			double new_coeff{ std::stod(match[1].str()) * rhs };

			result.push_back(std::to_string(new_coeff)
				+ match[2].str());
		}
	}
	else { result.push_back("0"); }

	return Polynomial(result);
}

// Utility Functions //

void Polynomial::simplify()
{
	for (auto it{ poly.begin() }; it != poly.end(); ++it) {

		std::smatch term;

		std::regex_search(*it, term, PATTERN);

		for (auto it2{ it + 1 }; it2 != poly.end();) {

			std::smatch next_term;
			std::regex_search(*it2, next_term, PATTERN);

			if (term[2].str() == next_term[2].str()) {

				double coeff_lhs{ std::stod(term[1].str()) };
				double coeff_rhs{ std::stod(next_term[1].str()) };

				*it = std::to_string(coeff_lhs + coeff_rhs) + term[2].str();
				poly.erase(it2);

				it2 = it + 1;
			}
			else { ++it2; }
		}
	}

	this->sort_poly();

}

void Polynomial::sort_poly()
{
	for (auto it{ poly.begin() }; it != poly.end(); ++it) {

		std::smatch term;

		std::regex_search(*it, term, PATTERN);

		if (not term[2].str().empty() && term[2].str() != "x") {

			for (auto it2{ it + 1 }; it2 != poly.end();) {

				const  std::regex PATTERN2{ "\\S\\^(\\d+)" };
				std::smatch exp_next_term;
				std::regex_search(*it2, exp_next_term, PATTERN2);

				if (not exp_next_term[1].str().empty()) {

					std::smatch exp_term;
					std::regex_search(*it, exp_term, PATTERN2);

					int lhs{ std::stoi(exp_term[1].str()) };
					int rhs{ std::stoi(exp_next_term[1].str()) };

					if (lhs < rhs) {

						std::string temp{ *it };
						*it = *it2;
						*it2 = temp;
						it2 = it + 1;
					}
					else { ++it2; }
				}
				else { ++it2; }
			}

		}
		else {
			if (std::regex_match(poly.back(), std::regex("[+-]?(\\d+\\.\\d+|\\d+)"))
				&& term[2].str() == "x") {

				if (*(poly.rbegin() + 1) != term.str()) {

					std::string temp{ *(poly.rbegin() + 1) };
					*(poly.rbegin() + 1) = term.str();
					*it = temp;
				}
			}
			else if (poly.back() != term.str()) {

				std::string temp{ poly.back() };
				poly.back() = *it;
				*it = temp;
			}
		}

	}
}


// insertion  operators  //
std::ostream& operator<<(std::ostream& out, const Polynomial& rhs)
{
	out.imbue(std::locale(""));

	for (const std::string& monomial : rhs.poly) {

		std::smatch term;

		std::regex_search(monomial, term, PATTERN);
		double coeff{ std::stod(term[1]) };


		if (monomial == rhs.poly.front()) {
			out << coeff << term[2];
		}
		else if (coeff < 0) {
			{
				coeff == -1 && not term[2].str().empty() ?
					out << " -" << term[2] :
					out << " " << coeff << term[2];
			}
		}
		else {
			{
				coeff == 1 && not term[2].str().empty() ?
					out << " + " << term[2] :
					out << " + " << coeff << term[2];
			}
		}
	}

	return out;
}