/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:59:38 by yeju              #+#    #+#             */
/*   Updated: 2022/04/03 18:50:36 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat a("a", 10);
	Bureaucrat b("b", 50);
	Bureaucrat c("c", 100);
	std::cout << std::endl;

	Form oneForm("one", 150, 150); //name, tosign, toexecute
	Form twoForm("two", 150, 90);
	Form threeForm("three", 90, 40);
	Form fourForm("four", 40, 5);
	Form fiveForm("five", 1, 1);
	std::cout << std::endl;

	std::cout << oneForm << std::endl;
	std::cout << twoForm << std::endl;
	std::cout << threeForm << std::endl;
	std::cout << fourForm << std::endl;
	std::cout << fiveForm << std::endl;
	std::cout << std::endl;

	std::cout << "--test beSigned() by b--" << std::endl;
	oneForm.beSigned(b);
	twoForm.beSigned(b);
	threeForm.beSigned(b);
	fourForm.beSigned(b);
	fiveForm.beSigned(b);
	std::cout << std::endl;

	std::cout << oneForm << std::endl;
	std::cout << twoForm << std::endl;
	std::cout << threeForm << std::endl;
	std::cout << fourForm << std::endl;
	std::cout << fiveForm << std::endl;
	std::cout << std::endl;

	std::cout << "--test beSigned() by a--" << std::endl;
	oneForm.beSigned(a);
	twoForm.beSigned(a);
	threeForm.beSigned(a);
	fourForm.beSigned(a);
	fiveForm.beSigned(a);
	std::cout << std::endl;

	std::cout << oneForm << std::endl;
	std::cout << twoForm << std::endl;
	std::cout << threeForm << std::endl;
	std::cout << fourForm << std::endl;
	std::cout << fiveForm << std::endl;
	std::cout << std::endl;

	std::cout << "--test signForm() of threeForm--" << std::endl;
	c.signForm(threeForm);
	b.signForm(threeForm);
	a.signForm(threeForm);
	std::cout << std::endl;

	std::cout << "--test signForm() of fourForm--" << std::endl;
	c.signForm(fourForm);
	b.signForm(fourForm);
	a.signForm(fourForm);
	std::cout << std::endl;

	return 0;
}