#ifndef FORM_HPP
#define FORM_HPP
//#include <string>
#include "Bureaucrat.hpp"

class Form {

private:

	const std::string _name;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExecute;
	Form();

public:
	Form(std::string name, int gradeToSign, int gradeToExecute);
	~Form();
	Form(Form const & src);
	Form & operator=(Form const & rhs);

	std::string getName() const;
	bool getSignedResult() const;
	void setSignedResult(bool signedResult);
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(Bureaucrat & bureaucrat);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("<Form> Grade too high (smaller than 1).");
			}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return ("<Form> Grade too low (bigger than 150).");
		}
	};

};

std::ostream & operator<<(std::ostream & o, Form const & form);

#endif //FORM_HPP
