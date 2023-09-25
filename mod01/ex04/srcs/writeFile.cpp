#include "sed.h"

void writeFile(std::string &content, std::string file) {
	std::ofstream ofs;
	ofs.exceptions(ofs.badbit | ofs.failbit | ofs.eofbit);
	ofs.open(file);
	ofs << content;
	ofs.close();
}