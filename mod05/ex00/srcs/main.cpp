#include "Bureaucrat.hpp"

int main() {
	Bureaucrat steve("Steve", 123);
	std::cout << steve << std::endl;
	steve.upGrade();
	std::cout << steve << std::endl;
	steve.downGrade();
	std::cout << steve << std::endl;
	Bureaucrat john("John", 1);
	try {
		john.upGrade();
	}
/* 	try {
		Bureaucrat greg("Greg", 0);
	}*/
/* 	try {
		Bureaucrat mike("Mike", 153);
	}*/
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return (-1);
	}
}