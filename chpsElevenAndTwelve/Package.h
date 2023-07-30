// Package.h

/*
	Package Class for exercise 11.9: Package Inheritance Hierarchy

*/



#ifndef PACKAGE_H
#define PACKAGE_H

#include<string>
#include<vector>

class Package
{
public:
	Package(const std::string& from_nme, const std::string& to_nme,
		const std::string& from_addr, const std::string& to_addr,
		const std::string& from_cty, const std::string& to_cty,
		const std::string& from_stat, const std::string& to_stat,
		const std::string& from_zip, const std::string& to_zip,
		double wght, double cst);

	double calculateCost()  const;
	std::string to_string() const;

protected:
	
 	 std::string& get_from_nme()  ;
	 std::string& get_to_nme()    ;
	 std::string& get_from_addr() ;
	 std::string& get_to_addr()   ;
	 std::string& get_from_cty()  ; 
	 std::string& get_to_cty()    ;
	 std::string& get_from_stat() ;
	 std::string& get_to_stat()   ;
	 std::string& get_from_zip()  ;
	 std::string& get_to_zip()    ;
	 double 	  get_weight() const   { return weight; }
	 double 	  get_cost()   const   { return cost; }
	 void		  set_weight(double);
	 void		  set_cost(double);
	
private:
	static struct from_to {
		std::string from;
		std::string to;
	};

	std::vector<from_to> inf;
	double weight;
	double cost;
	std::string& advance(int, bool);

};

#endif // !PACKAGE_H

