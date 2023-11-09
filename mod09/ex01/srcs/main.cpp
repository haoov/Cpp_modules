#include <list>
#include <iostream>
#include "RPN.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		return -1;
	}
	RPN rpn(argv[1]);
	try {
		rpn.parseArg();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return -1;
	}
	std::vector<RPN::s_arg> args = rpn.getArgs();
	for (size_t i = 0; i < args.size(); ++i) {
		if (args[i].op)
			std::cout << static_cast<char>(args[i].val) << std::endl;
		else
			std::cout << args[i].val << std::endl;
	}
	return 0;
}
