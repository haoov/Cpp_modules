#include "../incs/btc.hpp"
#include <map>

str_float_map readFile(const char *, char);

int main(int argc, char *argv[]) {
	static_cast<void>(argc);
	static_cast<void>(argv);
	//str_float_map date_currency = readFile("data.csv", ',');
	str_float_map date_value = readFile(argv[1], '|');
	str_float_map::iterator it = date_value.begin();
	str_float_map::iterator end = date_value.end();
	while (it != end) {
		std::cout << it->first << " | " << it->second << std::endl;
		++it; 
	}
}