// Package2.cpp

/*
	Package2 class definitions

*/

#include"Package2.h"
#include<sstream>
#include<stdexcept>

Package2::Package2(const std::string& from_nme, const std::string& to_nme,
	const std::string& from_addr, const std::string& to_addr,
	const std::string& from_cty, const std::string& to_cty,
	const std::string& from_stat, const std::string& to_stat,
	const std::string& from_zip, const std::string& to_zip,
	double wght, double cst)
{

	if (wght < 0.0f || cst < 0.0f) {

		throw std::invalid_argument({ wght < 0.0f
										? "Weight must be positive."
										: "Cost must be positive." });
	}

	inf = {
		{from_nme , to_nme},
		{from_addr, to_addr},
		{from_cty , to_cty},
		{from_stat, to_stat},
		{from_zip , to_zip}
	};

	weight = wght;
	cost = cst;

}

void Package2::set_weight(double rhs)
{
	if (rhs < 0.0f) {
		throw std::invalid_argument("Weight must be positive.");
	}
	this->weight = rhs;
}

void Package2::set_cost(double rhs)
{
	if (rhs < 0.0f) {
		throw std::invalid_argument("Cost must be positive.");
	}
	this->cost = rhs;
}

double Package2::calculateCost() const
{
	return this->weight * this->cost;
}

std::string Package2::to_string() const
{
	std::ostringstream out;

	for (auto it{ inf.cbegin() }; it != inf.cend(); ++it) {
		out << "From: " << it->from
			<< "; To: " << it->to << "\n";
	}

	out << "Weight: " << this->weight
		<< "\nCost: " << this->cost;

	return out.str();
}

std::string& Package2::get_from_nme()
{
	return inf.begin()->from;
}

std::string& Package2::get_to_nme()
{
	return inf.begin()->to;
}

std::string& Package2::get_from_addr()
{
	return this->advance(1, true);
}

std::string& Package2::get_to_addr()
{

	return this->advance(1, false);
}

std::string& Package2::get_from_cty()
{

	return this->advance(2, true);
}

std::string& Package2::get_to_cty()
{

	return this->advance(2, false);
}

std::string& Package2::get_from_stat()
{
	return this->advance(3, true);
}

std::string& Package2::get_to_stat()
{
	return this->advance(3, false);
}

std::string& Package2::get_from_zip()
{
	return this->advance(4, true);
}

std::string& Package2::get_to_zip()
{
	return this->advance(4, false);
}

/*
	Step: number of elements 'it' should be advanced
	key : True return 'from'; False return 'to'
*/
std::string& Package2::advance(int step, bool key)
{
	auto it{ inf.begin() };
	while (step > 0) { ++it, --step; }

	if (key) { return it->from; }
	else { return it->to; }
}
