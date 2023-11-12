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
		rpn.compute();
		res = rpn.getRes();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return -1;
	}
	std::cout << "result = " << res << std::endl;
	return 0;
}
