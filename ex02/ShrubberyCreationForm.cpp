/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:44:29 by qli               #+#    #+#             */
/*   Updated: 2022/04/03 17:14:02 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#include "Form.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("shrubbery creation", 145, 137){
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
		Form("shrubbery creation", 145, 137)
{
	this->setFormTarget(target);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs) : Form(rhs.getName(), rhs.getGradeToSign(), rhs.getGradeToExecute()){
	std::cout << YELLOW << "<ShrubberyCreationForm> copy constructor is called." << RESET << std::endl;
	*this = rhs;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
	if (this != &rhs)
	{
		this->setSignedResult(rhs.getSignedResult());
		this->setFormTarget(rhs.getFormTarget());
	}
	return *this;
}

void ShrubberyCreationForm::executeForm() const {
	std::ifstream inFile;
	inFile.open("ascii.txt");
	if (!inFile)
		std::cout << RED << "Open file error." << RESET << std::endl;

	std::string fileName = this->getFormTarget() + "_shrubbery";

	std::ofstream outFile(fileName.c_str());
	if (!outFile)
		std::cout << RED << "Create file error." << RESET << std::endl;

	std::string line;

	while(getline(inFile, line))
		outFile << line << std::endl;
	outFile.close();
	inFile.close();
}