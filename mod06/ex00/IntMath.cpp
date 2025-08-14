/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntMath.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:44:46 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/14 17:24:55 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IntMath.hpp"

IntMath::IntMath(void)
{
}

IntMath::IntMath(const IntMath &other)
{
	(void)other;
}

IntMath &IntMath::operator=(const IntMath &other)
{
	(void)other;
	return (*this);
}

IntMath::~IntMath(void)
{
}

bool	IntMath::isdigit(char num)
{
	if (num >= '0' && num <= '9')
		return (true);
	return (false);
}

std::string	IntMath::asCharLiteral(const std::string &inp, int &out)
{
	if (inp[0] != '\'')
		return (CONVERSION_IMPOSSIBLE);
	if (inp[1] == '\0')
		return (CONVERSION_IMPOSSIBLE);
	if (inp[2] != '\'')
		return (CONVERSION_IMPOSSIBLE);
	if (inp[3] != '\0')
		return (CONVERSION_IMPOSSIBLE);
	out = inp[1];
	return ("");
}

std::string IntMath::atoi(const std::string &inp, int &output)
{
	long	stored = 0;
	int		i = 0;
	int		fac = 1;

	output = 0;
	if (inp[i] == '-' || inp[i] == '+')
	{
		if (inp[i] == '-')
			fac = fac * -1;
		i++;
	}
	// Start of integer
	if (!isdigit(inp[i]))
		return (CONVERSION_IMPOSSIBLE);
	while (isdigit(inp[i]))
	{
		stored = stored * 10 + (inp[i] - '0');
		if ((fac == 1 && stored > MAX_INT) || \
			(fac == -1 && stored > ABS_MIN_INT))
				return (CONVERSION_IMPOSSIBLE);
		i++;
	}
	// End of integer
	if (inp[i] == '.')
	{
		i++;
		if (!isdigit(inp[i]))
			return (CONVERSION_IMPOSSIBLE);
		while (isdigit(inp[i]))
			i++;
		if (inp[i] == 'f' || inp[i] == 'F')
			i++;
	}
	if (inp[i])
		return (CONVERSION_IMPOSSIBLE);
	output = (int)(fac * stored);
	return ("");
}
