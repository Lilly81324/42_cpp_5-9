#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <iomanip>
#include <map>
#include <ostream>
#include <fstream>
#include <cstdlib>
#include <limits.h>

// Error Codes for parsing database
# define ERR_PARSE_OPEN 1
# define ERR_PARSE_MISSING_HEAD 2
# define ERR_PARSE_MISSING_SEP 3
# define ERR_PARSE_INVAL_CHAR 4
# define ERR_PARSE_GENERIC_SYNTAX 5

// Error Codes for parsing input file
# define ERR_PARSE_OPEN 1
# define ERR_PARSE_MISSING_HEAD 2
# define ERR_PARSE_MISSING_SEP 3
# define ERR_PARSE_INVAL_CHAR 4
# define ERR_PARSE_GENERIC_SYNTAX 5

class Entry
{
	public:
		int y; // Year
		int m; // Month
		int d; // Day

		Entry();
		Entry(int y, int m, int d);
		
		void set(int year, int month, int day);
	
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

		SmartNum &operator=(const SmartNum &e);
		SmartNum operator*(const SmartNum &b);
};

class BitcoinExchange
{
	public:
		std::map<Entry, SmartNum> lst;

		SmartNum get(const Entry &e) const;
		int parseDatabaseLine(const std::string &line);
		int parseDatabase(const char *name);
		int parseInputLine(const std::string &line);
		int parseInput(const char *name);
};

std::ostream &operator<<(std::ostream &out, const Entry &entry);

std::ostream &operator<<(std::ostream &out, const SmartNum &num);

std::ostream &operator<<(std::ostream &out, const std::map<Entry, SmartNum> &mapping);

std::ostream &operator<<(std::ostream &out, const BitcoinExchange &btc);

#endif