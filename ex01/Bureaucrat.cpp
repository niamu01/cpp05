/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 12:05:59 by yeju              #+#    #+#             */
/*   Updated: 2022/04/03 22:06:46 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(150)
{
	std::cout << "Bureaucrat: Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat: Constructor called" << std::endl;
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (const Bureaucrat::GradeTooHighException &_throw)
	{
		std::cout << YELLOW;
		std::cout << _throw.what() << std::endl;
		std::cout << RESET;
		return ;
	}
	catch (const Bureaucrat::GradeTooLowException &_throw)
	{
		std::cout << YELLOW;
		std::cout << _throw.what() << std::endl;
		std::cout << RESET;
		return ;
	}
	std::cout << CYAN;
	std::cout << "Bureaucrat: " << this->getName() << " is created by Constructor" << std::endl;
	std::cout << RESET;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat: Destructor called" << std::endl;
	std::cout << CYAN;
	std::cout << "Bureaucrat: " << this->getName() << " is destroyed by Destructor" << std::endl;
	std::cout << RESET;
}

Bureaucrat::Bureaucrat(Bureaucrat const &rhs) : _name(rhs.getName()), _grade(rhs.getGrade())
{
	std::cout << "Bureaucrat: Copy constructor called" << std::endl;
	*this = rhs;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	std::cout << "Bureaucrat: Assignation operator called" << std::endl;
	this->_grade = rhs.getGrade();
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

void Bureaucrat::setGrade(int grade)
{
	this->_grade = grade;
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade(int amount)
{
	try
	{
		if (this->getGrade() - amount < 0)
			throw Bureaucrat::GradeTooHighException();
		else if (this->getGrade() - amount > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (const Bureaucrat::GradeTooHighException &_throw)
	{
		std::cout << YELLOW;
		std::cout << _throw.what() << std::endl;
		std::cout << RESET;
		return ;
	}
	catch (const Bureaucrat::GradeTooLowException &_throw)
	{
		std::cout << YELLOW;
		std::cout << _throw.what() << std::endl;
		std::cout << RESET;
		return ;
	}
	this->setGrade(this->getGrade() - amount);
}

void Bureaucrat::decrementGrade(int amount)
{
	try
	{
		if (this->getGrade() + amount > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (this->getGrade() + amount < 0)
			throw Bureaucrat::GradeTooHighException();
	}
	catch (const Bureaucrat::GradeTooLowException &_throw)
	{
		std::cout << YELLOW;
		std::cout << _throw.what() << std::endl;
		std::cout << RESET;
		return ;
	}
	catch (const Bureaucrat::GradeTooHighException &_throw)
	{
		std::cout << YELLOW;
		std::cout << _throw.what() << std::endl;
		std::cout << RESET;
		return ;
	}
	this->setGrade(this->getGrade() + amount);
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << RED;
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	out << RESET;
	return (out);
}

void Bureaucrat::signForm(Form &form)
{
	if (form.getGradeToSign() >= this->getGrade())
	{
		form.setSigned(true);
		std::cout << GREEN;
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
		std::cout << RESET;
	}
	else
	{
		std::cout << RED;
		std::cout << this->getName() << " couldn’t sign " << form.getName() << " because <the bureaucrat's grade is lower than the form's grade to sign>" << std::endl;
		std::cout << RESET;
	}
}
