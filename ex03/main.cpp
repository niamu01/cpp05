/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:37:39 by yeju              #+#    #+#             */
/*   Updated: 2022/04/06 19:46:50 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern someRandomIntern;
	std::cout << std::endl;

	Form *rrf1 = someRandomIntern.makeForm("shrubbery creation", "formName1");
	std::cout << std::endl;
	Form *rrf2 = someRandomIntern.makeForm("robotomy request", "formName2");
	std::cout << std::endl;
	Form *rrf3 = someRandomIntern.makeForm("presidential pardon", "formName3");
	std::cout << std::endl;
	Form *rrf4 = someRandomIntern.makeForm("shrubbery request", "formName4");
	std::cout << std::endl;
	
	delete rrf1;
	delete rrf2;
	delete rrf3;
	delete rrf4;
}
