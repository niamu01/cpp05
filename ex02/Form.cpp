/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 21:07:48 by yeju              #+#    #+#             */
/*   Updated: 2022/04/06 18:52:39 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("name"), _signed(false), _gradeToSign(1), _gradeToExecute(1)
{
	std::cout << "Form: Default constructor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Form: Constructor called" << std::endl;
	try
	{
		if (this->getGradeToSign() < 1 || this->getGradeToExecute() < 1)
			throw GradeTooHighException();
		else if (this->getGradeToSign() > 150 || this->getGradeToExecute() > 150)
			throw GradeTooLowException();
	}
	catch (const GradeTooHighException &_throw)
	{
		std::cout << YELLOW;
		std::cout << _throw.what() << std::endl;
		std::cout << RESET;
	}
	catch (const GradeTooLowException &_throw)
	{
		std::cout << YELLOW;
		std::cout << _throw.what() << std::endl;
		std::cout << RESET;
	}
	std::cout << CYAN;
	std::cout << "Form '" << this->getName() << "' is created by Constructor"  << std::endl;
	std::cout << "'" << this->getGradeToSign() << "'grade to sign and '" << this->getGradeToExecute() << "' to execute" << std::endl;
	std::cout << RESET;
}

Form::~Form()
{
	std::cout << "Form: Destructor called" << std::endl;
	std::cout << CYAN;
	std::cout << "Form: " << this->getName() << " is destroyed by Destructor" << std::endl;
	std::cout << RESET;
}

Form::Form(const Form &rhs) : _name(rhs.getName()), _signed(rhs.getSigned()), _gradeToSign(rhs.getGradeToSign()), _gradeToExecute(rhs.getGradeToExecute())
{
	std::cout << "Form: Copy constructor called" << std::endl;
	*this = rhs;
}

Form &Form::operator=(const Form &rhs)
{
	std::cout << "Form: assignation operator is called" << std::endl;
	this->_signed = rhs.getSigned();
	return (*this);
}

std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getSigned() const
{
	return (this->_signed);
}

void Form::setSigned(bool sign)
{
	this->_signed = sign;
}

int Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	try
	{
		if (this->getGradeToSign() < bureaucrat.getGrade())
			throw GradeTooLowException();
	}
	catch (const GradeTooLowException &_throw)
	{
		std::cout << RED;
		std::cout << _throw.what() << std::endl;
		std::cout << RESET;
		return;
	}
	if (this->getGradeToSign() >= bureaucrat.getGrade())
	{
		std::cout << CYAN;
		std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
		std::cout << RESET;
		this->_signed = true;
	}
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	if (form.getSigned())
	{
		out << GREEN;
		out << "Form " << form.getName() << " is signed.";
		out << RESET;
	}
	else
	{
		out << RED;
		out << "Form " << form.getName() << " is not signed.";
		out << RESET;
	}
	return (out);
}

void Form::execute(const Bureaucrat &executor) const
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
		executeForm();
}

bool Form::checkFormSignedStatus(void) const
{
	if (this->getSigned())
		return (true);
	return (false);
}

bool Form::checkFormExecuteGrade(const Bureaucrat &execute) const
{
	try
	{
		if (this->getGradeToExecute() < execute.getGrade())
			throw GradeTooLowException();
	}
	catch (const GradeTooLowException &_throw)
	{
		std::cout << RED;
		std::cout << _throw.what() << std::endl;
		std::cout << RESET;
		return (false);
	}
	return (true);
}

void Form::setFormTarget(std::string target)
{
	this->_target = target;
}

std::string Form::getFormTarget() const
{
	return (this->_target);
}
