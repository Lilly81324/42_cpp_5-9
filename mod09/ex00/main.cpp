/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:56:18 by sikunne           #+#    #+#             */
/*   Updated: 2025/11/07 15:41:30 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Args: 1 compare_to_file.txt, (optional)database.csv
// If no database given, use default database
// If not default -> error

// Load csv into container
// Get target file
// Take target files line
// Get best fitting entry for this in container
// Get value of that entry
// Multiply that value by the given value ofr the specified date
// Output date and result

// Available:
// map
// multiset
// multimap
// queue
// priority_queue

// Good Containers:
// map		for storing and searching by date
// custom cont for value, so it can be int or float (maybe template instead)


int main(int argc, char **argv)
{
	std::string fileName;
	BitcoinExchange btc;
	int error;

	// Parse database as optional second parameter
	if (argc < 3 || argv[2] == NULL)
		error = btc.parseDatabase("./data.csv");
	else
		error = btc.parseDatabase(argv[2]);
	if (error)
		return (0);

	// Parse input file as first parameter
	if (argc < 2 || argv[1] == NULL)
		error = btc.parseInputLine("2025-11-7 | 1");
	else
		error = btc.parseInput(argv[1]);
	if (error)
		return (0);
	// std::cout << btc << std::endl;

	return (0);
}