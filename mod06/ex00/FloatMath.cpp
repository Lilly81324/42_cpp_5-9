/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloatMath.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:50:31 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/13 18:02:33 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FloatMath.hpp"
#include <iostream>

std::string FloatMath::atof(const std::string &inp, float &outf, double & outd)
{
	float	resultf = 0;
	double	resultd = 0;
	int		i = 0;
	int		fac = 1;

	outf = 0.0;
	outd = 0.0;
	if (inp[i] == '-' || inp[i] == '+')
	{
		if (inp[i] == '-')
			fac = -1;
		i++;
	}
	(void)fac;
	// Start of float
	if (!IntMath::isdigit(inp[i]))
		return (CONVERSION_IMPOSSIBLE);
	while (IntMath::isdigit(inp[i]))
	{
		resultf = resultf * 10 + (inp[i] - '0');
		resultd = resultd * 10 + (inp[i] - '0');
		i++;
	}
	std::cout << "So far: " << resultf << " and " << resultd << std::endl;
	// End of integer
	if (inp[i] == '.')
	{
		i++;
		if (!IntMath::isdigit(inp[i]))
			return (CONVERSION_IMPOSSIBLE);
		while (IntMath::isdigit(inp[i]))
			i++;
		if (!(inp[i] == 'f' || inp[i] == 'F'))
			return (CONVERSION_IMPOSSIBLE);
		i++;
	}
	if (inp[i])
		return (CONVERSION_IMPOSSIBLE);
	return ("");
}
