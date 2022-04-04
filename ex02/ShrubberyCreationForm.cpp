/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:33:56 by yeju              #+#    #+#             */
/*   Updated: 2022/04/04 18:24:09 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("name_shrubbery", 145, 137)
{
	std::cout << "ShrubberyCreationForm: Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("name_shrubbery", 145, 137)
{
	std::cout << "ShrubberyCreationForm: Constructor called" << std::endl;
	this->setFormTarget(target);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm: Destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs) : Form(rhs.getName(), rhs.getGradeToSign(), rhs.getGradeToExecute())
{
	std::cout << "ShrubberyCreationForm: Copy constructor called" << std::endl;
	*this = rhs;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	std::cout << "ShrubberyCreationForm: assignation operator is called." << std::endl;
	this->setSigned(rhs.getSigned());
	this->setFormTarget(rhs.getFormTarget());
	return (*this);
}

void ShrubberyCreationForm::executeForm() const
{
	std::string fileName = this->getFormTarget() + "_shrubbery";
	std::ofstream fout(fileName);

 	std::string shrubbery =	"               ,@@@@@@@,\n"
                          	"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
                         	"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
                          	"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
                         	"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
                        	"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
                      	    "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
                      	    "       |o|        | |         | |\n"
                      	    "       |.|        | |         | |\n"
                     	    "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_";
	if (fout.fail())
	{
		std::cout << RED;
		std::cout << "FILE CREATE ERROR" << std::endl;
		std::cout << RESET;
		return ;
	}

	fout << shrubbery << std::endl;

	fout.close();
}