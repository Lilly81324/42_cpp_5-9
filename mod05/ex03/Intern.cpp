/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:55:35 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/05 16:12:15 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern Default Constructor" << std::endl;
}

Intern::Intern(const Intern& other)
{
	(void)other;
	std::cout << "Intern Copy Constructor" << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "Intern Deconstrcutor" << std::endl;
}

Intern &Intern::operator=(const Intern &copy)
{
	(void)copy;
	std::cout << "Intern Asignement" << std::endl;
	return (*this);
}

void	Intern::stripString(std::string &s) const
{
	size_t	new_len = 0;
	size_t	old_len = -1;

	while (++old_len < s.length())
	{
		if (s[old_len] == ' ')
			continue ;
		s[new_len] = std::tolower((unsigned char)(s[old_len]));
		new_len++;
	}
	s.resize(new_len);
}

AForm	*Intern::makeForm(const std::string &type, const std::string &target) const
{
	int pos = 1;
	std::string name = type;
	const std::string keys[3] = {
	"robotomyrequest", \
	"shrubberycreation", \
	"presidentialpardon"};

	this->stripString(name);
	while (pos < 4 && name != keys[pos - 1])
		pos++;
	switch (pos)
	{
		case 1:
		{
			std::cout << "Making Robotomy Request Form for " << target << std::endl;
			return (new RobotomyRequestForm(target));
		}
		case 2:
		{
			std::cout << "Making Shrubbery Creation Form for " << target << std::endl;
			return (new ShrubberyCreationForm(target));
		}
		case 3:
		{
			std::cout << "Making Presidential Pardon Form for " << target << std::endl;
			return (new PresidentialPardonForm(target));
		}
		default:
		{
			std::cerr << "Error: Intern failed at making " << name << " Form. Bad Intern." << std::endl;
			return (NULL);
		}
	}
	std::cerr << "Error: Intern failed at making " << name << " Form. Bad Intern." << std::endl;
	return (NULL);
}
