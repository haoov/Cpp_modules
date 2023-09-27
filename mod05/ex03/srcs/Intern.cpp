#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/*------------------------------------*/
/*    Constructors and destructor     */
/*------------------------------------*/

Intern::Intern() {}

Intern::Intern(const Intern &other) {
	*this = other;
}

Intern::~Intern() {}

/*------------------------------------*/
/*       Overloading operators        */
/*------------------------------------*/

Intern &Intern::operator=(const Intern &other) {
	static_cast<void>(other);
	return (*this);
}

/*------------------------------------*/
/*               Methods              */
/*------------------------------------*/

AForm *Intern::makeForm(const std::string name, const std::string target) const {
	std::string names[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	int i = 0;
	while ( i < 3 && names[i] != name) {
		++i;
	}
	if (i == 3) {
		throw Intern::doesNotExists();
	}
	std::cout << "Intern creates " << names[i] << std::endl;
	switch (i) {
		case 0 :
			return (new ShrubberyCreationForm(target));
			break;
		case 1 :
			return (new RobotomyRequestForm(target));
			break;
		case 2 :
			return (new PresidentialPardonForm(target));
		default :
			break;
	}
	return (NULL);
}

/*------------------------------------*/
/*        Exceptions methods          */
/*------------------------------------*/

const char *Intern::doesNotExists::what() const throw() {
	return ("Does not exists");
}