/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:04:24 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/01 19:07:09 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main(void)
{
	std::cout << "---===INVALID CONSTRUCTORS===---" << std::endl;
	std::cout << std::endl << "----===NORMAL DESTRUCTORS===----" << std::endl;
	RobotomyRequestForm test;
	Bureaucrat	boss("Da Booss", 1);
	std::cout << std::endl << "-------=======TESTS======-------" << std::endl;
	test.execute(boss);
	std::cout << test << std::endl;
	std::cout << "-----=====DESTRUCTORS=====------" << std::endl;
	return (0);
}
