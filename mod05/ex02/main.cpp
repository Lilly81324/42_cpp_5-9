/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:04:24 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/04 18:36:00 by sikunne          ###   ########.fr       */
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
	std::cout << std::endl << "----===NORMAL DESTRUCTORS===----" << std::endl;
	ShrubberyCreationForm test("The infamous memory thief");
	Bureaucrat	boss("Da Booss", 1);
	Bureaucrat	chump("Lvl 1 Grunt", 150);
	std::cout << std::endl << "-------=======TESTS======-------" << std::endl;
	boss.signForm(test);
	boss.executeForm(test);
	std::cout << test << std::endl;
	std::cout <<  std::endl << "-----=====DESTRUCTORS=====------" << std::endl;
	return (0);
}
