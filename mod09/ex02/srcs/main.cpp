#include "../incs/PmergeMe.hpp"
#include "../incs/PmergeMe.tpp"

int main(int argc, char *argv[]) {
	if (argc < 2)
		return -1;
	try {
		std::cout << "with vectors :" << std::endl;
		PmergeMe<std::vector> vecPmerge(argv[1]);
		std::cout << std::endl;
		std::cout << "with deque :" << std::endl;
		PmergeMe<std::deque> deqPmergeMe(argv[1]);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return -1;
	}
}