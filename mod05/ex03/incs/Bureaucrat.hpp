#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
	public :
		/*------------------------------------*/
		/*    Constructors and destructors    */
		/*------------------------------------*/
		Bureaucrat(const std::string, int);
		Bureaucrat(const Bureaucrat &);
		~Bureaucrat();

		/*------------------------------------*/
		/*        Overloading operators       */
		/*------------------------------------*/
		Bureaucrat &operator=(const Bureaucrat &);

		/*------------------------------------*/
		/*               Methods              */
		/*------------------------------------*/
		std::string getName() const;
		int getGrade() const;
		void upGrade();
		void downGrade();
		void signForm(AForm &) const;
		void executeForm(const AForm &) const;

		/*------------------------------------*/
		/*         Exceptions classes         */
		/*------------------------------------*/
		class GradeToHighException : public std::exception {
			public :
				virtual const char *what() const throw();
		};

		class GradeToLowException : public std::exception {
			public :
				virtual const char *what() const throw();
		};

	protected :

	private :
		const std::string name;
		int grade;
};

std::ostream &operator<<(std::ostream &ost, const Bureaucrat &obj);

#endif