#include <list>
#include <iostream>
#include "RPN.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		return -1;
	}
	RPN rpn(argv[1]);
	int res = 0;
	try {
		rpn.parseArg();
		res = rpn.compute();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return -1;
	}
	std::cout << res << std::endl;
	return 0;
}
