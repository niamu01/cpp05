/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 21:20:03 by yeju              #+#    #+#             */
/*   Updated: 2022/04/06 19:02:20 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	std::cout << YELLOW;
	std::cout << "--make two Bureaucrat--" << std::endl;
	std::cout << RESET;

		Bureaucrat highGrade("highGrade", 1);
		Bureaucrat lowGrade("lowGrade", 150);
		std::cout << std::endl;

	std::cout << YELLOW;
	std::cout << "--make ShrubberyCreationForm--" << std::endl;
	std::cout << RESET;
	
		ShrubberyCreationForm shrubbery("home");
		std::cout << std::endl;

		std::cout << "--check ShrubberyCreation signed--" << std::endl;
		std::cout << shrubbery << std::endl;
		std::cout << std::endl;

		std::cout << "--test execute to ShrubberyCreationForm--" << std::endl;
		highGrade.executeForm(shrubbery);
		lowGrade.executeForm(shrubbery);
		std::cout << std::endl;
		
		std::cout << "--test executor can execute ShrubberyCreationForm--" << std::endl;
		shrubbery.execute(lowGrade);
		shrubbery.execute(highGrade);
		std::cout << std::endl;

		std::cout << "--sign the form--" << std::endl;
		highGrade.signForm(shrubbery);
		lowGrade.signForm(shrubbery);
		std::cout << std::endl;

		std::cout << "--test execute to ShrubberyCreationForm again--" << std::endl;
		highGrade.executeForm(shrubbery);
		std::cout << std::endl;
		lowGrade.executeForm(shrubbery);
		std::cout << std::endl;

		std::cout << "--test executor can execute ShrubberyCreationForm again--" << std::endl;
		shrubbery.execute(lowGrade);
		std::cout << std::endl;
		shrubbery.execute(highGrade);
		std::cout << std::endl;

	std::cout << YELLOW;
	std::cout << "--make RobotomyRequestForm--" << std::endl;
	std::cout << RESET;
	
		RobotomyRequestForm robotomy("robotomy");
		std::cout << std::endl;

		std::cout << "--check robotomyCreation signed--" << std::endl;
		std::cout << robotomy << std::endl;
		std::cout << std::endl;

		std::cout << "--test execute to RobotomyRequestForm--" << std::endl;
		highGrade.executeForm(robotomy);
		lowGrade.executeForm(robotomy);
		std::cout << std::endl;
		
		std::cout << "--test executor can execute RobotomyRequestForm--" << std::endl;
		robotomy.execute(lowGrade);
		robotomy.execute(highGrade);
		std::cout << std::endl;

		std::cout << "--sign the form--" << std::endl;
		highGrade.signForm(robotomy);
		lowGrade.signForm(robotomy);
		std::cout << std::endl;

		std::cout << "--test execute to RobotomyRequestForm again--" << std::endl;
		highGrade.executeForm(robotomy);
		std::cout << std::endl;
		lowGrade.executeForm(robotomy);
		std::cout << std::endl;

		std::cout << "--test executor can execute RobotomyRequestForm again--" << std::endl;
		robotomy.execute(lowGrade);
		std::cout << std::endl;
		robotomy.execute(highGrade);
		std::cout << std::endl;

	std::cout << YELLOW;
	std::cout << "--make PresidentialPardonForm--" << std::endl;
	std::cout << RESET;
	
		PresidentialPardonForm presidential("presidential");
		std::cout << std::endl;

		std::cout << "--check presidentialCreation signed--" << std::endl;
		std::cout << presidential << std::endl;
		std::cout << std::endl;

		std::cout << "--test execute to PresidentialPardonForm--" << std::endl;
		highGrade.executeForm(presidential);
		lowGrade.executeForm(presidential);
		std::cout << std::endl;
		
		std::cout << "--test executor can execute PresidentialPardonForm--" << std::endl;
		presidential.execute(lowGrade);
		presidential.execute(highGrade);
		std::cout << std::endl;

		std::cout << "--sign the form--" << std::endl;
		highGrade.signForm(presidential);
		lowGrade.signForm(presidential);
		std::cout << std::endl;

		std::cout << "--test execute to PresidentialPardonForm again--" << std::endl;
		highGrade.executeForm(presidential);
		std::cout << std::endl;
		lowGrade.executeForm(presidential);
		std::cout << std::endl;

		std::cout << "--test executor can execute PresidentialPardonForm again--" << std::endl;
		presidential.execute(lowGrade);
		std::cout << std::endl;
		presidential.execute(highGrade);
		std::cout << std::endl;

	return 0;
}
