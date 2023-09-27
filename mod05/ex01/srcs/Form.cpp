#include "Form.hpp"

/*------------------------------------*/
/*    Constructors and destructor     */
/*------------------------------------*/

Form::Form(const std::string name, int sign, int exec)
: name(name), signGrade(sign), execGrade(exec) {
	if (sign < 1 || exec < 1) {
		throw Form::GradeToHighException();
	}
	if (sign > 150 || exec > 150) {
		throw Form::GradeToLowException();
	}
	this->signStatus = false;
}

Form::Form(const Form &other)
: name(other.name), signGrade(other.signGrade), execGrade(other.execGrade) {
	*this = other;
}

Form::~Form() {}

/*------------------------------------*/
/*       Overloading operators        */
/*------------------------------------*/

Form &Form::operator=(const Form &other) {
	this->signStatus = other.signStatus;
	return (*this);
}

std::ostream &operator<<(std::ostream &ost, const Form &obj) {
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

const std::string &Form::getName() const {
	return (this->name);
}

const int &Form::getExecGrade() const {
	return (this->execGrade);
}

const int &Form::getSignGrade() const {
	return (this->signGrade);
}

const bool &Form::getIfSign() const {
	return (this->signStatus);
}

void Form::beSigned(const Bureaucrat &obj) {
	if (obj.getGrade() > this->signGrade) {
		throw Form::GradeToLowException();
	}
	this->signStatus = true;
}

/*------------------------------------*/
/*         Exception methods          */
/*------------------------------------*/

const char *Form::GradeToHighException::what() const throw() {
	return ("Grade to high");
}

const char *Form::GradeToLowException::what() const throw() {
	return ("Grade to low");
}