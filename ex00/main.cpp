#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat tooHigh("tooHigh", 0);
	Bureaucrat tooLow("tooLow", 160);

	// test grade change (within range)
	std::cout << "----" << std::endl;
	Bureaucrat name("name", 100);
	std::cout << name << std::endl;
	name.incrementGrade(90);
	std::cout << name << std::endl;
	name.decrementGrade(90);
	std::cout << name << std::endl;

	// test grade change (out of range)
	std::cout << "----" << std::endl;
	name.incrementGrade(150);
	std::cout << name << std::endl;
	name.decrementGrade(150);
	std::cout << name << std::endl;

	// test copy & assignation operator
	std::cout << "----" << std::endl;
	Bureaucrat copy = Bureaucrat(tooHigh);
	std::cout << copy << std::endl;

	// objects are destructed automatically
	std::cout << "----" << std::endl;

	return 0;
}