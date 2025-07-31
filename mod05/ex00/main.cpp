/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:04:24 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/31 18:51:36 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
/**
 * Bigger then 0 values reduce the numeric value of the subjects grade
 */
void	increment_tests(Bureaucrat& subject, int value)
{
	std::cout << "----------" << std::endl;
	while (value != 0)
	{
		if (value > 0)
		{
			subject.decrement();
			value--;
		}
		else
		{
			subject.increment();
			value++;
		}
	}
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
	Bureaucrat	copied;
	
	copied = average;
	
	increment_tests(high, -2);
	increment_tests(high, 2);
	increment_tests(low, 2);
	increment_tests(low, -2);
	
	average = defaulty = high;
	return (0);
}
