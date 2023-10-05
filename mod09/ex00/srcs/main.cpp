#include "../incs/btc.hpp"
#include <map>
#include "../incs/Parser.hpp"

int main(int argc, char *argv[]) {
	if (argc < 2) {
		return -1;
	}
	Parser parser(',');
	str_float_map date_currency;
	try {
		date_currency = parser.parseFile("data.csv");
		analyseInput(argv[1], date_currency);
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
		return -1;
	}
	return 0;
}