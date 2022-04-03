#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat High("High", 0);
	Bureaucrat Low("Low", 151);
	std::cout << std::endl;

	Bureaucrat a("nameA", 100);
	std::cout << std::endl;

	Bureaucrat b (a);
	std::cout << std::endl;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << std::endl;

	a.incrementGrade(50);
	std::cout << a << std::endl;
	std::cout << std::endl;

	a.decrementGrade(100);
	std::cout << a << std::endl;
	std::cout << std::endl;

	a.incrementGrade(150);
	std::cout << a << std::endl;
	std::cout << std::endl;

	a.decrementGrade(150);
	std::cout << a << std::endl;
	std::cout << std::endl;
	
	a.incrementGrade(50);
	std::cout << a << std::endl;
	std::cout << std::endl;

	return 0;
}