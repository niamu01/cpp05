/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:37:39 by yeju              #+#    #+#             */
/*   Updated: 2022/04/04 19:58:17 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern someRandomIntern;

	Form *form1 = someRandomIntern.makeForm("presidential pardon", "dog");
	Form *form2 = someRandomIntern.makeForm("robotomy request", "cat");
	Form *form3 = someRandomIntern.makeForm("shrubbery creation", "fish");
	Form *form4 = someRandomIntern.makeForm("shrubbery", "no");

	std::cout << YELLOW << "<" << form1->getName() << "> is created to target <" << form1->getFormTarget() << ">." << RESET << std::endl;
	std::cout << YELLOW << "<" << form2->getName() << "> is created to target <" << form2->getFormTarget() << ">." << RESET << std::endl;
	std::cout << YELLOW << "<" << form2->getName() << "> is created to target <" << form2->getFormTarget() << ">." << RESET << std::endl;

	delete form1;
	delete form2;
	delete form3;
	delete form4;
}
