/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:33:56 by yeju              #+#    #+#             */
/*   Updated: 2022/04/06 19:27:14 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("Form_shrubbery", 145, 137)
{
	std::cout << "ShrubberyCreationForm: Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form(target, 145, 137)
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

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
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
	{
		std::ifstream fin;
		std::string fileName = this->getFormTarget() + "_shrubbery";
		std::ofstream fout(fileName.c_str());

		fin.open("ascii.txt");

		if (fin.fail())
		{
			std::cout << RED;
			std::cout << "FILE OPEN ERROR" << std::endl;
			std::cout << RESET;
			return ;
		}
		if (fout.fail())
		{
			std::cout << RED;
			std::cout << "Create file error." << std::endl;
			std::cout << RESET;
			return ;
		}

		std::string word;
		while (std::getline(fin, word))
			fout << word << std::endl;
		fout << std::endl;

		fout.close();
		fin.close();
	}
}