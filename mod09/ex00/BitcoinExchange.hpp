/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:15:21 by sikunne           #+#    #+#             */
/*   Updated: 2025/11/07 18:15:21 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>		// << operator
#include <iomanip>		// setwidth, needed for fancy Entry outputting
#include <map>			// Container used in this exercise
#include <fstream>		// ifstream in order to read from file
#include <cstdlib>		// std::atoi
#include <limits.h>		// PATH_MAX for realpath()

// Error Codes for parsing database
# define ERR_PARSE_OPEN 1
# define ERR_PARSE_MISSING_HEAD 2
# define ERR_PARSE_MISSING_SEP 3
# define ERR_PARSE_INVAL_CHAR 4
# define ERR_PARSE_GENERIC_SYNTAX 5
# define ERR_PARSE_DATE_INVALID 6
# define ERR_PARSE_VALUE_TOO_SMOL 7
# define ERR_PARSE_VALUE_TOO_BIG 8

# define MAX_YEAR 4000

enum FileType
{
	DATABASE = 0,
	INPUT_FILE
};



// Entry Class functions: -----------------------------------------------------


/**
 * @brief Class specifying a BitcoinExchange Timestamp
 * 
 * Data has to be set in one go
 * Relational Operators lexicographically compare
 * meaning:
 * {
 * Go through y, then m, then d
 * Return result of operation on the first unequal element
 * )
 */
class Entry
{
	// Data 
	public:
		int y; // Year
		int m; // Month
		int d; // Day

	// Functions:
	public:
		Entry();
		Entry(int y, int m, int d);
		
		void set(int year, int month, int day);
		bool valid(void);
	
		// Required for use in map, so it satisfies "Compare"
		bool operator<(const Entry &e) const;
		bool operator<=(const Entry &e) const;
		bool operator>=(const Entry &e) const;
		bool operator>(const Entry &e) const;
		bool operator==(const Entry &e) const;
		bool operator!=(const Entry &e) const;
};



// SmartNum Class functions: --------------------------------------------------


/**
 * @brief Class for BitcoinExchange values
 * 
 * Can store either int or float, and may be reset at any time
 * To use, simply check if <usesInt> is true, then use the <ival>
 * otherwise use the <dval>
 * Data can be set in Constructor, or later with = asignement
 * example: Entry e(5.5);
 * example:	Entry e; e = 5.5;
 */
class SmartNum
{
	// Data 
	public:
		bool	usesInt;
		int		ival;
		double	dval;

	// Functions:
	public:
		SmartNum(void);
		SmartNum(int i);
		SmartNum(double d);

		SmartNum &operator=(const int &num);
		SmartNum &operator=(const double &num);
		SmartNum &operator=(const SmartNum &e);
		SmartNum operator*(const SmartNum &b);
};



// BitcoinExchange Class functions: -------------------------------------------


/**
 * @brief Handles storing a database of Timestamps with values,
 * and returns the value based on a given input file of timestamps and amount per day
 * 
 * Main:
 * Use parseFile(..., DATABASE) to set the database
 * Then use parseFile(..., FILE_INPUT) to check a file with the currently stored database
 * Optional:
 * complain() with any error code from this class to get an output of the error
 * get() with a Timestamp to get the currently stored value there or earlier
 */
class BitcoinExchange
{
	// Data 
	private:
		std::map<Entry, SmartNum> lst;

	// Functions:
	public:
		/**
		 * @brief Complain according to the given error code
		 * @param error Specifies the type of message
		 * @param filetype [optional] specifies wether input file or database file
		 * @param name [optional] specifies files name
		 */
		static void complain(int error, std::string filetype, std::string name);

		/**
		 * @brief Get the last course at or before the given entry
		 * @param Entry Timestamp specifying the desired time
		 */
		SmartNum get(const Entry &e) const;

		/**
		 * @brief Parses a given file as database or input
		 * @param name File name, as pure name, relative or absolute path
		 * @param mode enum specyifing if file is database or input
		 */
		int parseFile(const char *name, FileType mode);
	
	private:
		/**
		 * @brief Takes a line of content and turns it into Entry and Value
		 * @param line contains the information to parse
		 * @param seps String of 3 seperators, between each field in order
		 * @param e Timestamp for this entry
		 * @param num Value at that timestamp
		 */
		int	parseLine(const std::string &line, std::string seps, Entry &e, SmartNum &num);

		/**
		 * @brief Parses all data in a filestream
		 * @param in Filestream to read from
		 * @param mode enum specyifing if file is database or input
		 */
		void parseContent(std::ifstream &in, FileType mode);
};


// Outputting : ---------------------------------------------------------------


std::ostream &operator<<(std::ostream &out, const Entry &entry);

std::ostream &operator<<(std::ostream &out, const SmartNum &num);

std::ostream &operator<<(std::ostream &out, const std::map<Entry, SmartNum> &mapping);

// std::ostream &operator<<(std::ostream &out, const BitcoinExchange &btc);

#endif