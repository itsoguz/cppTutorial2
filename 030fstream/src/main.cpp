#include <iostream>
#include <fstream>
#include <deque>
#include <stdexcept>
#include <limits>
#include "Food.hpp"

static std::deque<Food> contFoods;

void initializeFoods(){				// No need to use this function
	std::ofstream oFile("foods.txt");	// outputFile
	oFile << "lemon 1.5 cheese 1.1 pie 2.4 pizza 6.0";
	oFile.close();
}

int initialImport(){				// No need to use this function
	std::ifstream iFile("foods.txt");	// inputFile
	
	//std::deque<Food> contFoods;	// containerFoods
	Food tmpFood;			// temporaryFood
	std::string tmpStr;
	
	while (iFile >> tmpStr){
		tmpFood.setName(tmpStr);
		if (iFile >> tmpStr){
			try{
				tmpFood.setCost(std::stod(tmpStr));	// convert "3.14" to 3.14 and setCost(3.14);
			}
			catch (const std::invalid_argument& e){		// "abc" is not a double, catch exception
				std::cerr << "Invalid argument: " << e.what() << std::endl;
				return -1;
			}
			contFoods.push_back(tmpFood);
		}
	}
	iFile.close();
	return 0;
}

int main(){
	//initializeFoods();
	//initialImport();
	
	std::ifstream iFile("foods.txt");
	if (iFile.is_open()) {
		importContainer(contFoods, iFile);
		iFile.close();
	} else {
		std::cerr << "Error opening file: foods.txt" << std::endl;
		return -1;
	}
	
	std::cout << "Program started with initial shopping list:" << std::endl;
	printContainer(contFoods);

	Food tmpFood;
	int response = 0;
	while (response != -1 && response != -2) {
		std::cout << "Choose an option:" << std::endl;
		std::cout << "Press 1 - Display foods" << std::endl;
		std::cout << "Press 2 - Add food to top" << std::endl;
		std::cout << "Press 3 - Add food to bottom" << std::endl;
		std::cout << "Press 4 - Remove food from top" << std::endl;
		std::cout << "Press 5 - Remove food from bottom" << std::endl;
		std::cout << "Input -1 - Save and quit" << std::endl;
		std::cout << "Input -2 - Quit without saving" << std::endl;
	
		std::cin >> response;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		switch (response) {
			case 1:
				printContainer(contFoods);
				break;		
			case 2:
				std::cout << "Food and cost? Example: tomato 1.65" << std::endl;
				importFoods(tmpFood, std::cin);
				contFoods.push_front(tmpFood);
				break;
			case 3:
				std::cout << "Food and cost? Example: tomato 1.65" << std::endl;
				importFoods(tmpFood, std::cin);
				contFoods.push_back(tmpFood);
				break;
			case 4:
				std::cout << "Removed: " << contFoods.front().getName() << std::endl;
				contFoods.pop_front();
				break;
			case 5:
				std::cout << "Removed " << contFoods.back().getName() << std::endl;
				contFoods.pop_back();
				break;
			case -1: {
				std::cout << "foods.txt file has been saved." << std::endl;
				std::ofstream oFile;
				oFile.open("foods.txt");
				if (oFile.is_open()) {
					printContainer(contFoods, oFile);
					oFile.close();
				}
				break;
			}
			case -2:			
				break;
			default:
				break;
		}
	std::cout << std::endl;
	}
	return 0;
}

