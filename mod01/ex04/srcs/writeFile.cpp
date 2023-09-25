#include "sed.h"

void writeFile(std::string &content, std::string file) {
	std::ofstream ofs;
	ofs.exceptions(ofs.badbit | ofs.failbit | ofs.eofbit);
	ofs.open(file.c_str());
	ofs << content;
	ofs.close();
}