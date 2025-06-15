// Food.hpp
//
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

inline void print(Food &f){
	std::cout << f.getName() << " " << f.getCost() << std::endl;
}

inline void print(Food &f, std::ostream& out){	// export()
	out << f.getName() << " " << f.getCost() << std::endl;
}

template <template <typename> typename Container, typename T>
void printContainer(Container<T>& cont) {
	for ( auto c : cont )
		print(c);
	std::cout << std::endl;
}

template <template <typename> typename Container, typename T>
void printContainer(Container<T>& cont, std::ostream& out) {
	for ( auto c : cont )
		print(c, out);
}

inline void importFoods(Food& f, std::istream& is){
	std::string tmpStr;
	if ( std::getline(is, tmpStr) ) {
		size_t delimiterPos = tmpStr.find(' ');
		if ( delimiterPos != std::string::npos ) {
			std::string str1 = tmpStr.substr(0, delimiterPos);
			std::string str2 = tmpStr.substr(delimiterPos+1);
			f.setName(str1);
			f.setCost(std::stod(str2));
		}
	}
}

#endif
