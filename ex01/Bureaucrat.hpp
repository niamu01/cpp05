/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 12:05:59 by yeju              #+#    #+#             */
/*   Updated: 2022/04/06 18:33:42 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

# define RESET "\e[0m"
# define RED "\e[31m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define CYAN "\e[36m"

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
	
	void setGrade(int grade);
	
	void incrementGrade(int amount);
	void decrementGrade(int amount);

	void signForm(Form &form);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("Grade is too high");
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("Grade is too low");
		}
	};
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif