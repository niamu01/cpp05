/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:49:32 by yeju              #+#    #+#             */
/*   Updated: 2022/04/06 19:41:45 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Form.hpp"

class Intern
{
public:
	Intern();
	Intern(Intern const &rhs);
	~Intern();

	Intern &operator=(Intern const &rhs);

	Form *makeForm(std::string formName, std::string formTarget);

	class noMaching : public std::exception
	{
   	public:
    	virtual const char* what() const throw()
		{
			return ("nothing matched with formName");
		}
  	};
	  
private:
	Form *createShrubberyCreation(std::string formTarget);
	Form *createRobotomyRequest(std::string formTarget);
	Form *createPresidentialPardon(std::string formTarget);
};

// typedef Form *(Intern::*createFormFunction)(std::string formTarget);

#endif
