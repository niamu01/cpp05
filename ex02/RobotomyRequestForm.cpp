/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:12:10 by yeju              #+#    #+#             */
/*   Updated: 2022/04/03 20:54:40 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("robotomy request", 72, 45)
{
	std::cout << "RobotomyRequestForm: Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("robotomy request", 72, 45)
{
	std::cout << "RobotomyRequestForm: Constructor called" << std::endl;
	this->setFormTarget(target);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm: Destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs) : Form(rhs.getName(), rhs.getGradeToSign(), rhs.getGradeToExecute())
{
	std::cout << "RobotomyRequestForm: Copy constructor called" << std::endl;
	*this = rhs;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	std::cout << "RobotomyRequestForm: assignation operator is called" << std::endl;
	this->setSigned(rhs.getSigned());
	this->setFormTarget(rhs.getFormTarget());
	return (*this);
}

void RobotomyRequestForm::executeForm() const
{

	std::cout << CYAN;
	std::cout << "Some drilling noises..." << std::endl;
	std::cout << RESET;

	srand(time(NULL));
	int randomnum = rand() % 2;
	if (randomnum)
	{
		std::cout << GREEN;
		std::cout << "<" << this->getFormTarget() << "> has been robotomized successfully" << std::endl;
		std::cout << RESET;
	}
	else
	{
		std::cout << RED;
		std::cout << "<" << this->getFormTarget() << ">. has been failed to robotomized" << std::endl;
		std::cout << RESET;
	}
}