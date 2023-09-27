#include "PresidentialPardonForm.hpp"

/*------------------------------------*/
/*    Constructors and destructor     */
/*------------------------------------*/

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
: AForm("PresidentialPardonForm", 25, 5) {
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
: AForm(other) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

/*------------------------------------*/
/*       Overloading operators        */
/*------------------------------------*/

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	this->AForm::operator=(other);
	return (*this);
}

/*------------------------------------*/
/*              Methods               */
/*------------------------------------*/

void PresidentialPardonForm::beExecuted() const {
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}