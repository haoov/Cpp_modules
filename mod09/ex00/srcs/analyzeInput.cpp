#include "../incs/btc.hpp"
#include "../incs/Parser.hpp"

/**
 * @brief Function to analyse the parse data from an input file 
 * and compute the value with the given currency
 * 
 * @param inputFile the file to parse and compare
 * @param date_currency a map<string, float> containing the data to compare with
*/
void analyseInput(const char *inputFile, str_float_map date_currency) {
	Parser parser('|');
	parser.openFile(inputFile);
	str_float date_value;
	while (!parser.eof()) {
		try {
			date_value = parser.parseLine(true);
			str_float_map::iterator it = date_currency.begin();
			str_float_map::iterator end = date_currency.end();
			while (it != end && date_value.first.compare(it->first) > 0)
				++it;
			if (it == end || date_value.first.compare(it->first) < 0)
				--it;
			std::cout	<< it->first << " => " << date_value.second
						<< " = " << date_value.second * it->second << std::endl;
		}
		catch (Parser::EofReached &e) {
			//do nothing
		}
		catch (Parser::EmptyLine &e) {
			//discard the line
		}
		catch (Parser::Error &e) {
			std::cout << "Parser error: " << e.what() << std::endl;
		}
	}
}