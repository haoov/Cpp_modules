#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Bureaucrat steve("Steve", 123);
	Bureaucrat john("John", 1);
	Form a1("A1", 145, 90), b1("B1", 85, 21);
	std::cout << a1 << std::endl;
	steve.signForm(a1);
	john.signForm(a1);
	std::cout << a1 << std::endl;
	steve.signForm(b1);
	std::cout << b1 << std::endl;
	john.signForm(b1);
	std::cout << b1 << std::endl;
}