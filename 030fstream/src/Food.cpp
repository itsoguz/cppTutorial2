// Food.cpp

#include "Food.hpp"
#include <iostream>
#include <string>
#include <deque>

Food::Food(std::string name, double cost) : _name(name), _cost(cost) {}

void Food::setName(std::string name_){
	_name = name_;
}
void Food::setCost(double cost_){
	_cost = cost_;
}
const std::string& Food::getName() const{
	return _name;
}
const double& Food::getCost() const{
	return _cost;
}

void Food::print() const {
	std::cout << _name << " " << _cost << std::endl;
}

//template void printContainer(std::deque<Food>& cont);
