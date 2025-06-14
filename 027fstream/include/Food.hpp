// Food.hpp
//
#ifndef FOOD_HPP
#define FOOD_HPP
#include <string>

class Food {
	public:
		std::string name;	// variables are public because: "file.txt >> food.name" in main.cpp
		double cost;

		Food() = default;
		Food(std::string name, double cost);
		void print() const;
};

#endif
