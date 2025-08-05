/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 14:16:55 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/04 18:05:25 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm& subject);

PresidentialPardonForm::PresidentialPardonForm(void): \
AForm("Presidential Pardon Form", 25, 5), target(DEF_TARGET)
{
	std::cout << "PresidentialPardonForm D-Constr:  ";
	std::cout << *this << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target): \
AForm("Presidential Pardon Form", 25, 5), target(target)
{
	std::cout << "PresidentialPardonForm P-Constr.: ";
	std::cout << *this << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): \
AForm("Presidential Pardon Form", 25, 5), target(other.getTarget())
{
	std::cout << "PresidentialPardonForm C-Constr.: ";
	std::cout << *this << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	std::cout << "PresidentialPardonForm Asignement operator called: ";
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

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor:";
	std::cout << *this << std::endl;
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->target);
}

bool	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSign())
		return false;
	if (executor.getGrade() > this->getExGrade())
		return false;
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	return true;
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm& subject)
{
	out << \
	subject.getName() << \
	", Target: " << subject.getTarget() << \
	", Signed: " << subject.getSign() << \
	", Sign Grade: " << subject.getSiGrade() << \
	", Exec Grade: " << subject.getExGrade();
	return (out);
}