/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:04:24 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/01 18:12:15 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	try_signing(Form &form, Bureaucrat& writer)
{
	try
	{
		writer.signForm(form);
	}
	catch (const std::exception &ex)
	{
		std::cerr << ex.what() << std::endl;
	}
}

void	giveFormAround(Form &form, Bureaucrat& first, Bureaucrat& second, \
						Bureaucrat& third, Bureaucrat& fourth)
{
	std::cout << "Testing: [" << form.getName() << ", " << form.getSiGrade() << "]" << std::endl;
	try_signing(form, first);
	try_signing(form, second);
	try_signing(form, third);
	try_signing(form, fourth);
	std::cout << std::endl;
}

int main(void)
{
	std::cout << "---===INVALID CONSTRUCTORS===---" << std::endl;
	try 
	{
		Form invalid("Invalid Form", 0, 1);
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	try 
	{
		Form invalid("Invalid Form", 151, 1);
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	try 
	{
		Form invalid("Invalid Form", 1, 0);
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	try 
	{
		Form invalid("Invalid Form", 1, 151);
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	std::cout << std::endl << "----===NORMAL DESTRUCTORS===----" << std::endl;
	Bureaucrat	bu_default;
	Bureaucrat	pleb("Worker William ", 130);
	Bureaucrat	middle("Manager Manfred", 70);
	Bureaucrat	boss("CEO Charlotte  ", 1);
	std::cout << std::endl;
	Form	defaul;
	Form	easy("Survey Form", 140, 140);
	Form	hard("Firing Form", 75, 75);
	Form	hardest("Ultima Form", 1, 1);
	std::cout << std::endl << "-------=======TESTS======-------" << std::endl;
	giveFormAround(defaul, bu_default, pleb, middle, boss);
	giveFormAround(easy, bu_default, pleb, middle, boss);
	giveFormAround(hard, bu_default, pleb, middle, boss);
	giveFormAround(hardest, bu_default, pleb, middle, boss);
	std::cout << "-----=====DESTRUCTORS=====------" << std::endl;
	return (0);
}
