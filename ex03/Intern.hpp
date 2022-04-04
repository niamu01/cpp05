
#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	Intern();
	Intern(Intern const &rhs);
	~Intern();

	Intern &operator=(Intern const &rhs);

	Form *makeForm(std::string formName, std::string formTarget);
private:
	Form *createPresidentialPardon(std::string formTarget);
	Form *createRobotomyRequest(std::string formTarget);
	Form *createShrubberyCreation(std::string formTarget);
};

// typedef Form *(Intern::*createFormFunction)(std::string formTarget);

#endif
