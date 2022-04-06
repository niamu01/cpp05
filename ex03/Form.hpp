/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:21:46 by yeju              #+#    #+#             */
/*   Updated: 2022/04/06 19:22:32 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExecute;
	std::string _target;

public:
	Form();
	Form(std::string name, int gradeToSign, int gradeToExecute);
	Form(Form const &rhs);
	virtual ~Form();

	Form &operator=(Form const &rhs);

	std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void setSigned(bool sign);
	
	void beSigned(Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("Form: Grade is too high");
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("Form: Grade is too low");
		}
	};

	virtual void execute(Bureaucrat const &executor) const = 0;
	
	bool checkFormSignedStatus() const;
	bool checkFormExecuteGrade(Bureaucrat const &executor) const;

	void setFormTarget(std::string target);
	std::string getFormTarget() const;
	
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif
