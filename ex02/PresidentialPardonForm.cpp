/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:29:08 by yeju              #+#    #+#             */
/*   Updated: 2022/04/06 19:07:33 by yeju             ###   ########.fr       */
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

void PresidentialPardonForm::executeForm() const
{
	std::cout << CYAN;
	std::cout << this->getFormTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
	std::cout << RESET;
}
