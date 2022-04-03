
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{

private:
	ShrubberyCreationForm();

public:
	ShrubberyCreationForm(std::string target);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const &rhs);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

	virtual void executeForm() const;
};

#endif // SHRUBBERYCREATIONFORM_HPP
