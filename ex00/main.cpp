/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:58:54 by yeju              #+#    #+#             */
/*   Updated: 2022/06/01 17:00:39 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat High("High", 0);
	Bureaucrat Low("Low", 151);
	std::cout << std::endl;

	Bureaucrat a("nameA", 100); //A,100 생성
	std::cout << std::endl;

	Bureaucrat b (a); //복사생성자
	std::cout << std::endl;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << std::endl;

	a.incrementGrade(50);
	std::cout << "increment 50: " << a << std::endl; //100-50 = 50
	std::cout << std::endl;

	a.decrementGrade(100);
	std::cout << "decrement 100: " << a << std::endl; //50+100 = 150
	std::cout << std::endl;

	a.incrementGrade(150);
	std::cout << "increment 150: " << a << std::endl; //150-150 = 0 (x)
	std::cout << std::endl;

	a.decrementGrade(1);
	std::cout << "decrement 1: " << a << std::endl; //150+1 = 151 (x)
	std::cout << std::endl;
	
	a.incrementGrade(50);
	std::cout << "increment 50: " << a << std::endl; //150-50 = 100
	std::cout << std::endl;

	return 0;
}