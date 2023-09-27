#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public :
		/*------------------------------------*/
		/*   Constructors and destructor      */
		/*------------------------------------*/
		AForm(const std::string, int, int);
		AForm(const AForm &);
		virtual ~AForm();

		/*------------------------------------*/
		/*       Overloading operators        */
		/*------------------------------------*/
		AForm &operator=(const AForm &);

		/*------------------------------------*/
		/*               Methods              */
		/*------------------------------------*/
		const std::string &getName() const;
		const int &getSignGrade() const;
		const int &getExecGrade() const;
		const bool &getIfSign() const;
		void beSigned(const Bureaucrat &obj);
		void execute(const Bureaucrat &executor) const;
		virtual void beExecuted() const = 0;

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

		class notSignedException : public std::exception {
			public :
				virtual const char *what() const throw();
		};

	protected :
		std::string target;

	private :
		const std::string name;
		bool signStatus;
		const int signGrade;
		const int execGrade;
};

std::ostream &operator<<(std::ostream &ost, const AForm &obj);

#endif