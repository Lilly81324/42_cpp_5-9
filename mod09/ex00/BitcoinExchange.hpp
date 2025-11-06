#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <iomanip>
#include <map>
#include <ostream>
#include <fstream>
#include <cstdlib>
#include <limits.h>

// Error Codes for parsing
# define ERR_PARSE_OPEN 1
# define ERR_PARSE_MISSING_HEAD 2
# define ERR_PARSE_MISSING_SEP 3
# define ERR_PARSE_INVAL_CHAR 4
# define ERR_PARSE_GENERIC_SYNTAX 5

class Entry
{
	public:
		Entry(int y, int m, int d);
		Entry();
		int y; // Year
		int m; // Month
		int d; // Day
	
		bool operator<(const Entry &e) const;
		bool operator<=(const Entry &e) const;
		bool operator>=(const Entry &e) const;
		bool operator>(const Entry &e) const;
		bool operator==(const Entry &e) const;
		bool operator!=(const Entry &e) const;
};

class SmartNum
{
	public:
		bool	usesInt;
		int		ival;
		double	dval;

		SmartNum(void);
		SmartNum(int i);
		SmartNum(double d);

		void store(int num);
		void store(double num);
};

class BitcoinExchange
{
	public:
		std::map<Entry, SmartNum> lst;
		void add(Entry entry, SmartNum num);
		int parseLine(const std::string &line);
		int parseFile(const char *name);
};

std::ostream &operator<<(std::ostream &out, const Entry &entry);

std::ostream &operator<<(std::ostream &out, const SmartNum &num);

std::ostream &operator<<(std::ostream &out, const std::map<Entry, SmartNum> &mapping);

std::ostream &operator<<(std::ostream &out, const BitcoinExchange &btc);

#endif