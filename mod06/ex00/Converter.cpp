/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:48:18 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/14 17:07:33 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter(void): _in(""), _cval(0), _cerr(""), _ival(0), _ierr(""), _fval(0.0f), _ferr(""), _dval(0.0), _derr("")
{
}

Converter::Converter(const std::string &input): _in(""), _cval(0), _cerr(""), _ival(0), _ierr(""), _fval(0.0f), _ferr(""), _dval(0.0), _derr("")
{
	_in = input;
}

Converter::Converter(const Converter &other)
{
	*this = other;
}

Converter &Converter::operator=(const Converter &other)
{
	if (this == &other)
		return ;
	this->_in = other._in;
	this->_cval = other._cval;
	this->_cerr = other._cerr;
	this->_ival = other._ival;
	this->_ierr = other._ierr;
	this->_fval = other._fval;
	this->_ferr = other._ferr;
	this->_dval = other._dval;
	this->_derr = other._derr;
	return (*this);
}

Converter::~Converter(void)
{	
}

void	Converter::setInput(const std::string &newIn)
{
	this->_in = newIn;
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

void	Converter::convChar(void)
{
	this->_cval = 0;
	int			intvalue;
	std::string	error;

	error = asCharLiteral(input, intvalue);
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

void	Converter::convert(void)
{
	
}