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
#include "Serializer.hpp"

int main(void)
{
	Data *lel = new Data("Lel", 131, true);
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Original pointer adress:       [" << lel << "]" << std::endl;
	std::cout << "Original pointer value:        [" << *lel << "]" << std::endl;

	std::cout << "-----------------------------------------" << std::endl;
	uintptr_t ptr;
	ptr = Serializer::serialize(lel);
	std::cout << "Converted into uintptr_t:      [" << ptr << "]" << std::endl;
	std::cout << "in hexadecimal notation:       [0x" << std::hex << ptr << std::dec << "]" << std::endl;

	std::cout << "-----------------------------------------" << std::endl;
	Data *other;
	other = Serializer::deserialize(ptr);
	std::cout << "Re-converted pointer adress:   [" << other << "]" << std::endl;
	std::cout << "Re-converted pointer value:    [" << *other << "]" << std::endl;

	std::cout << "-----------------------------------------" << std::endl;
	if (lel == other)
		std::cout << "Both pointers are equal" << std::endl;
	delete lel;
	return (0);
}