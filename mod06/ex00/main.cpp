/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:30:18 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/22 17:11:11 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	int	i = 0;
	while (++i < argc)
	{
		if (i > 1)
			std::cout << "------------" << std::endl;
		ScalarConverter::convert(argv[i]);
	}
	return (0);
}
