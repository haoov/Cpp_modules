#include "../incs/PmergeMe.hpp"

int main(int argc, char *argv[]) {
	if (argc < 2)
		return -1;
	PmergeMe vecPmerge(argv[1]);
	try {
		vecPmerge.parseArg();
		vecPmerge.sort();
		vecPmerge.insert();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return -1;
	}
	std::vector<int> vec = vecPmerge.getMain();
	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
		if (i == vec.size() -1)
			std::cout << std::endl;
	}
}