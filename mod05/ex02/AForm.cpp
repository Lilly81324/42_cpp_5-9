/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 14:16:55 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/01 18:14:19 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void): \
name(FO_DEF_NAME), is_signed(FO_DEF_SIGN), sign_grade(FO_DEF_SIGN_GRADE), exec_grade(FO_DEF_EX_GRADE)
{
	std::cout << "Default AForm Constructor called:       ";
	std::cout << *this << std::endl;
}

AForm::AForm(const std::string name, const int sign_g, const int exec_g): \
name(name), is_signed(FO_DEF_SIGN), sign_grade(sign_g), exec_grade(exec_g)
{
	if (sign_g < 1)
		throw (AForm::GradeTooHighException());
	else if (sign_g > 150)
		throw (AForm::GradeTooLowException());
	if (exec_g < 1)
		throw (AForm::GradeTooHighException());
	else if (exec_g > 150)
		throw (AForm::GradeTooLowException());
	std::cout << "Parameterized AForm Constructor called: ";
	std::cout << *this << std::endl;
}

AForm::AForm(const AForm& other): \
name(other.getName()), is_signed(other.getSign()), \
sign_grade(other.getSiGrade()), exec_grade(other.getExGrade())
{
	std::cout << "Copy AForm Constructor created:        ";
	std::cout << *this << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	std::cout << "AForm Asignement operator called:       ";
	std::cout << "Setting " << this->getSign() << " to " << other.getSign() << std::endl;
	if (this == &other)
		return (*this);
	this->is_signed = other.getSign();
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm Destructor called on: ";
	std::cout << *this << std::endl;
}

std::string	AForm::getName(void) const
{
	return (this->name);
}

bool		AForm::getSign(void) const
{
	return (this->is_signed);
}

int			AForm::getSiGrade(void) const
{
	return (this->sign_grade);
}

int			AForm::getExGrade(void) const
{
	return (this->exec_grade);
}

bool	AForm::beSigned(const Bureaucrat& signer)
{
	if (this->is_signed)
		return (false);
	if (signer.getGrade() > this->getSiGrade())
		throw (AForm::GradeTooLowException());
	this->is_signed = true;
	return (true);
}

const char *AForm::GradeTooHighException::what(void) const throw ()
{
	return ("Error: Grade too high");
}

const char *AForm::GradeTooLowException::what(void) const throw ()
{
	return ("Error: Grade too low");
}

std::ostream &operator<<(std::ostream &out, const AForm& subject)
{
	out << subject.getName() << ", Signed: " << subject.getSign() << ", Sign Grade: " \
	<< subject.getSiGrade() << ", Exec Grade: " << subject.getExGrade();
	return (out);
}