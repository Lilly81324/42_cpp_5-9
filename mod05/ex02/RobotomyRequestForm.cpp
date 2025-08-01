/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 14:16:55 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/01 19:07:52 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm& subject);

RobotomyRequestForm::RobotomyRequestForm(void): \
AForm("Robotomy Request Form", 72, 45), target(DEF_TARGET)
{
	std::cout << "Default RobotomyRequestForm Constructor called:      ";
	std::cout << *this << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): \
AForm("Robotomy Request Form", 72, 45), target(target)
{
	std::cout << "Parameterized RobotomyRequestForm Constructor called: ";
	std::cout << *this << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): \
AForm(other.getName(), other.getSiGrade(), other.getExGrade()), target(other.getTarget())
{
	std::cout << "Copy RobotomyRequestForm Constructor called:          ";
	std::cout << *this << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << "RobotomyRequestForm Asignement operator called:       ";
	std::cout << "Setting Sign: " << this->getSign() << "->" << other.getSign() \
	<< ", Target: " << this->getTarget() << "->" << other.getTarget() << std::endl;
	if (this == &other)
		return (*this);
	this->is_signed = other.getSign();
	this->target = other.getTarget();
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor called on: ";
	std::cout << *this << std::endl;
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->target);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	(void)executor;
	std::cout << "Robotomizing " << this->getTarget() << std::endl;
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm& subject)
{
	out << \
	subject.getName() << \
	", Target: " << subject.getTarget() << \
	", Signed: " << subject.getSign() << \
	", Sign Grade: " << subject.getSiGrade() << \
	", Exec Grade: " << subject.getExGrade();
	return (out);
}