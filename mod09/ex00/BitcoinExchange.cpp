/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:39:55 by sikunne           #+#    #+#             */
/*   Updated: 2025/11/07 19:19:42 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


// Local functions: -----------------------------------------------------------

int checkValue(SmartNum &num)
{
	if (num.usesInt)
	{
		if (num.ival < 0)
			return (ERR_PARSE_VALUE_TOO_SMOL);
		if (num.ival > 1000)
			return (ERR_PARSE_VALUE_TOO_BIG);
		return (0);
	}
	else
	{
		if (num.dval < 0.0)
			return (ERR_PARSE_VALUE_TOO_SMOL);
		if (num.dval > 1000.0)
			return (ERR_PARSE_VALUE_TOO_BIG);
		return (0);
	}
}

int parseTime(std::string::size_type &start, char target, const std::string &line, int &result, bool skipSpaces)
{
	std::string::size_type pos;
	std::string::size_type end;
	double		insurance;
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
	insurance = std::atof(substring.data());
	if (insurance > 2147483647.0)
		result = 2147483647;
	else
		result = std::atoi(substring.data());
	start = end;
	return (0);
}

int parseValue(std::string::size_type &start, const std::string &line, SmartNum &result)
{
	std::string::size_type dot;
	std::size_t	i = 0;
	std::string	substring;
	double		insurance;

	// Try to find target
	dot = line.find('.', start);

	// No dot -> int
	substring = line.substr(start);
	if (dot == std::string::npos)
	{
		for (; i < substring.size(); i++)
			if (!std::isdigit(substring[i]))
				return (ERR_PARSE_INVAL_CHAR);
		insurance = std::atof(substring.data());
		if (insurance > 2147483647.0)
			result = 2147483647;
		else
			result = std::atoi(substring.data());
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
	result = std::atof(substring.data());
	return (0);
}


// Entry Class functions: -----------------------------------------------------


Entry::Entry(void): y(0), m(0), d(0)
{ }

Entry::Entry(const Entry &other): y(0), m(0), d(0)
{
	*this = other;
}

Entry::Entry(int y, int m, int d): y(y), m(m), d(d)
{ }

Entry::~Entry()
{ }

void Entry::set(int year, int month, int day)
{
	this->y = year;
	this->m = month;
	this->d = day;
}

bool Entry::valid(void)
{
	if (this->y < 0 || this->y > MAX_YEAR)
		return (false);
	if (this->m < 1 || this->m > 12)
		return (false);
	if (this->d < 1 || this->d > 31)
		return (false);
	return (true);
}

Entry &Entry::operator=(const Entry &other)
{
	if (this == &other)
		return (*this);
	this->y = other.y;
	this->m = other.m;
	this->d = other.d;
	return (*this);
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

SmartNum::SmartNum(const SmartNum &other): usesInt(true), ival(0), dval(0.0)
{
	*this = other;
}

SmartNum::~SmartNum(void)
{ }

SmartNum &SmartNum::operator=(const int &num)
{
	this->usesInt = true;
	this->dval = 0.0;
	this->ival = num;
	return (*this);
}

SmartNum &SmartNum::operator=(const double &num)
{
	this->usesInt = false;
	this->dval = num;
	this->ival = 0;
	return (*this);
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


BitcoinExchange::BitcoinExchange(void)
{ }

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange::~BitcoinExchange(void)
{ }


void BitcoinExchange::complain(int error, std::string filetype = "", std::string name = "")
{
	switch (error)
	{
		case ERR_PARSE_OPEN:
			std::cout << "Error: " << filetype << " file " << name << " could not be opened" << std::endl;
			break ;
		case ERR_PARSE_MISSING_HEAD:
			std::cout << "Error: " << filetype << " file " << name << " is missing the Header line" << std::endl;
			break ;
		case ERR_PARSE_MISSING_SEP:
			std::cout << "Error: " << filetype << " file entry is missing seperator" << std::endl;
			break ;
		case ERR_PARSE_INVAL_CHAR:
			std::cout << "Error: Invalid character in " << filetype << " file" << std::endl;
			break ;
		case ERR_PARSE_GENERIC_SYNTAX:
			std::cout << "Error: Unspecified Syntax error in " << filetype << " file" << std::endl;
			break ;
		case ERR_PARSE_DATE_INVALID:
			std::cout << "Error: Date in " << filetype << " file is invalid (Y:0-4000, M:1-12, D:1-31)" << std::endl;
			break ;
		case ERR_PARSE_VALUE_TOO_SMOL:
			std::cout << "Error: Value in " << filetype << " must be at least 0 (Look at this looser with negative Bitcoin)" << std::endl;
			break ;
		case ERR_PARSE_VALUE_TOO_BIG:
			std::cout << "Error: Value in " << filetype << " must be at most 1000 (You dont have THAT much Bitcoin, liar)" << std::endl;
			break ;
		default:
			std::cout << "Error: Unknown Error code " << error << " for " << filetype << std::endl;
			break ;
	}
}

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

int	BitcoinExchange::parseLine(const std::string &line, std::string seps, Entry &e, SmartNum &num)
{
	int						error = 0;
	int						year = 0;
	int						month = 0;
	int						day = 0;
	std::string::size_type	start = 0;

	// Skip empty lines
	if (line.empty())
		return (0);

	error = parseTime(start, seps[0], line, year, false);
	if (error != 0)
		return (error);
	error = parseTime(start, seps[1], line, month, false);
	if (error != 0)
		return (error);
	error = parseTime(start, seps[2], line, day, true);
	if (error != 0)
		return (error);
	error = parseValue(start, line, num);
	if (error != 0)
		return (error);
	e.set(year, month, day);
	if (!e.valid())
		return (ERR_PARSE_DATE_INVALID);
	return (0);
}

void BitcoinExchange::parseContent(std::ifstream &in, FileType mode)
{
	// Read lines
	std::string		line;
	std::string		filetype;
	int				error;
	Entry			e;
	SmartNum		value;
	SmartNum		course;

	if (mode == DATABASE)
		filetype = "database";
	else
		filetype = "input";

	while (getline(in, line))
	{
		if (mode == DATABASE)
		{
			error = parseLine(line, "--,", e, value);
			if (error)
				BitcoinExchange::complain(error, filetype);
			else
				this->lst[e] = value;
		}
		else // if (mode == INPUT_FILE)
		{
			error = parseLine(line, "--|", e, value);
			if (!error)
				error = checkValue(value);
			if (error)
				BitcoinExchange::complain(error, filetype);
			else
			{
				course = this->get(e);
				std::cout << e << " => " << value << " => " << (course * value) << std::endl;
			}
		}
	}
}

int BitcoinExchange::parseFile(const char *name, FileType mode)
{
	std::ifstream	in;
	std::string		line;
	std::string		filetype;
	char			full_path[PATH_MAX];

	if (mode == DATABASE)
		filetype = "database";
	else
		filetype = "input";

	realpath(name, full_path);
	in.open(full_path);

	if (!in.good())
	{
		BitcoinExchange::complain(ERR_PARSE_OPEN, filetype, full_path);
		return (ERR_PARSE_OPEN);
	}
	
	// Skip Header
	getline(in, line);
	if ((mode == DATABASE && line != "date,exchange_rate") \
		|| (mode == INPUT_FILE && line != "date | value"))
	{
		BitcoinExchange::complain(ERR_PARSE_MISSING_HEAD, filetype, full_path);
		return (ERR_PARSE_MISSING_HEAD);
	}

	parseContent(in, mode);
	return (0);
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this == &other)
		return (*this);
	std::map<Entry, SmartNum>::const_iterator it = other.lst.begin();
	std::map<Entry, SmartNum>::const_iterator end = other.lst.end();
	for (; it != end; it++)
		this->lst.insert(*it);
	return (*this);
}

// Outputting : ---------------------------------------------------------------


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

// To use this, make BitcoinExchange->lst public
// std::ostream &operator<<(std::ostream &out, const BitcoinExchange &btc)
// {
// 	out << btc.lst;
// 	return (out);
// }