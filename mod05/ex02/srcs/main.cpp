#include "../incs/Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Bureaucrat steve("Steve", 123);
	Bureaucrat john("John", 1);
	ShrubberyCreationForm s1("Stest");
	RobotomyRequestForm r1("Rtest");
	PresidentialPardonForm p1("Ptest");
	steve.signForm(s1);
	steve.signForm(r1);
	steve.signForm(p1);
	steve.executeForm(s1);
	john.executeForm(r1);
	john.signForm(r1);
	john.signForm(p1);
	john.executeForm(r1);
	john.executeForm(p1);
}