/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:46:39 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/05 15:53:03 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Default Constructor
Bureaucrat::Bureaucrat(void): name(BU_DEF_NAME), grade(BU_DEF_GRADE)
{
	std::cout << "Bureaucrat D-Constr.:             " \
	<< this->name << " grade " <<this->grade << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name): name(name), grade(BU_DEF_GRADE)
{
	std::cout << "Bureaucrat P-Constr.(name):       " \
	<< this->name << " grade " <<this->grade << std::endl;
}

Bureaucrat::Bureaucrat(int grade): name(BU_DEF_NAME), grade(BU_DEF_GRADE)
{
	this->setGrade(grade);
	std::cout << "Bureaucrat P-Constr.(grade):      ";
	std::cout << " on " << this->name << " grade " <<this->grade << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): name(name), grade(BU_DEF_GRADE)
{
	this->setGrade(grade);
	std::cout << "Bureaucrat P-Constr.(name, grade):" \
	<< this->name << " grade " <<this->grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name), grade(BU_DEF_GRADE)
{
	this->setGrade(other.grade);
	std::cout << "Bureaucrat C-Constr.:             " \
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

bool	Bureaucrat::signForm(AForm& subject) const
{
	if (subject.getSign())
	{
		std::cout << "Error: " << \
		this->getName() << " couldn't sign " << \
		subject.getName() << " because it is already signed." << std::endl;
		return (false);
	}
	try
	{
		subject.beSigned(*this);
	}
	catch (const AForm::GradeTooLowException& e)
	{
		std::cout << "Error: " << \
		this->getName() << " couldn't sign " << \
		subject.getName() << " because Grade is too low (Grades " << \
		this->getGrade() << " > " << \
		subject.getSiGrade() << ")." << std::endl;;
		return (false);
	}
	std::cout << \
	this->getName() << " signed " << \
	subject.getName() << " (Grades " << \
	subject.getSiGrade() << " >= " << \
	this->getGrade() << ")." << std::endl;
	return (true);
}

void Bureaucrat::executeForm(AForm const & form) const
{
	if (!form.getSign())
	{
		std::cerr << "Error: " << \
		form.getName() << " of " << \
		form.getTarget() << " is not signed, and cant be executed." << \
		std::endl;
		return ;
	}
	if (this->getGrade() > form.getExGrade())
	{
		std::cerr << "Error: " << this->getName() << \
		"s grade is too low to execute " << form.getName() << \
		". (" << this->getGrade() << \
		" > " << form.getExGrade()\
		<< ")" << std::endl;
		return ;
	}
	if (!form.execute(*this))
	{
		std::cout << "Error: " << \
		this->getName() << " failed executing " << \
		form.getName() << std::endl;
		return ;
	}
	return ;
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
