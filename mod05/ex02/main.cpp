/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:04:24 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/05 14:26:37 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main(void)
{
	std::cout << "---===INVALID CONSTRUCTORS===---" << std::endl;
	// AForm inval;
	// AForm("Invalid Forn", 69, 88);
	std::cout << std::endl << "----===NORMAL DESTRUCTORS===----" << std::endl;
	RobotomyRequestForm rform1("Fleshy Human 1");
	RobotomyRequestForm rform2;
	RobotomyRequestForm rform3(rform1);
	ShrubberyCreationForm sform("Central_park");
	PresidentialPardonForm pform("Robin Hood");
	Bureaucrat	boss("Da Booss", 1);
	Bureaucrat	chump("Lvl 1 Grunt", 150);
	std::cout << std::endl << "-------=======TESTS======-------" << std::endl;
	std::cout << rform1 << std::endl;
	std::cout << rform2 << std::endl;
	std::cout << rform3 << std::endl;
	std::cout << sform << std::endl;
	std::cout << pform << std::endl << std::endl;
	chump.signForm(rform1);
	chump.executeForm(rform1);
	boss.signForm(rform1);
	chump.executeForm(rform1);
	boss.executeForm(rform1);
	std::cout << std::endl << rform1 << std::endl;
	std::cout << rform3 << std::endl;
	rform3 = rform1;
	std::cout << rform3 << std::endl << std::endl;
	boss.signForm(sform);
	boss.executeForm(sform);
	boss.signForm(pform);
	boss.executeForm(pform);
	std::cout <<  std::endl << "-----=====DESTRUCTORS=====------" << std::endl;
	return (0);
}
