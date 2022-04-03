/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:59:36 by yeju              #+#    #+#             */
/*   Updated: 2022/04/03 17:15:26 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
private:
	const std::string _name;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExecute;
	
public:
	Form();
	Form(std::string name, int gradeToSign, int gradeToExecute);
	Form(Form const &rhs);
	~Form();
	
	Form &operator=(Form const &rhs);

	std::string getName() const;
	bool getSignedResult() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	
	void setSignedResult(bool signedResult);

	void beSigned(Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return ("Form: Grade is too high");
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return ("Form: Grade is too low");
		}
	};
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif
