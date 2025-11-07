/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:15:26 by sikunne           #+#    #+#             */
/*   Updated: 2025/11/07 18:15:27 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Good Containers:
// deque	O(1) Insertion/Deletion at end

// Used Containers:
// std::stack, std::deque

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid Arg Count, only one please" << std::endl;
		return (0);
	}

	RpnCaller rpn;
	std::string error;
	int result;

	result = rpn.handle(argv[1]);
	error = rpn.getError();
	if (error.size() != 0)
		std::cout << error << std::endl;
	else
		std::cout << "Result: " << result << std::endl;
	return (0);
}