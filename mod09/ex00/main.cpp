/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:56:18 by sikunne           #+#    #+#             */
/*   Updated: 2025/11/07 17:46:26 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Good Containers:
// map		for storing and searching by date
// custom	for value, so it can be int or float (maybe template instead)

// Used Containers:
// std::map

int main(int argc, char **argv)
{
	std::string fileName;
	BitcoinExchange btc;
	int error;

	// Parse database as optional second parameter
	// if (argc < 3 || argv[2] == NULL)
		error = btc.parseFile("./data.csv", DATABASE);
	// else
		// error = btc.parseFile(argv[2], DATABASE);
	if (error)
		return (0);

	// Parse input file as first parameter
	if (argc < 2 || argv[1] == NULL)
	{
		std::cout << "Error: No input file given as argument" << std::endl;
		return (0);
	}

	// Run Input File
	error = btc.parseFile(argv[1], INPUT_FILE);
	return (0);
}