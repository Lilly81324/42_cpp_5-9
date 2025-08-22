/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialiser.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:30:06 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/19 14:30:06 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{}

Serializer::~Serializer(void)
{}

Serializer::Serializer(const Serializer &other)
{
	(void)other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	(void)other;
	return (*this);
}

uintptr_t Serializer::serialize(Data *data)
{
	return (reinterpret_cast<uintptr_t>(data));
}

Data *Serializer::deserialize(uintptr_t target)
{
	return (reinterpret_cast<Data *>(target));
}