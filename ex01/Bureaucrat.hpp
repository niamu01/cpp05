/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 12:05:59 by yeju              #+#    #+#             */
/*   Updated: 2022/04/03 13:23:40 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

# define RESET "\e[0m"
# define RED "\e[31m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define BLUE "\e[34m"
# define PURPLE "\e[35m" //MAGENTA
# define CYAN "\e[36m"

class Form;

class Bureaucrat {

private:
	const std::string _name;
	int	_grade;
	Bureaucrat();

public:
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(Bureaucrat const & src);
	Bureaucrat & operator=(Bureaucrat const & rhs);

	std::string getName() const;
	int	getGrade() const;
	void setGrade(int);
	void incrementGrade(int);
	void decrementGrade(int);

	void signForm(Form & form);

	class GradeTooHighException : public std::exception
	{
	public:
		const char * what () const throw ()
		{
			return ("Grade is too high (smaller than 1).");
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char * what () const throw ()
		{
			return ("Grade is too low (bigger than 150).");
		}
	};

};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & i);

#endif