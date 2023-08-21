// Tool.cpp
/*
	Tool Class Definitions
*/

#include "Tool.h"
#include<cstddef>
#include<stdexcept>

Tool::Tool(int rcord_nmbr, const std::string& nme, int qntity, double cst)
{
	this->set_record_number(rcord_nmbr);
	this->set_name(nme);
	this->set_quantity(qntity);
	this->set_cost(cst);
}


void Tool::set_name(const std::string& rhs)
{
	std::size_t length{ rhs.size() };

	length = (length < 15 ? length : 14);

	rhs.copy(name, length);

	this->name[length] = '\0';
}

void Tool::set_record_number(int rhs)
{
	if (rhs < 0) {
		throw std::invalid_argument("Record Number must be positive");
	}

	this->record_nmbr = rhs;
}

void Tool::set_quantity(int rhs)
{
	if (rhs < 0) {
		throw std::invalid_argument("The Quantity must be a positive value");
	}

	this->quantity = rhs;
}

void Tool::set_cost(double rhs)
{
	if (rhs < 0) {
		throw std::invalid_argument("The Cost must be a positive value");
	}

	this->cost = rhs;
}



std::string Tool::get_name() const { return std::string(this->name); }

int			Tool::get_record_number() const { return this->record_nmbr; }

int			Tool::get_quantity() const { return this->quantity; }

double		Tool::get_cost() const { return this->cost; }
