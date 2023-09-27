#include "ShrubberyCreationForm.hpp"
#include <fstream>

/*------------------------------------*/
/*     Constructors and destructor    */
/*------------------------------------*/

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
: AForm("ShrubberyCreationForm", 145, 137) {
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
: AForm(other) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

/*------------------------------------*/
/*       Overloading operators        */
/*------------------------------------*/

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	this->AForm::operator=(other);
	return (*this);
}

/*------------------------------------*/
/*               Methods              */
/*------------------------------------*/

void ShrubberyCreationForm::beExecuted() const {
	std::ofstream file(this->target + "_shrubbery");
	if (file.fail()) {
		throw std::ofstream::failure("open failed");
	}
	file	<< "project/" << std::endl
			<< "├─ srcs/" << std::endl
			<< "├─ incs/" << std::endl
			<< "├─ Makefile" << std::endl
			<< "├─ Readme.md" << std::endl;
	file.close();
}
