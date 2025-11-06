/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:39:55 by sikunne           #+#    #+#             */
/*   Updated: 2025/11/06 19:43:54 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


// Entry Class functions: -----------------------------------------------------

Entry::Entry(int y, int m, int d): y(y), m(m), d(d)
{ }

Entry::Entry(void): y(0), m(0), d(0)
{ }

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


// BitcoinExchange Class functions: -------------------------------------------


void BitcoinExchange::add(Entry entry, SmartNum num)
{
	this->lst[entry] = num;
}

// Input: 2020-05-08,10002.48 start at 0, 5, 8
int parseTime(std::string::size_type &start, char target, const std::string &line, int &result)
{
	std::string::size_type end;
	std::string substring;

	// Try to find target
	end = line.find(target, start);
	if (end == std::string::npos)
		return (ERR_PARSE_MISSING_SEP);
	
	// Ensure until then there are only numbers
	substring = line.substr(start, end - start);
	for (size_t i = 0; i < substring.size(); i++)
		if (!std::isdigit(substring[i]))
			return (ERR_PARSE_INVAL_CHAR);
	
	// Store result and move cursor after target
	result = std::atoi(substring.data());
	start = end + 1;
	return (0);
}

/*
	2020-05-05,8885;
	2020-05-08,10002.48;
*/

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

int BitcoinExchange::parseLine(const std::string &line)
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
	error = parseTime(start, '-', line, year);
	if (error != 0)
		return (error);
	error = parseTime(start, '-', line, month);
	if (error != 0)
		return (error);
	error = parseTime(start, ',', line, day);
	if (error != 0)
		return (error);
	if (year == 2010 && month == 8 && day == 20)
		std::cout << "here!" << std::endl;
	error = parseValue(start, line, value);
	if (error != 0)
		return (error);
	this->add(Entry(year, month, day), value);
	return (0);
}

int BitcoinExchange::parseFile(const char *name)
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
		error = parseLine(line);
		if (error)
			return (error);
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