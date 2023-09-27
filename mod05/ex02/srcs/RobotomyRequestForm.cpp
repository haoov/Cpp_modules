#include "RobotomyRequestForm.hpp"
#include <ctime>

/*------------------------------------*/
/*     Contructors and destructor     */
/*------------------------------------*/

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
: AForm("RobotomyRequestForm", 72, 45) {
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
: AForm(other) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

/*------------------------------------*/
/*       Overloading operators        */
/*------------------------------------*/

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	this->AForm::operator=(other);
	return (*this);
}

/*------------------------------------*/
/*               Methods              */
/*------------------------------------*/

void RobotomyRequestForm::beExecuted() const {
	std::cout << "BRRRRRRZZZZ" << std::endl;
	srand(time(NULL));
	if (rand() % 100 < 50) {
		std::cout << this->target << " has been succesfully robotomized" << std::endl;
	}
	else {
		std::cout << "robotomy failed" << std::endl;
	}
}