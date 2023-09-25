#include "sed.h"

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Invalid number of arguments" << std::endl;
	}
	try {
		std::string content = readFile(argv[1]);
		replace(content, argv[2], argv[3]);
		writeFile(content, std::string(argv[1]) + ".replace");
	}
	catch (std::ios_base::failure &fail) {
		std::cout << fail.what();
	}
}