/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConverterUtil.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:12:36 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/22 17:08:22 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ConverterUtil.hpp"

ConverterUtil::ConverterUtil(void)
{
}

ConverterUtil::ConverterUtil(const ConverterUtil &other)
{
	(void)other;
}

ConverterUtil &ConverterUtil::operator=(const ConverterUtil &other)
{
	(void)other;
	return (*this);
}

ConverterUtil::~ConverterUtil(void)
{
}

/**
 * @returns true if input at i is "nan" and then stops
 */
bool	isNan(const std::string &inp, int i)
{
	if (inp[i] != 'n')
		return (false);
	if (inp[i + 1] != 'a')
		return (false);
	if (inp[i + 2] != 'n')
		return (false);
	if (inp[i + 3] == '\0')
		return (true);
	else if (inp[i + 3] == 'f' && inp[i + 4] == '\0')
		return (true);
	return (false);
}

/**
 * @returns true if input at i is "inf" and then stops
 */
bool	isInf(const std::string &inp, int i)
{
	if (inp[i] != 'i')
		return (false);
	if (inp[i + 1] != 'n')
		return (false);
	if (inp[i + 2] != 'f')
		return (false);
	if (inp[i + 3] == '\0')
		return (true);
	else if (inp[i + 3] == 'f' && inp[i + 4] == '\0')
		return (true);
	return (false);
}

bool	ft_isdigit(char num)
{
	if (num >= '0' && num <= '9')
		return (true);
	return (false);
}

/**
 * 
 * @brief Handles fraction part of doubles
 * @param inp String to take data from
 * @param outf Double to store fractional parts in
 * @param i Iterator for position in string
 */
void	dfraction(const std::string &inp, double &outd, int &i)
{
	int		depth = 1;
	double	result = 0;

	while (ft_isdigit(inp[i]))
	{
		result = inp[i] - '0';
		for (int i = 0; i < depth; i++)
			result /= 10;
		outd += result;
		depth++;
		i++;
	}
}

/**
 * @brief Tries to calculate a character in int form from the input string
 * @param inp String to convert
 * @param result Place to store the double in
 * @returns String with error message, if conversion invalid
 * @returns Empty string "" if conversion succesfull
 */
std::string ConverterUtil::strToChar(const std::string &input, char &result)
{
	double	dvalue;
	std::string error;

	error = ConverterUtil::strToDouble(input, dvalue);
	if (error != "")
		return (CONVERSION_IMPOSSIBLE);
	if (dvalue < CHAR_MIN || dvalue > (double)CHAR_MAX)
		return (CONVERSION_IMPOSSIBLE);
	result = static_cast<char>(dvalue);
	if (result < ' ' || result > '~')
		return (CHAR_NON_DISP);
	return ("");
}

/**
 * @brief Tries to calculate a double from the input string
 * @param inp String to convert
 * @param result Place to store the double in
 * @returns String with error message, if conversion invalid
 * @returns Empty string "" if conversion succesfull
 */
std::string ConverterUtil::strToInt(const std::string &input, int &result)
{
	double	dvalue;
	std::string error;

	error = ConverterUtil::strToDouble(input, dvalue);
	if (error != "")
		return (CONVERSION_IMPOSSIBLE);
	if (dvalue < (double)INT_MIN || dvalue > (double)INT_MAX)
		return (CONVERSION_IMPOSSIBLE);
	result = static_cast<int>(dvalue);
	return ("");
}

/**
 * @brief Tries to calculate a float from the input string
 * @param inp String to convert
 * @param result Place to store the double in
 * @returns String with error message, if conversion invalid
 * @returns Empty string "" if conversion succesfull
 */
std::string ConverterUtil::strToFloat(const std::string &input, float &result)
{
	double	dvalue;
	std::string error;

	error = ConverterUtil::strToDouble(input, dvalue);
	if (error != "")
		return (error += "f");
	result = static_cast<float>(dvalue);
	return ("");
}

/**
 * @brief Tries to calculate a double from the input string
 * @param inp String to convert
 * @param result Place to store the double in
 * @returns String with error message, if conversion invalid
 * @returns Empty string "" if conversion succesfull
 */
std::string ConverterUtil::strToDouble(const std::string &inp, double &result)
{
	int	fac = 1;
	int i = 0;
	result = std::numeric_limits<double>::quiet_NaN();
	if (isNan(inp, i))
		return ("nan");
	if (inp[i] == '-' || inp[i] == '+')
	{
		if (inp[i] == '-')
			fac = -1;
		i++;
	}
	result = std::numeric_limits<double>::infinity();
	if (isInf(inp, i) && fac == 1)
		return ("inf");
	result = -std::numeric_limits<double>::infinity();
	if (isInf(inp, i) && fac == -1)
		return ("-inf");
	result = 0;
	if (!ft_isdigit(inp[i]))
		return (CONVERSION_IMPOSSIBLE);
	i--;
	while (ft_isdigit(inp[++i]))
		result = result * 10 + (inp[i] - '0');
	if (inp[i] == '.')
	{
		i++;
		if (!ft_isdigit(inp[i]))
			return (CONVERSION_IMPOSSIBLE);
		dfraction(inp, result, i);
		if (inp[i] == 'f' || inp[i] == 'F')
			i++;
	}
	if (inp[i])
		return (CONVERSION_IMPOSSIBLE);
	result *= fac;
	return ("");
}
