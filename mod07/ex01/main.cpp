/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:49:25 by sikunne           #+#    #+#             */
/*   Updated: 2025/10/17 16:25:49 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template <typename T2>
void my_print(T2 param)
{
	std::cout << param << " ";
}

template <typename T3>
void multiply(T3 &a)
{
	a *= 10;
}

int main(void)
{
	// Printing values
	{
		std::string arr[5] = {"Hello", "World.", "Do", "you", "copy?"};
		iter(arr, 5, my_print);
		std::cout << std::endl;
	}
	// Printing and changing values
	{
		int arr[4] = {1, 3, 5, 7};
		iter(arr, 4, multiply);
		iter(arr, 4, my_print);
		std::cout << std::endl;
	}
	// Usage of const in array
	{
		int const arr[4] = {2, 4, 6, 8};
		// iter(arr, 4, multiply);
		iter(arr, 4, my_print);
		std::cout << std::endl;
	}
	return (0);
}
