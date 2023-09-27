#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <iostream>

class ShrubberyCreationForm : public AForm {
	public :
		ShrubberyCreationForm(const std::string);
		ShrubberyCreationForm(const ShrubberyCreationForm &);
		~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);

		void beExecuted() const;
	protected :

	private :
};

#endif