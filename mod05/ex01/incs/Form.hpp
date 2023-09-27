#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public :
		/*------------------------------------*/
		/*   Constructors and destructor      */
		/*------------------------------------*/
		Form(const std::string, int, int);
		Form(const Form &);
		~Form();

		/*------------------------------------*/
		/*       Overloading operators        */
		/*------------------------------------*/
		Form &operator=(const Form &);

		/*------------------------------------*/
		/*               Methods              */
		/*------------------------------------*/
		const std::string &getName() const;
		const int &getSignGrade() const;
		const int &getExecGrade() const;
		const bool &getIfSign() const;
		void beSigned(const Bureaucrat &obj);

		/*------------------------------------*/
		/*         Exception classes          */
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
		bool signStatus;
		const int signGrade;
		const int execGrade;
};

std::ostream &operator<<(std::ostream &ost, const Form &obj);

#endif