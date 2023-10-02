#include <iostream>
#include <map>

std::map<std::string, float> readCurrency(const char *file);

int main(int argc, char *argv[]) {
	static_cast<void>(argc);
	std::map<std::string, float> date_currency = readCurrency(argv[1]);
	std::map<std::string, float>::iterator it = date_currency.begin();
	std::map<std::string, float>::iterator end = date_currency.end();
	while (it != end) {
		std::cout << it->first << " | " << it->second << std::endl;
		++it; 
	}
}