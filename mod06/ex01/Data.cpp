/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:37:39 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/19 14:37:39 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void): name("none"), value(0), active(false)
{}

Data::~Data(void)
{}

Data::Data(const std::string &name, int val, bool active): name(name), value(val), active(active)
{}


Data::Data(const Data &other)
{
	*this = other;
}

Data &Data::operator=(const Data &other)
{
	if (this == &other)
		return (*this);
	this->name = other.getName();
	this->value = other.getValue();
	this->active = other.getActive();
	return (*this);
}

std::string Data::getName(void) const
{
	return (this->name);
}

int Data::getValue(void) const
{
	return (this->value);
}

bool Data::getActive(void) const
{
	return (this->active);
}

std::ostream &operator<<(std::ostream &out, const Data &target)
{
	out << target.getName() << " has the value " << target.getValue() << " and is ";
	if (!target.getActive())
		out << "not ";
	out << "active.";
	return (out);
}