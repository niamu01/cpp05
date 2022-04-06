/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:29:08 by yeju              #+#    #+#             */
/*   Updated: 2022/04/06 19:26:07 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("Form_presidential", 25, 5)
{
	std::cout << "PresidentialPardonForm: Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form(target, 25, 5)
{
	std::cout << "PresidentialPardonForm: Constructor called" << std::endl;
	this->setFormTarget(target);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm: Destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs) : Form(rhs.getName(), rhs.getGradeToSign(), rhs.getGradeToExecute())
{
	std::cout << "PresidentialPardonForm: Copy constructor called" << std::endl;
	*this = rhs;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	std::cout << "PresidentialPardonForm: assignation operator is called" << std::endl;
	this->setSigned(rhs.getSigned());
	this->setFormTarget(rhs.getFormTarget());
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (!this->checkFormSignedStatus())
	{
		std::cout << RED;
		std::cout << this->getName() << " can't executed "<< executor.getName() << ", because the form is not signed." << std::endl;
		std::cout << RESET;
	}
	else if (!this->checkFormExecuteGrade(executor))
	{
		std::cout << RED;
		std::cout << this->getName() << " can't executed "<< executor.getName() << ", because the form does not have a high score." << std::endl;
		std::cout << RESET;
	}
	else
	{
		std::cout << CYAN;
		std::cout << this->getFormTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
		std::cout << RESET;
	}
}
