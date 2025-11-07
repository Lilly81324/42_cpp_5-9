/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:39:55 by sikunne           #+#    #+#             */
/*   Updated: 2025/11/07 15:44:44 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


// Local functions: -----------------------------------------------------------


int parseTime(std::string::size_type &start, char target, const std::string &line, int &result, bool skipSpaces)
{
	std::string::size_type pos;
	std::string::size_type end;
	std::string substring;

	// Try to find target
	pos = line.find(target, start);
	if (pos == std::string::npos)
		return (ERR_PARSE_MISSING_SEP);

	// Skip spaces before and after 
	end = pos + 1;
	if (skipSpaces)
	{
		// Skip spaces after target
		while (isspace(line[end]))
			end++;
		
		// Remove spaces before target
		pos--;
		while (pos > 0 && isspace(line[pos]))
			pos--;
		pos++;
	}
	
	// Ensure until then there are only numbers
	substring = line.substr(start, pos - start);
	for (size_t i = 0; i < substring.size(); i++)
		if (!std::isdigit(substring[i]))
			return (ERR_PARSE_INVAL_CHAR);
	
	// Store result and move cursor after target
	result = std::atoi(substring.data());
	start = end;
	return (0);
}

int parseValue(std::string::size_type &start, const std::string &line, SmartNum &result)
{
	std::string::size_type dot;
	std::size_t i = 0;
	std::string substring;

	// Try to find target
	dot = line.find('.', start);

	// No dot -> int
	substring = line.substr(start);
	if (dot == std::string::npos)
	{
		for (; i < substring.size(); i++)
			if (!std::isdigit(substring[i]))
				return (ERR_PARSE_INVAL_CHAR);
		result.store(std::atoi(substring.data()));
		return (0);
	}

	// if there is a dot
	// Move past digits
	if (!std::isdigit(line[i]))
		return (ERR_PARSE_GENERIC_SYNTAX);
	while (i < substring.size() && substring[i] != '.')
	{
		if (!std::isdigit(substring[i]))
			return (ERR_PARSE_INVAL_CHAR);
		i++;
	}
	// Move past dot
	if (substring[i] != '.')
		return (ERR_PARSE_MISSING_SEP);
	i++;
	// Move past digits
	if (!std::isdigit(substring[i]))
		return (ERR_PARSE_GENERIC_SYNTAX);
	while (i < substring.size())
	{
		if (!std::isdigit(substring[i]))
			return (ERR_PARSE_INVAL_CHAR);
		i++;
	}
	result.store(std::atof(substring.data()));
	return (0);
}


// Entry Class functions: -----------------------------------------------------


Entry::Entry(void): y(0), m(0), d(0)
{ }

Entry::Entry(int y, int m, int d): y(y), m(m), d(d)
{ }

void Entry::set(int year, int month, int day)
{
	this->y = year;
	this->m = month;
	this->d = day;
}

bool Entry::operator<(const Entry &e) const
{
	if (this->y != e.y)
	{
		return (this->y < e.y);
	}
	if (this->m != e.m)
	{
		return (this->m < e.m);
	}
	if (this->d != e.d)
	{
		return (this->d < e.d);
	}
	return (false);
}

bool Entry::operator>(const Entry &e) const
{
	if (this->y != e.y)
	{
		return (this->y > e.y);
	}
	if (this->m != e.m)
	{
		return (this->m > e.m);
	}
	if (this->d != e.d)
	{
		return (this->d > e.d);
	}
	return (false);
}

bool Entry::operator==(const Entry &e) const
{
	return (this->y == e.y && this->m == e.m && this->d == e.d);
}

bool Entry::operator<=(const Entry &e) const
{
	if (*this < e || *this == e)
		return (true);
	return (false);
}

bool Entry::operator>=(const Entry &e) const
{
	if (*this > e || *this == e)
		return (true);
	return (false);
}

bool Entry::operator!=(const Entry &e) const
{
	if (*this == e)
		return (false);
	return (true);
}


// SmartNum Class functions: --------------------------------------------------


SmartNum::SmartNum(void): usesInt(true), ival(0), dval(0.0)
{ }

SmartNum::SmartNum(int i): usesInt(true), ival(i), dval(0.0)
{ }

SmartNum::SmartNum(double d): usesInt(false), ival(0), dval(d)
{ }

void SmartNum::store(int i)
{
	this->usesInt = true;
	this->ival = i;
	this->dval = 0.0;
}

void SmartNum::store(double d)
{
	this->usesInt = false;
	this->ival = 0;
	this->dval = d;
}

SmartNum &SmartNum::operator=(const SmartNum &num)
{
	if (this == &num)
		return (*this);
	this->usesInt = num.usesInt;
	this->dval = num.dval;
	this->ival = num.ival;
	return (*this);
}

SmartNum SmartNum::operator*(const SmartNum &b)
{
	double	doubVal;
	int		inVal;

	if (this->usesInt && b.usesInt)
		return (SmartNum(this->ival * b.ival));
	else if ((!this->usesInt) && (!b.usesInt))
		return (SmartNum(this->dval * b.dval));
	else
	{
		if (this->usesInt)
		{
			inVal = this->ival;
			doubVal = b.dval;
		}
		else
		{
			inVal = b.ival;
			doubVal = this->dval;
		}
		return (SmartNum(static_cast<double>(inVal) * doubVal));
	}
}


// BitcoinExchange Class functions: -------------------------------------------


SmartNum BitcoinExchange::get(const Entry &e) const
{
	std::map<Entry, SmartNum>::const_iterator it = this->lst.begin();
	std::map<Entry, SmartNum>::const_iterator end = this->lst.end();

	for (; it != end; it++)
	{
		if (it->first == e)
			return (it->second);
		else if (it->first > e)
		{
			if (it != this->lst.begin())
				it--;
			return (it->second);
		}
	}
	end--;
	return (end->second);
}

int BitcoinExchange::parseDatabaseLine(const std::string &line)
{
	int			error;
	int			year;
	int			month;
	int			day;
	SmartNum	value;
	std::string::size_type	start;

	// Skip empty lines
	if (line.empty())
		return (true);

	// First part is year
	start = 0;
	error = parseTime(start, '-', line, year, false);
	if (error != 0)
		return (error);
	error = parseTime(start, '-', line, month, false);
	if (error != 0)
		return (error);
	error = parseTime(start, ',', line, day, false);
	if (error != 0)
		return (error);
	error = parseValue(start, line, value);
	if (error != 0)
		return (error);

	this->lst[Entry(year, month, day)] = value;
	return (0);
}

int BitcoinExchange::parseDatabase(const char *name)
{
	std::ifstream in;
	std::string line;
	int error;
	char full_path[PATH_MAX];
	realpath(name, full_path);
	in.open(full_path);
	std::cout << "Path: " << full_path << std::endl;

	if (!in.good())
		return (ERR_PARSE_OPEN);
	
	// Skip Header
	getline(in, line);
	if (line != "date,exchange_rate")
		return (ERR_PARSE_MISSING_HEAD);

	// Read lines
	while (getline(in, line))
	{
		error = parseDatabaseLine(line);
		// Error in parsing -> identify
		if (error)
		{
			switch (error)
			{
				case ERR_PARSE_OPEN:			std::cout << "Error: Database " << name << "could not be opened" << std::endl;			return (error);
				case ERR_PARSE_MISSING_HEAD:	std::cout << "Error: Database " << name << "is missing the Header line" << std::endl;	return (error);
				case ERR_PARSE_MISSING_SEP:		std::cout << "Error: Database entry is missing sepereator" << std::endl;				return (error);
				case ERR_PARSE_INVAL_CHAR:		std::cout << "Error: Invalid character in database" << std::endl;						return (error);
				case ERR_PARSE_GENERIC_SYNTAX:	std::cout << "Error: Unspecified Syntax error in database" << std::endl;				return (error);
				default:						std::cout << "Error: Unknown Error code " << error << std::endl;						return (error);
			}
		}
	}
	return (0);
}

int BitcoinExchange::parseInputLine(const std::string &line)
{
	int			error;
	int			year;
	int			month;
	int			day;
	SmartNum	value;
	SmartNum	course;
	Entry		e;
	std::string::size_type	start;

	// Skip empty lines
	if (line.empty())
		return (true);

	// First part is year
	start = 0;

	error = parseTime(start, '-', line, year, false);
	if (error != 0)
		return (error);

	error = parseTime(start, '-', line, month, false);
	if (error != 0)
		return (error);

	error = parseTime(start, '|', line, day, true);
	if (error != 0)
		return (error);

	error = parseValue(start, line, value);
	if (error != 0)
		return (error);

	// Get the current Entry and the corresponding course from database
	e.set(year, month, day);
	course = this->get(e);
	std::cout << e << " => " << value << " => " << (course * value) << std::endl;
	return (0);
}

int BitcoinExchange::parseInput(const char *name)
{
	std::ifstream in;
	std::string line;
	int error;
	char full_path[PATH_MAX];
	realpath(name, full_path);
	in.open(full_path);

	if (!in.good())
		return (ERR_PARSE_OPEN);
	
	// Skip Header
	getline(in, line);
	if (line != "date | value")
		return (ERR_PARSE_MISSING_HEAD);

	// Read lines
	while (getline(in, line))
	{
		error = parseInputLine(line);
		// Error in parsing -> identify
		if (error)
		{
			switch (error)
			{
				case ERR_PARSE_OPEN:			std::cout << "Error: Input file " << name << "could not be opened" << std::endl;		break ;
				case ERR_PARSE_MISSING_HEAD:	std::cout << "Error: Input file " << name << "is missing the Header line" << std::endl;	break ;
				case ERR_PARSE_MISSING_SEP:		std::cout << "Error: Input file entry is missing sepereator" << std::endl;				break ;
				case ERR_PARSE_INVAL_CHAR:		std::cout << "Error: Invalid character in input file" << std::endl;						break ;
				case ERR_PARSE_GENERIC_SYNTAX:	std::cout << "Error: Unspecified Syntax error in input file" << std::endl;				break ;
				default:						std::cout << "Error: Unknown Error code " << error << std::endl;						break ;
			}
		}
	}
	return (0);
}


// Outputting (mostly debug, might be REDUNDANT): -----------------------------


std::ostream &operator<<(std::ostream &out, const Entry &entry)
{
	out << std::setfill('0') << \
	std::setw(4) << entry.y << "-" << \
	std::setw(2) << entry.m << "-" << \
	std::setw(2) << entry.d;
	return (out);
}

std::ostream &operator<<(std::ostream &out, const SmartNum &num)
{
	if (num.usesInt)
		out << num.ival;
	else
		out << num.dval;
	return (out);
}

std::ostream &operator<<(std::ostream &out, const std::map<Entry, SmartNum> &mapping)
{
	std::map<Entry, SmartNum>::const_iterator it = mapping.begin();
	std::map<Entry, SmartNum>::const_iterator end = mapping.end();
	if (it != end)
	{
		out << it->first << " - " << it->second;
		it++;
	}
	for (; it != end; it++)
		out << std::endl << it->first << " - " << it->second;
	return (out);
}

std::ostream &operator<<(std::ostream &out, const BitcoinExchange &btc)
{
	out << btc.lst;
	return (out);
}