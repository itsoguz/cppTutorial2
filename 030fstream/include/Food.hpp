// Food.hpp

#ifndef FOOD_HPP
#define FOOD_HPP
#include <iostream>
//#include <ostream>
//#include <ofstream>
#include <string>

class Food {
	private:
		std::string _name;
		double _cost;
	public:
		Food() = default;
		Food(std::string name, double cost);
		~Food() = default;

		void setName(std::string name_);		
		void setCost(double cost_);
		const std::string& getName() const;	// encapsulation is not broken because returned reference is const
		const double& getCost() const;
		
		void print() const;
//		friend void print(Food &f);	// friend function is not needed, getters() are enough.
};

template <typename T>
void print(T& t){
	std::cout << t << " ";
}

template <typename T>
void print(T& t, std::ostream& out) {
	out << t << " ";
}

void print(Food &f);
void print(Food &f, std::ostream& out);		// export()

template <template <typename> typename Container, typename T>
void printContainer(Container<T>& cont) {
	for ( auto c : cont )
		print(c);
	//std::cout << std::endl;
}

template <template <typename> typename Container, typename T>
void printContainer(Container<T>& cont, std::ostream& out) {
	for ( auto c : cont )
		print(c, out);
}

void stof(std::string& str, Food& food);				// string_to_food()
void importFoods(Food& f, std::istream& is);

template <template <typename> typename Container>
void importContainer(Container<Food>& cont, std::istream& is) {		// Deque<Food>
	Food f;
	std::string s;
	while ( std::getline(is, s) ) {
		stof(s, f);
		cont.push_back(f);
	}	
}

#endif

