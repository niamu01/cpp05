/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:54:44 by yeju              #+#    #+#             */
/*   Updated: 2022/04/06 19:43:36 by yeju             ###   ########.fr       */
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
						return new ShrubberyCreationForm(formTarget);
						break;
					case 1:
						return new RobotomyRequestForm(formTarget);
						break;
					case 2:
						return new PresidentialPardonForm(formTarget);
						break;
				}
			}
		}
		throw Intern::noMaching();
	}
	catch (const Intern::noMaching &_throw)
	{
		std::cout << RED;
		std::cout << _throw.what() << std::endl;
		std::cout << RESET;
		return (NULL);
	}
}