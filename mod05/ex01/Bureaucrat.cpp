/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:46:39 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/01 18:04:08 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include "Bureaucrat.hpp"

// Default Constructor
Bureaucrat::Bureaucrat(void): name(BU_DEF_NAME), grade(BU_DEF_GRADE)
{
	std::cout << "Default Bureaucrat Constructor called on " \
	<< this->name << " grade " <<this->grade << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name): name(name), grade(BU_DEF_GRADE)
{
	std::cout << "Parameterized Bureaucrat Constructor (name) called on " \
	<< this->name << " grade " <<this->grade << std::endl;
}

Bureaucrat::Bureaucrat(int grade): name(BU_DEF_NAME), grade(BU_DEF_GRADE)
{
	this->setGrade(grade);
	std::cout << "Parameterized Bureaucrat Constructor (grade) called";
	std::cout << " on " << this->name << " grade " <<this->grade << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): name(name), grade(BU_DEF_GRADE)
{
	this->setGrade(grade);
	std::cout << "Parameterized Bureaucrat Constructor (name, grade) called on " \
	<< this->name << " grade " <<this->grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name), grade(BU_DEF_GRADE)
{
	this->setGrade(other.grade);
	std::cout << "Copy Bureaucrat Constructor called on " \
	<< this->name << " grade " <<this->grade << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Bureaucrat Asignement Operator called on " \
	<< this->name << " grade " << this->getGrade() << "->";
	this->setGrade(other.getGrade());
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

void	Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->grade = grade;
}

/** 
 * Decrease Bureaucrats grade (5->4)
 */
void	Bureaucrat::increment(void)
{
	this->setGrade(this->getGrade() - 1);
	std::cout << "Incremented " << this->getName() << " to " << this->getGrade() << std::endl;
}

/** 
 * Increase Bureaucrats grade (5->6)
*/
void	Bureaucrat::decrement(void)
{
	this->setGrade(this->getGrade() + 1);
	std::cout << "Decremented " << this->getName() << " to " << this->getGrade() << std::endl;
}

bool	Bureaucrat::signForm(Form& subject)
{
	if (subject.getSign())
	{
		std::cout << this->getName() << " couldn't sign " << subject.getName() \
		<< " because it is already signed." << std::endl;
		return (false);
	}
	if (subject.beSigned(*this))
	{
		std::cout << this->getName() << " signed " << subject.getName() \
		<< " (Grades " << subject.getSiGrade() << " >= " << this->getGrade() << ")." << std::endl;
		return (true);
	}
	std::cout << this->getName() << " couldn't sign " << subject.getName() \
	<< " because Grade is too low (Grades " << this->getGrade() << " > " \
	<< subject.getSiGrade() << ")." << std::endl;;
	return (false);
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
	out << subject.getName() << ", bureaucrat grade  " << subject.getGrade() << "." << std::endl;
	return (out);
}
