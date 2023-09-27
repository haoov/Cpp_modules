#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Intern {
	public :
		Intern();
		Intern(const Intern &);
		~Intern();

		Intern &operator=(const Intern &);

		AForm *makeForm(const std::string, const std::string) const;

		class doesNotExists : public std::exception {
			public :
				const char *what() const throw();
		};
	protected :

	private :
};

#endif