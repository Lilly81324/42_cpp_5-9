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
	std::cout << "ShrubberyCreationForm D-Constr.:  ";
	std::cout << *this << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): \
AForm("Shrubbery Creation Form", 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm P-Constr.:  ";
	std::cout << *this << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): \
AForm("Shrubbery Creation Form", 145, 137), target(other.getTarget())
{
	std::cout << "ShrubberyCreationForm C-Constr.:  ";
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
	std::cout << "ShrubberyCreationForm Destructor: ";
	std::cout << *this << std::endl;
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->target);
}

void ShrubberyCreationForm::draw_line( std::ofstream& out, int count, const std::string &src) const
{
	for (int i = 0; i < count; i++)
		out << src;
	out << std::endl;
}

bool	ShrubberyCreationForm::draw_tree(void) const
{
	std::string name;

	name = this->getTarget() + "_shrubbery";
	std::ofstream out(name.c_str());
	if (!out.is_open())
	{
		std::cerr << "Error: Couldnt open file" << std::endl;
		return (false);
	}
	draw_line(out, 4, "         ooooooo    ");
	draw_line(out, 4, "        ooOOOO0oo   ");
	draw_line(out, 4, "       ooO0OOO0Ooo  ");
	draw_line(out, 4, "       ooOOO0OOOoo  ");
	draw_line(out, 4, "   _    ooOOO0Ooo   ");
	draw_line(out, 4, "  / \\    oo|o|oo    ");
	draw_line(out, 4, "  | |   >-=| |      ");
	draw_line(out, 4, "  \\_/      | |=-<   ");
	draw_line(out, 4, "   |-      | |      ");
	draw_line(out, 4, "  -|       | |      ");
	draw_line(out, 4, "   |      /   \\     ");
	return (true);
}

bool	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSign())
		return false;
	if (executor.getGrade() > this->getExGrade())
		return false;
	std::cout << \
	executor.getName() << " has executed the " <<\
	this->getName() << " for " <<\
	this->getTarget() << "." << std::endl;
	return (this->draw_tree());
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