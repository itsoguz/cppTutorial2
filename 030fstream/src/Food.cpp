// Food.cpp

#include "Food.hpp"
#include <iostream>
#include <string>
//#include <deque>

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

// Definitions for the non-template print functions
void print(Food &f){
	std::cout << f.getName() << " " << f.getCost() << std::endl;
}

void print(Food &f, std::ostream& out){
	out << f.getName() << " " << f.getCost() << std::endl;
}

void stof(std::string& str, Food& food) {	// string_to_food()
	size_t delimiterPos = str.find(' ');
	if ( delimiterPos != std::string::npos ) {
		std::string str1 = str.substr(0, delimiterPos);
		std::string str2 = str.substr(delimiterPos+1);
		food.setName(str1);
		try {
			double cost = std::stod(str2);
			food.setCost(cost);
		} catch (const std::invalid_argument& e) {
			std::cerr << "Invalid argument for cost: " << e.what() << std::endl;
			food.setCost(0.0);
		} catch (const std::out_of_range& e) {
			std::cerr << "Cost out of range: " << e.what() << std::endl;
			food.setCost(0.0);
		}
	}
}

void importFoods(Food& f, std::istream& is){
	std::string tmpStr;
	if ( std::getline(is, tmpStr) ) {
		stof(tmpStr, f);
	}
}

//template void printContainer(std::deque<Food>& cont);

