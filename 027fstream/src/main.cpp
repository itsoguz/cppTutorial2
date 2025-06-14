#include <iostream>
#include <fstream>
#include <deque>
#include "Food.hpp"

int main(){
	std::deque<Food> contFoods;	// containerFoods
	Food tmpFood;			// temporaryFood

	std::ofstream oFile("foods.txt");	// outputFile
	oFile << "lemon 1.5 cheese 1.1 pie 2.4 pizza 6.0";
	oFile.close();

	std::ifstream iFile("foods.txt");	// inputFile
	
	while (iFile >> tmpFood.name >> tmpFood.cost)
		contFoods.push_back(tmpFood);
	iFile.close();

	for (auto i : contFoods)
		i.print();

	return 0;
}
