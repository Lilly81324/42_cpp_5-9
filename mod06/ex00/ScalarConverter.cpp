/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:25:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/13 18:00:02 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	printChar(const std::string &input)
{
	int			intvalue;
	std::string	error;

	error = IntMath::atoi(input, intvalue);
	std::cout << "char: ";
	if (error != "")
	{
		std::cout << error << std::endl;
		return ;
	}
	if (intvalue < ' ' || intvalue > '~')
	{
		std::cout << CHAR_NON_DISP << std::endl;
		return ;
	}
	std::cout << "'" << (char)intvalue << "'"  << std::endl;
}

void printInt(const std::string &input)
{
	int intvalue;
	std::string error;
	
	error = IntMath::atoi(input, intvalue);
	std::cout << "int: ";
	if (error != "")
		std::cout << error << std::endl;
	else
		std::cout << intvalue << std::endl;
}

void printFloat(const std::string &input)
{
	float	fvalue;
	double	dvalue;
	std::string error;
	
	error = FloatMath::atof(input, fvalue, dvalue);
	std::cout << "float: ";
	if (error != "")
		std::cout << error << std::endl;
	else
		std::cout << fvalue << std::endl;
	std::cout << "double: ";
	if (error != "")
		std::cout << error << std::endl;
	else
		std::cout << dvalue << std::endl;
}

void	ScalarConverter::convert(const std::string &input)
{
	printChar(input);
	printInt(input);
	printFloat(input);
}