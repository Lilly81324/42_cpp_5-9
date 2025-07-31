/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:46:39 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/31 18:54:39 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Default Constructor
Bureaucrat::Bureaucrat(void): name(DEF_NAME), grade(DEF_GRADE)
{
	std::cout << "Default Bureaucrat Constructor called on " \
	<< this->name << " grade " <<this->grade << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name): name(name), grade(DEF_GRADE)
{
	std::cout << "Parameterized Bureaucrat Constructor (name) called on " \
	<< this->name << " grade " <<this->grade << std::endl;
}

Bureaucrat::Bureaucrat(int grade): name(DEF_NAME), grade(DEF_GRADE)
{
	if (!this->setGrade(grade))
		return ;
	std::cout << "Parameterized Bureaucrat Constructor (grade) called";
	std::cout << " on " << this->name << " grade " <<this->grade << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): name(name), grade(DEF_GRADE)
{
	if (!this->setGrade(grade))
		return ;
	std::cout << "Parameterized Bureaucrat Constructor (name, grade) called on " \
	<< this->name << " grade " <<this->grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name), grade(DEF_GRADE)
{
	if (!this->setGrade(other.grade))
		return ;
	std::cout << "Copy Bureaucrat Constructor called on " \
	<< this->name << " grade " <<this->grade << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Bureaucrat Asignement Operator called on " \
	<< this->name << " grade " << this->getGrade() << "->";
	if (!this->setGrade(other.getGrade()))
	{
		return (*this);
	}
	std::cout << this->getGrade() << std::endl;
	return (*this);
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor called on " \
	<< this->name << " grade " <<this->grade << std::endl;
}

std::string	Bureaucrat::getName(void) const
{
	return (this->name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

int	Bureaucrat::setGrade(int grade)
{
	try
	{
		if (grade < 1)
			throw (Bureaucrat::GradeTooHighException());
		else if (grade > 150)
			throw (Bureaucrat::GradeTooLowException());
	}
	catch(const Bureaucrat::GradeTooHighException& ex)
	{
		std::cerr << ex.what() << std::endl;
		return (0);
	}
	catch(const Bureaucrat::GradeTooLowException& ex)
	{
		std::cerr << ex.what() << std::endl;
		return (0);
	}
	this->grade = grade;
	return (1);
}

/** 
 * Decrease Bureaucrats grade (5->4)
 */
void	Bureaucrat::increment(void)
{
	if (this->setGrade(this->getGrade() - 1))
		std::cout << "Incremented " << this->getName() << " to " << this->getGrade() << std::endl;
}

/** 
 * Increase Bureaucrats grade (5->6)
*/
void	Bureaucrat::decrement(void)
{
	if (this->setGrade(this->getGrade() + 1))
		std::cout << "Decremented " << this->getName() << " to " << this->getGrade() << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw ()
{
	return ("Error: Grade is too high (Less then 1)");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw ()
{
	return ("Error: Grade is too low (Bigger then 150)");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat& subject)
{
	out << subject.getName() << " has a grade of " << subject.getGrade() << std::endl;
	return (out);
}
