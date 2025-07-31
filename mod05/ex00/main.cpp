/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:04:24 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/31 19:06:46 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
/**
 * Bigger then 0 values reduce the numeric value of the subjects grade
 */
void	increment_tests(Bureaucrat& subject, int value)
{
	std::cout << "----------" << std::endl;
		if (value > 0)
			subject.decrement();
		else
			subject.increment();
}

int main(void)
{
	Bureaucrat	defaulty;
	Bureaucrat	toolow("Invalid Ingrid", 0);
	Bureaucrat	toohigh("Invalid Idriz", 151);
	Bureaucrat	high("CEO Carly", 1);
	Bureaucrat	low("Low Larry", 150);
	Bureaucrat	average("Average Avery", 75);
	Bureaucrat	cloned(average);
	std::cout << "----------" << std::endl;
	defaulty = high;
	std::cout << "----------" << std::endl;
	high.increment();
	high.decrement();
	std::cout << "----------" << std::endl;
	low.decrement();
	low.increment();
	std::cout << "----------" << std::endl;
	average = defaulty = high;
	return (0);
}
