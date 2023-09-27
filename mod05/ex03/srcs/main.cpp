#include "../incs/Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	Bureaucrat steve("Steve", 123);
	Bureaucrat john("John", 1);
	Intern intern1;
	AForm *p1 = intern1.makeForm("PresidentialPardonForm", "Some guy");
	steve.signForm(*p1);
	AForm *s1;
	try {
		s1 = intern1.makeForm("WrongForm", "Some place");
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	if (s1) {
		delete s1;
	}
	delete p1;
}