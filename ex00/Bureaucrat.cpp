/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 12:05:59 by yeju              #+#    #+#             */
/*   Updated: 2022/04/03 13:15:09 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdexcept>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():  _name(""), _grade(Bureaucrat::lowestGrade) //생성자를 두는게 맞는지...
{
	std::cout << "Bureaucrat: Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat: constructor called" << std::endl;
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (const Bureaucrat::GradeTooLowException &_throw)
	{
		std::cout << YELLOW << _throw.what() << RESET << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &_throw)
	{
		std::cout << YELLOW << _throw.what() << RESET << std::endl;
	}
	std::cout << GREEN << "* Bureaucrat <" << this->getName() << "> is born. *" << RESET << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat: Destructor called" << std::endl;
	std::cout << CYAN << "* Bureaucrat <" << this->getName() << "> is destroyed. *" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs) : _name(rhs.getName()), _grade(rhs.getGrade())
{
	std::cout << "Bureaucrat copy constructor called." << std::endl;
	*this = rhs;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	std::cout << YELLOW << "Bureaucrat: Copy constructor called" << RESET << std::endl;
	if (this != &rhs)
	{
		this->_grade = rhs.getGrade();
	}
	return *this;
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

void Bureaucrat::setGrade(int grade)
{
	this->_grade = grade;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade(int amount)
{
	try
	{
		if (this->getGrade() - amount < 1)
		{
			throw Bureaucrat::GradeTooHighException();
		}
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << RED << e.what() << std::endl << RESET;
		return;
	}
	this->setGrade(this->getGrade() - amount);
}

void Bureaucrat::decrementGrade(int amount)
{
	try
	{
		if (this->getGrade() + amount > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << RED << e.what() << std::endl
				  << RESET;
		return;
	}
	this->setGrade(this->getGrade() + amount);
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << BLUE << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << RESET;
	return out;
}
