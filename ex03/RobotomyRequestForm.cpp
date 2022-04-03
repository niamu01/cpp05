
#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include "Form.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("robotomy request", 72, 45)
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("robotomy request", 72, 45)
{
	this->setFormTarget(target);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs) : Form(rhs.getName(), rhs.getGradeToSign(), rhs.getGradeToExecute())
{
	std::cout << YELLOW << "<RobotomyRequestForm> copy constructor is called." << RESET << std::endl;
	*this = rhs;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this != &rhs)
	{
		this->setSignedResult(rhs.getSignedResult());
		this->setFormTarget(rhs.getFormTarget());
	}
	return *this;
}

void RobotomyRequestForm::executeForm() const
{

	std::cout << BLUE << "Drilling noises..." << RESET << std::endl;
	srand(time(NULL));
	int ret = rand() % 2;
	if (ret)
		std::cout << BLUE << "<" << this->getFormTarget() << "> has been robotomized successfully." << RESET << std::endl;
	else
		std::cout << BLUE << "The executor failed to robotomize <" << this->getFormTarget() << ">." << RESET << std::endl;
}