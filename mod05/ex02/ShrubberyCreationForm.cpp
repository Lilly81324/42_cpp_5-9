/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 14:16:55 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/04 18:05:25 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm& subject);

ShrubberyCreationForm::ShrubberyCreationForm(void): \
AForm("Shrubbery Creation Form", 145, 137), target(DEF_TARGET)
{
	std::cout << "Default ShrubberyCreationForm Constructor called:      ";
	std::cout << *this << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): \
AForm("Shrubbery Creation Form", 145, 137), target(target)
{
	std::cout << "Parameterized ShrubberyCreationForm Constructor called: ";
	std::cout << *this << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): \
AForm("Shrubbery Creation Form", 145, 137), target(other.getTarget())
{
	std::cout << "Copy ShrubberyCreationForm Constructor called:          ";
	std::cout << *this << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "ShrubberyCreationForm Asignement operator called: ";
	std::cout << "Setting Sign: " << \
	this->getSign() << "->" << \
	other.getSign() << ", Target: " << \
	this->getTarget() << "->" << \
	other.getTarget() << std::endl;
	if (this == &other)
		return (*this);
	this->is_signed = other.getSign();
	this->target = other.getTarget();
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor called on: ";
	std::cout << *this << std::endl;
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->target);
}

bool	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSign())
	{
		std::cerr << "Error: " << \
		this->getName() << " of " << \
		this->getTarget() << " is not signed, and cant be executed." << \
		std::endl;
		return false;
	}
	if (executor.getGrade() > this->getExGrade())
	{
		std::cerr << "Error: " << executor.getName() << \
		"s grade is too low to execute " << this->getName() << \
		". (" << executor.getGrade() << \
		" > " << this->getExGrade()\
		<< ")" << std::endl;
		return false;
	}
	std::cout << "I am a shrub, not a bush!" << std::endl;
	return true;
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm& subject)
{
	out << \
	subject.getName() << \
	", Target: " << subject.getTarget() << \
	", Signed: " << subject.getSign() << \
	", Sign Grade: " << subject.getSiGrade() << \
	", Exec Grade: " << subject.getExGrade();
	return (out);
}