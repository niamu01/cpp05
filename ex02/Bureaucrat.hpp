/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:34:22 by yeju              #+#    #+#             */
/*   Updated: 2022/04/03 21:57:54 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"

class Form;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const &rhs);
	~Bureaucrat();

	Bureaucrat &operator=(Bureaucrat const &rhs);

	std::string getName() const;
	int getGrade() const;

	void setGrade(int);

	void incrementGrade(int);
	void decrementGrade(int);

	void signForm(Form &form);

	void executeForm(Form const &form);

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return ("Grade is too high");
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return ("Grade is too low");
		}
	};
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif
