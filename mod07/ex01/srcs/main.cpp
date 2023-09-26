#include "../incs/FctTemplates.hpp"

int main() {
	char array[6] = "salut";
	iter(array, 6, print<char>);
}