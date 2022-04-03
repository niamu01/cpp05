/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:44:06 by qli               #+#    #+#             */
/*   Updated: 2022/04/03 17:14:02 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "Form.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("presidential pardon", 25, 5){
	return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
Form("presidential pardon", 25, 5)
{
	this->setFormTarget(target);
}

PresidentialPardonForm::~PresidentialPardonForm() {
	return;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs) : Form(rhs.getName(), rhs.getGradeToSign(), rhs.getGradeToExecute()){
	std::cout << YELLOW << "<PresidentialPardonForm> copy constructor is called." << RESET << std::endl;
	*this = rhs;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
	if (this != &rhs)
	{
		this->setSignedResult(rhs.getSignedResult());
		this->setFormTarget(rhs.getFormTarget());
	}
	return *this;
}

void PresidentialPardonForm::executeForm() const {
	std::cout << BLUE << this->getFormTarget() << " has been pardoned by Zafod Beeblebrox." << RESET << std::endl;
}