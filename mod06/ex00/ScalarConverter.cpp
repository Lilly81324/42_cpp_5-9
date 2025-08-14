/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:25:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/14 16:24:47 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>
#include <iostream>
#include <limits>

void	printChar(const std::string &input)
{
	int			intvalue;
	std::string	error;

	error = IntMath::asCharLiteral(input, intvalue);
	if (error != "")
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
	float	fvalue = 0.0;
	double	dvalue;
	std::string error;
	
	error = FloatMath::atof(input, fvalue);
	std::cout << "float: ";
	if (error != "")
		std::cout << error << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << fvalue << "f" << std::endl;
	error = FloatMath::atod(input, dvalue);
	std::cout << "double: ";
	if (error != "")
		std::cout << error << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << dvalue << std::endl;
}

void	ScalarConverter::convert(const std::string &input)
{
	printChar(input);
	printInt(input);
	printFloat(input);
}