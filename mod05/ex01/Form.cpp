/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 14:16:55 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/01 18:14:19 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void): \
name(FO_DEF_NAME), is_signed(FO_DEF_SIGN), sign_grade(FO_DEF_SIGN_GRADE), exec_grade(FO_DEF_EX_GRADE)
{
	std::cout << "Default Form Constructor called:       ";
	std::cout << *this << std::endl;
}

Form::Form(const std::string name, const int sign_g, const int exec_g): \
name(name), is_signed(FO_DEF_SIGN), sign_grade(sign_g), exec_grade(exec_g)
{
	if (sign_g < 1)
		throw (Form::GradeTooHighException());
	else if (sign_g > 150)
		throw (Form::GradeTooLowException());
	if (exec_g < 1)
		throw (Form::GradeTooHighException());
	else if (exec_g > 150)
		throw (Form::GradeTooLowException());
	std::cout << "Parameterized Form Constructor called: ";
	std::cout << *this << std::endl;
}

Form::Form(const Form& other): \
name(other.getName()), is_signed(other.getSign()), \
sign_grade(other.getSiGrade()), exec_grade(other.getExGrade())
{
	std::cout << "Copy Form Constructor created:        ";
	std::cout << *this << std::endl;
}

Form& Form::operator=(const Form& other)
{
	std::cout << "Form Asignement operator called:       ";
	std::cout << "Setting " << this->getSign() << " to " << other.getSign() << std::endl;
	if (this == &other)
		return (*this);
	this->is_signed = other.getSign();
	return (*this);
}

Form::~Form()
{
	std::cout << "Form Destructor called on: ";
	std::cout << *this << std::endl;
}

std::string	Form::getName(void) const
{
	return (this->name);
}

bool		Form::getSign(void) const
{
	return (this->is_signed);
}

int			Form::getSiGrade(void) const
{
	return (this->sign_grade);
}

int			Form::getExGrade(void) const
{
	return (this->exec_grade);
}

bool	Form::beSigned(const Bureaucrat& signer)
{
	if (this->is_signed)
		return (false);
	if (signer.getGrade() > this->getSiGrade())
		throw (Form::GradeTooLowException());
	this->is_signed = true;
	return (true);
}

const char *Form::GradeTooHighException::what(void) const throw ()
{
	return ("Error: Grade too high");
}

const char *Form::GradeTooLowException::what(void) const throw ()
{
	return ("Error: Grade too low");
}

std::ostream &operator<<(std::ostream &out, const Form& subject)
{
	out << subject.getName() << ", Signed: " << subject.getSign() << ", Sign Grade: " \
	<< subject.getSiGrade() << ", Exec Grade: " << subject.getExGrade();
	return (out);
}