/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:25:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/22 17:11:33 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
}

void	ScalarConverter::convert(const std::string &input)
{
	std::string output;
	char cvalue;
	int ivalue;
	float	fvalue;
	double	dvalue;

	std::cout << "char: ";
	output = ConverterUtil::strToChar(input, cvalue);
	if (output != "")
		std::cout << output << std::endl;
	else
		std::cout << "'" << cvalue << "'" << std::endl;

	std::cout << "int: ";
	output = ConverterUtil::strToInt(input, ivalue);
	if (output != "")
		std::cout << output << std::endl;
	else
		std::cout << ivalue << std::endl;
	
	std::cout << "float: ";
	output = ConverterUtil::strToFloat(input, fvalue);
	if (output != "")
		std::cout << output << std::endl;
	else
		std::cout << std::fixed << std::setprecision(PRECISION) << fvalue << "f" << std::endl;
	
	std::cout << "double: ";
	output = ConverterUtil::strToDouble(input, dvalue);
	if (output != "")
		std::cout << output << std::endl;
	else
		std::cout << std::fixed << std::setprecision(PRECISION) << fvalue << std::endl;
}