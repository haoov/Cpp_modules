#include "BitcoinExchange.hpp"
#include <map>

int main(int argc, char *argv[]) {
	if (argc < 2) {
		std::cout << "Error: no input file" << std::endl;
		return -1;
	}
	BitcoinExchange btc(',');
	str_float_map date_currency;
	try {
		date_currency = btc.parseFile("data.csv");
		analyseInput(argv[1], date_currency);
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
		return -1;
	}
	return 0;
}

/**
 * @brief Function to analyse the parse data from an input file 
 * and compute the value with the given currency
 * 
 * @param inputFile the file to parse and compare
 * @param date_currency a map<string, float> containing the data to compare with
*/
void analyseInput(const char *inputFile, str_float_map date_currency) {
	BitcoinExchange btc('|');
	btc.openFile(inputFile);
	str_float date_value;
	while (!btc.eof()) {
		try {
			date_value = btc.parseLine(true);
			str_float_map::iterator it = date_currency.begin();
			str_float_map::iterator end = date_currency.end();
			while (it != end && date_value.first.compare(it->first) > 0)
				++it;
			if (it == end || date_value.first.compare(it->first) < 0)
				--it;
			std::cout	<< it->first << " => " << date_value.second
						<< " = " << date_value.second * it->second << std::endl;
		}
		catch (BitcoinExchange::EofReached &e) {
			//do nothing
		}
		catch (BitcoinExchange::EmptyLine &e) {
			//discard the line
		}
		catch (BitcoinExchange::Error &e) {
			std::cout << "Parser error: " << e.what() << std::endl;
		}
	}
}