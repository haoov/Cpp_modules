#include "../incs/btc.hpp"
#include <map>
#include "../incs/Parser.hpp"

int main(int argc, char *argv[]) {
	if (argc < 2) {
		return -1;
	}
	Parser parser(',');
	str_float_map date_currency;
	str_float date_value;
	try {
		date_currency = parser.parseFile("data.csv");
		str_float_map::iterator it = date_currency.begin();
		//str_float_map::iterator end = date_currency.end();
		++it;
		std::cout << it->first << std::endl;
		(void)argv;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}