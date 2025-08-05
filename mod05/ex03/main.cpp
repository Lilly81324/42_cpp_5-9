/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:04:24 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/05 16:12:56 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

void	test(const Intern &inter, const Bureaucrat &buro, const std::string &type, const std::string &target)
{
	AForm *ptr;

	std::cout << "Testing [" << type << "] form creation for [" << target << "]." << std::endl;
	ptr = inter.makeForm(type, target);
	if (!ptr)
	{
		std::cout << "Function returned NULL pointer" << std::endl << std::endl;
		return ;
	}
	std::cout << *ptr << std::endl;
	buro.signForm(*ptr);
	buro.executeForm(*ptr);
	delete (ptr);
	std::cout << std::endl;
}

int main(void)
{
	std::cout << "---===INVALID CONSTRUCTORS===---" << std::endl;

	std::cout << std::endl << "----===NORMAL DESTRUCTORS===----" << std::endl;
	Intern peter;
	Bureaucrat john(1);
	std::cout << std::endl << "-------=======TESTS======-------" << std::endl;
	test(peter, john, "robotomy request", "Bender");
	test(peter, john, "SHRUBBERYCREATION", "My hedge");
	test(peter, john, "pReSidEn tIaLP aRdoN", "some criminal");
	test(peter, john, "Invalid Form", "some target");
	test(peter, john, "", "");
	std::cout <<  std::endl << "-----=====DESTRUCTORS=====------" << std::endl;
	return (0);
}
