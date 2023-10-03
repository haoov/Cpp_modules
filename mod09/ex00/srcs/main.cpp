#include "../incs/btc.hpp"
#include <map>
#include "../incs/Parser.hpp"

str_float_map readFile(const char *, char);

int main(int argc, char *argv[]) {
	static_cast<void>(argc);
	static_cast<void>(argv);
	Parser parser(',');
	str_float_map date_currency = parser.parseFile("data.csv");
	str_float_map::iterator it = date_currency.begin();
	str_float_map::iterator end = date_currency.end();
	while (it != end) {
		std::cout << it->first << " | " << it->second << std::endl;
		++it; 
	}
}