#include "Bureaucrat.hpp"

/*-----------------------------------*/
/*    Constructors and destructor    */
/*-----------------------------------*/

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade) {
	if (grade < 1) {
		throw Bureaucrat::GradeToLowException();
	}
	if (grade > 150) {
		throw Bureaucrat::GradeToLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
	*this = other;
}

Bureaucrat::~Bureaucrat() {}

/*------------------------------------*/
/*        Overloading operators       */
/*------------------------------------*/

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	this->grade = other.grade;
	return (*this);
}

std::ostream &operator<<(std::ostream &ost, const Bureaucrat &obj) {
	ost << "Bureaucrat " << obj.getName() << " grade: " << obj.getGrade();
	return (ost);
}

/*------------------------------------*/
/*               Methods              */
/*------------------------------------*/

std::string Bureaucrat::getName() const {
	return (this->name);
}

int Bureaucrat::getGrade() const {
	return (this->grade);
}

void Bureaucrat::upGrade() {
	--(this->grade);
	if (this->grade < 1) {
		throw Bureaucrat::GradeToHighException();
	}
}

void Bureaucrat::downGrade() {
	++(this->grade);
	if (this->grade > 150) {
		throw Bureaucrat::GradeToLowException();
	}
}

void Bureaucrat::signForm(Form &obj) const {
	try {
		obj.beSigned(*this);
	}
	catch (Form::GradeToLowException &e) {
		std::cout	<< this->name << " could not sign form "
					<< obj.getName() << " because " << e.what() << std::endl;
		return;
	}
	std::cout << this->name << " signed form " << obj.getName() << std::endl;
}

/*------------------------------------*/
/*         Exception methods          */
/*------------------------------------*/

const char *Bureaucrat::GradeToHighException::what() const throw() {
	return ("Grade to high");
}

const char *Bureaucrat::GradeToLowException::what() const throw() {
	return ("Grade to low");
}