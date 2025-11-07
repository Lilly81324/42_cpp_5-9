/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:29:29 by sikunne           #+#    #+#             */
/*   Updated: 2025/11/07 19:30:18 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool find(char c, const std::string &str)
{
	for (int i = 0; i < (int)str.size(); i++)
		if (c == str[i])
			return (true);
	return (false);
}

Rpn::Rpn(void): stack()
{ }

Rpn::Rpn(const Rpn &other): stack()
{
	*this = other;
}

Rpn::~Rpn(void)
{ }

void Rpn::clear(void)
{
	while (this->stack.size() > 0)
		this->stack.pop();
}

bool Rpn::operand(int number)
{
	if (number >= 10)
		return (false);
	this->stack.push(number);
	return (true);
}

bool Rpn::operater(char op)
{
	int a;
	int b;

	if (this->stack.size() < 2)
		return (false);
	a = this->stack.top();
	this->stack.pop();
	b = this->stack.top();
	this->stack.pop();
	if (op == '-')
		b -= a;
	else if (op == '*')
		b *= a;
	else if (op == '/')
		b /= a;
	else
		b += a;
	this->stack.push(b);
	return (true);
}

int Rpn::getResult(std::string &error)
{
	// If too much in stack
	if (this->stack.size() > 1)
	{
		error = "Error: Operation has too many remainders and is invalid";
		return (0);
	}
	if (this->stack.size() < 1)
	{
		error = "Error: Operation has no remainders left";
		return (0);
	}
	return (this->stack.top());
}

Rpn &Rpn::operator=(const Rpn &other)
{
	if (this == &other)
		return (*this);
	this->stack = other.stack;
	return (*this);
}

RpnCaller::RpnCaller(void)
{
	this->curNum = -1;
	this->hasNum = false;
	this->lastOperator = 0;
	this->error = "";
}

RpnCaller::RpnCaller(const RpnCaller &other)
{
	*this = other;
}

RpnCaller::~RpnCaller(void)
{ }

void RpnCaller::clear()
{
	this->curNum = -1;
	this->hasNum = false;
	this->lastOperator = 0;
	this->error = "";
	this->rpn.clear();
}

// Digits may be after
// Digits
// Space
// Other last operands
bool RpnCaller::givenDigit(char c)
{
	if (!hasNum)
		curNum = 0;
	hasNum = true;
	if (lastOperator == '-')
		curNum = curNum * 10 - (c - '0');
	else if (lastOperator == '+' || lastOperator == '\0')
		curNum = curNum * 10 + (c - '0');
	else
	{
		error = "Error: Invalid sign for a number, msut be + or -";
		return (false);
	}
	return (true);
}

bool RpnCaller::givenSpace(void)
{
	if (hasNum)
	{
		if (this->rpn.operand(curNum) == false)
		{
			error = "Error: Only numbers below 10 are allowed";
			return (false);
		}
	}
	else if (lastOperator != '\0')
	{
		if (this->rpn.operater(lastOperator) == false)
		{
			error = "Error: Not enough numbers for operator";
			return (false);
		}
	}
	lastOperator = '\0';
	hasNum = false;
	return (true);
}

bool RpnCaller::givenOperator(char c)
{
	if (hasNum || lastOperator != '\0')
	{
		error = "Error: Operator directly after number or other operator";
		return (false);
	}
	lastOperator = c;
	return (true);
}

int RpnCaller::handle(const char *input)
{
	// Clear last usage
	char c;
	this->clear();

	if (input == NULL)
	{
		error = "Error: No input given";
		return (0);
	}

	// For each character in input
	for (int i = 0; input[i] != '\0'; i++)
	{
		c = input[i];

		if (isdigit(c))
		{
			if (!givenDigit(c))
				return (0);
		}
		else if (find(c, OPERATORS))
		{
			if (!givenOperator(c))
				return (0);
		}
		else if (isspace(c))
		{
			if (!givenSpace())
				return (0);
		}
		else
		{
			error = "Error: Invalid character in input";
			return (0);
		}
	}

	// If buffers have stuff left
	if (hasNum)
	{
		if (this->rpn.operand(curNum) == false)
		{
			error = "Error: Only numbers below 10 are allowed";
			return (0);
		}
	}
	else if (lastOperator != '\0')
	{
		if (this->rpn.operater(lastOperator) == false)
		{
			error = "Error: Not enough numbers for operator";
			return (0);
		}
	}
	return (this->rpn.getResult(error));
}

const std::string RpnCaller::getError(void)
{
	return (this->error);
}

RpnCaller &RpnCaller::operator=(const RpnCaller &other)
{
	if (this == &other)
		return (*this);
	this->rpn = other.rpn;
	this->curNum = other.curNum;
	this->hasNum = other.hasNum;
	this->lastOperator = other.lastOperator;
	this->error = other.error;
	return (*this);
}
