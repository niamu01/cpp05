/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:54:44 by yeju              #+#    #+#             */
/*   Updated: 2022/04/04 21:13:25 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern: Default constructor called" << std::endl;
}

Intern::Intern(const Intern &rhs)
{
	std::cout << "Intern: Copy constructor called" << std::endl;
	*this = rhs;
}

Intern::~Intern()
{
	std::cout << "Intern: Destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &rhs)
{
	std::cout << "Intern: assignation operator is called" << std::endl;
	(void)rhs;
	return (*this);
}

void noMaching()
{
	std::cout << RED;
	std::cout << "Intern cannot creates " << formTarget << formName << std::endl;
	std::cout << RESET;
}

Form *Intern::makeForm(std::string formName, std::string formTarget)
{
	std::string input[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	
	try
	{
		for (int i = 0; i < 3; i++)
		{
			if (formName == input[i])
			{
				std::cout << YELLOW;
				std::cout << "Intern creates " << formName << std::endl;
				std::cout << RESET;
				switch (i)
				{
					case 0:
						return new ShrubberyCreationForm(formName);
						break;
					case 1:
						return new RobotomyRequestForm(formName);
						break;
					case 2:
						return new PresidentialPardonForm(formName);
						break;
				}
			}
		}
		throw noMaching();
	}
	catch (std::exception *_throw)
	{
		std::cout << RED;
		std::cout << "Intern cannot creates " << formName << formTarget << std::endl;
		std::cout << RESET;
	}
}