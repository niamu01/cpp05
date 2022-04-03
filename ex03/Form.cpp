
#include <iostream>
#include "Form.hpp"

Form::Form() : _name("null"), _signed(false), _gradeToSign(0), _gradeToExecute(0)
{
	return;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{

	try
	{
		if (this->getGradeToSign() < 1 || this->getGradeToExecute() < 1)
			throw GradeTooHighException();
		else if (this->getGradeToSign() > 150 || this->getGradeToExecute() > 150)
			throw GradeTooLowException();
	}
	catch (const GradeTooHighException &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	catch (const GradeTooLowException &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	std::cout << GREEN << "* Form <" << this->getName() << "> is created with <" << this->getGradeToSign() << "> grade to sign and <" << this->getGradeToExecute() << "> to execute. *" << RESET << std::endl;
}

Form::~Form()
{
	std::cout << MAGENTA << "* Form <" << this->getName() << "> is destroyed. *" << RESET << std::endl;
}

Form::Form(const Form &rhs) : _name(rhs.getName()), _signed(rhs.getSigned()), _gradeToSign(rhs.getGradeToSign()), _gradeToExecute(rhs.getGradeToExecute())
{
	std::cout << YELLOW << "Form copy constructor is called." << std::endl;
	*this = rhs;
}

Form &Form::operator=(const Form &rhs)
{
	std::cout << YELLOW << "Form assignation operator is called." << std::endl;
	if (this != &rhs)
	{
		this->_signed = rhs.getSigned();
	}
	return *this;
}

std::string Form::getName() const
{
	return this->_name;
}

bool Form::getSigned() const
{
	return this->_signed;
}

int Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

int Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	try
	{
		if (this->getGradeToSign() < bureaucrat.getGrade())
			throw GradeTooLowException();
	}
	catch (const GradeTooLowException &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
		return;
	}
	if (this->getGradeToSign() >= bureaucrat.getGrade())
	{
		this->setSigned(true);
		std::cout << BLUE << "<" << this->getName() << "> is signed by <" << bureaucrat.getName() << ">" << RESET << std::endl;
	}
}

bool Form::checkFormSignedStatus(void) const
{

	if (this->getSigned())
		return true;
	return false;
}

bool Form::checkFormExecuteGrade(const Bureaucrat &executor) const
{
	try
	{
		if (this->getGradeToExecute() < executor.getGrade())
			throw GradeTooLowException();
	}
	catch (const GradeTooLowException &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
		return false;
	}
	return true;
}

void Form::setFormTarget(std::string target)
{
	this->_target = target;
}

std::string Form::getFormTarget() const
{
	return this->_target;
}

void Form::setSigned(bool sign)
{
	this->_signed = sign;
}

void Form::execute(const Bureaucrat &executor) const
{
	if (!this->checkFormSignedStatus())
		std::cout << MAGENTA << "<" << this->getName() << "> cannot be executed by <" << executor.getName() << "> because the form is not signed." << RESET << std::endl;
	else if (!this->checkFormExecuteGrade(executor))
		std::cout << MAGENTA << "<" << this->getName() << "> cannot be executed by <" << executor.getName() << "> because the executor does not have a high enough score." << RESET << std::endl;
	else
		executeForm();
}

std::ostream &operator<<(std::ostream &o, const Form &form)
{
	if (form.getSigned())
		o << BLUE << "Form <" << form.getName() << "> is signed." << RESET;
	else
		o << RED << "Form <" << form.getName() << "> is not signed." << RESET;
	return o;
}
