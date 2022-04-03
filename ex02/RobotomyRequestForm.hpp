
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "Form.hpp"

class RobotomyRequestForm : public Form
{

private:
	RobotomyRequestForm();

public:
	RobotomyRequestForm(std::string target);
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const &rhs);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

	virtual void executeForm() const;
};

#endif // ROBOTOMYREQUESTFORM_HPP
