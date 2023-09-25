#include "sed.h"

std::string readFile(char *file) {
	std::string content;
	std::ifstream ifs;
	ifs.exceptions(ifs.badbit | ifs.failbit);
	ifs.open(file);
	std::getline(ifs, content, '\0');
	ifs.close();
	return content;
}