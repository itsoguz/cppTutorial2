// Food.cpp

#include "Food.hpp"
#include <iostream>
#include <string>

Food::Food(std::string name_, double cost_) : name(name_), cost(cost_) {}
void Food::print() const {
	std::cout << name << " " << cost << std::endl;
}
