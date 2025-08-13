/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloatMath.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:50:31 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/13 19:03:18 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FloatMath.hpp"
#include <iostream>

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
	if (inp[i + 3])
		return (false);
	return (true);
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
	if (inp[i + 3])
		return (false);
	return (true);
}

/**
 * handles fraction part of doubles
 */
void	dfraction(const std::string &inp, double &outd, int &i)
{
	int		depth = 1;
	double	result = 0;

	while (IntMath::isdigit(inp[i]))
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
 * handles fraction part of flaots
 */
void	ffraction(const std::string &inp, float &outf, int &i)
{
	int		depth = 1;
	float	result = 0;

	while (IntMath::isdigit(inp[i]))
	{
		result = inp[i] - '0';
		for (int i = 0; i < depth; i++)
			result /= 10;
		outf += result;
		depth++;
		i++;
	}
}

std::string FloatMath::atof(const std::string &inp, float &outf)
{
	int		i = 0;
	int		fac = 1;

	outf = 0.0;
	
	if (isNan(inp, i))
		return ("nanf");
	if (inp[i] == '-' || inp[i] == '+')
	{
		if (inp[i] == '-')
			fac = -1;
		i++;
	}
	if (isInf(inp, i) && fac == 1)
		return ("inf");
	if (isInf(inp, i) && fac == -1)
		return ("-inf");
	// Start of float
	if (!IntMath::isdigit(inp[i]))
		return (CONVERSION_IMPOSSIBLE);
	i--;
	while (IntMath::isdigit(inp[++i]))
		outf = outf * 10 + (inp[i] - '0');
	// End of integer
	if (inp[i] == '.')
	{
		i++;
		if (!IntMath::isdigit(inp[i]))
			return (CONVERSION_IMPOSSIBLE);
		ffraction(inp, outf, i);
		if (inp[i] == 'f' || inp[i] == 'F')
			i++;
	}
	if (inp[i])
		return (CONVERSION_IMPOSSIBLE);
	outf *= fac;
	return ("");
}

std::string FloatMath::atod(const std::string &inp, double &outd)
{
	int		i = 0;
	int		fac = 1;

	outd = 0.0;
	if (isNan(inp, i))
		return ("nan");
	if (inp[i] == '-' || inp[i] == '+')
	{
		if (inp[i] == '-')
			fac = -1;
		i++;
	}
	if (isInf(inp, i) && fac == 1)
		return ("inf");
	if (isInf(inp, i) && fac == -1)
		return ("-inf");
	// Start of float
	if (!IntMath::isdigit(inp[i]))
		return (CONVERSION_IMPOSSIBLE);
	i--;
	while (IntMath::isdigit(inp[++i]))
		outd = outd * 10 + (inp[i] - '0');
	// End of integer
	if (inp[i] == '.')
	{
		i++;
		if (!IntMath::isdigit(inp[i]))
			return (CONVERSION_IMPOSSIBLE);
		dfraction(inp, outd, i);
		if (inp[i] == 'f' || inp[i] == 'F')
			i++;
	}
	if (inp[i])
		return (CONVERSION_IMPOSSIBLE);
	outd *= fac;
	return ("");
}