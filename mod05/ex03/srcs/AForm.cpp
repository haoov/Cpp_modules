#include "AForm.hpp"

/*------------------------------------*/
/*    Constructors and destructor     */
/*------------------------------------*/

AForm::AForm(const std::string name, int sign, int exec)
: name(name), signGrade(sign), execGrade(exec) {
	if (sign < 1 || exec < 1) {
		throw AForm::GradeToHighException();
	}
	if (sign > 150 || exec > 150) {
		throw AForm::GradeToLowException();
	}
	this->signStatus = false;
}

AForm::AForm(const AForm &other)
: name(other.name), signGrade(other.signGrade), execGrade(other.execGrade) {
	*this = other;
}

AForm::~AForm() {}

/*------------------------------------*/
/*       Overloading operators        */
/*------------------------------------*/

AForm &AForm::operator=(const AForm &other) {
	this->signStatus = other.signStatus;
	return (*this);
}

std::ostream &operator<<(std::ostream &ost, const AForm &obj) {
	ost << "Form " << obj.getName() << std::endl;
	ost << "grade requiered to sign: " << obj.getSignGrade() << std::endl;
	ost << "grade requiered to execute: " << obj.getExecGrade() << std::endl;
	ost << "signed: ";
	if (obj.getIfSign() == true) {
		ost << "yes";
	}
	else {
		ost << "no";
	}
	return (ost);
}

/*------------------------------------*/
/*              Methods               */
/*------------------------------------*/

const std::string &AForm::getName() const {
	return (this->name);
}

const int &AForm::getExecGrade() const {
	return (this->execGrade);
}

const int &AForm::getSignGrade() const {
	return (this->signGrade);
}

const bool &AForm::getIfSign() const {
	return (this->signStatus);
}

void AForm::beSigned(const Bureaucrat &obj) {
	if (obj.getGrade() > this->signGrade) {
		throw AForm::GradeToLowException();
	}
	this->signStatus = true;
}

void AForm::execute(const Bureaucrat &executor) const {
	if (this->signStatus == false) {
		throw AForm::notSignedException();
	}
	if (executor.getGrade() > this->execGrade) {
		throw AForm::GradeToLowException();
	}
	this->beExecuted();
}

/*------------------------------------*/
/*         Exception methods          */
/*------------------------------------*/

const char *AForm::GradeToHighException::what() const throw() {
	return ("Grade to high");
}

const char *AForm::GradeToLowException::what() const throw() {
	return ("Grade to low");
}

const char *AForm::notSignedException::what() const throw() {
	return ("Form not signed");
}