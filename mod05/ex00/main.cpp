/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:04:24 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/01 18:19:36 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
/**
 * Try to increment Bureaucrat
 */
static void	static_inc(Bureaucrat& subject)
{
	std::cout << std::endl;
	try
	{
		subject.increment();
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
}

/**
 * Try to decrement Bureaucrat
 */
static void	static_dec(Bureaucrat& subject)
{
	std::cout << std::endl;
	try
	{
		subject.decrement();
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
}

int main(void)
{
	std::cout << "---===INVALID CONSTRUCTORS===---" << std::endl;
	try
	{
		Bureaucrat	invalid("Invalid Ingrid", 0);
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	try
	{
		Bureaucrat	invalid("Invalid Ingrid", 151);
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	std::cout << std::endl << "----===NORMAL DESTRUCTORS===----" << std::endl;
	Bureaucrat	defaulty;
	Bureaucrat	high("CEO Carly", 1);
	Bureaucrat	low("Low Larry", 150);
	Bureaucrat	average("Average Avery", 75);
	Bureaucrat	cloned(average);
	std::cout << std::endl << "-------=======TESTS======-------" << std::endl;
	static_inc(high);
	static_dec(high);
	static_dec(low);
	static_inc(low);
	std::cout << std::endl;
	average = defaulty = high;
	std::cout << "-----=====DESTRUCTORS=====------" << std::endl;
	return (0);
}
