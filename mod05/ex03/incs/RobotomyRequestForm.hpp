#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>

class RobotomyRequestForm : public AForm {
	public :
		RobotomyRequestForm(const std::string);
		RobotomyRequestForm(const RobotomyRequestForm &);
		~RobotomyRequestForm();

		RobotomyRequestForm &operator=(const RobotomyRequestForm &);

		void beExecuted() const;
	protected :

	private :

};

#endif