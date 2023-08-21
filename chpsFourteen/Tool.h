//Tool.h
/*

	Tool Class for exercise 14.11: Hardware Inventory
*/

#ifndef TOOL_H
#define TOOL_H

#include<string>

class Tool
{

public:
	Tool(int rcord_nmbr, const std::string& nme, 
		int qntity, double cst);
	Tool() = default;
	~Tool() = default;  

// Setters

	void set_name(const std::string&);
	void set_record_number(int);
	void set_quantity(int);
	void set_cost(double);

// Getters
	std::string get_name()			const;
	int			get_record_number() const;
	int			get_quantity()		const;
	double		get_cost()			const;


private:
	int		record_nmbr;
	char	name[15];
	int		quantity;
	double	cost;


};

#endif // !TOOL_H
