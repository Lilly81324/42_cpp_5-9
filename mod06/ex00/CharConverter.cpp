/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharConverter.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:48:18 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/14 17:15:55 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CharConverter.hpp"

CharConverter::CharConverter(void): _in(""), _cval(0), _cerr("")
{
}

CharConverter::CharConverter(const std::string &input): _in(""), _cval(0), _cerr("")
{
	_in = input;
}

CharConverter::CharConverter(const CharConverter &other)
{
	*this = other;
}

CharConverter &CharConverter::operator=(const CharConverter &other)
{
	if (this == &other)
		return ;
	this->_in = other._in;
	this->_cval = other._cval;
	this->_cerr = other._cerr;
	return (*this);
}

CharConverter::~CharConverter(void)
{	
}

void	CharConverter::setInput(const std::string &newIn)
{
	this->_in = newIn;
}

std::string	CharConverter::asCharLiteral(void)
{
	if (this->_in[0] != '\'')
		return (CONVERSION_IMPOSSIBLE);
	if (this->_in[1] == '\0')
		return (CONVERSION_IMPOSSIBLE);
	if (this->_in[2] != '\'')
		return (CONVERSION_IMPOSSIBLE);
	if (this->_in[3] != '\0')
		return (CONVERSION_IMPOSSIBLE);
	this->_cval = (char)this->_in[1];
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

void	CharConverter::convChar(void)
{
	this->_cval = 0;
	int			intvalue;
	std::string	error;

	this->_cerr = asCharLiteral(void);
	if (this->_cerr != "")
		this->_cerr = IntMath::atoi(input, intvalue);
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

void	CharConverter::convert(void)
{
	
}