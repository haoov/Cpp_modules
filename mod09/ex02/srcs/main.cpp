#include "../incs/PmergeMe.hpp"
#include "../incs/PmergeMe.tpp"

int main(int argc, char *argv[]) {
	if (argc < 2)
		return -1;
	try {
		PmergeMe<std::vector> vecPmerge(argv[1]);
		PmergeMe<std::deque> deqPmergeMe(argv[1]);
		std::cout << "BEFORE: " << std::endl;
		std::cout << argv[1] << std::endl;
		std::cout << "AFTER: " << std::endl;
		vecPmerge.printChain();
		std::cout << "sorting time using vector: " << vecPmerge.getTime() << std::endl;
		std::cout << "sorting time using deque: " << deqPmergeMe.getTime() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return -1;
	}
}