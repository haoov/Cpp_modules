#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm {
	public :
		PresidentialPardonForm(const std::string);
		PresidentialPardonForm(const PresidentialPardonForm &);
		~PresidentialPardonForm();

		PresidentialPardonForm &operator=(const PresidentialPardonForm &);

		void beExecuted() const;
	protected :

	private :
};

#endif