/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:56:01 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/19 14:56:01 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int main(void)
{
	Data lel("Lel", 131, true);
	Data defau;
	std::cout << lel << std::endl;
	std::cout << defau << std::endl;
	return (0);
}