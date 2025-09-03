/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:49:25 by sikunne           #+#    #+#             */
/*   Updated: 2025/09/03 13:19:45 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template <typename T1>
void my_print(T1 param)
{
	std::cout << param << " ";
}

int main(void)
{
	{
		std::string arr[5] = {"Hello", "World.", "Do", "you", "copy?"};
		iter(arr, 5, my_print);
		std::cout << std::endl;
	}
	{
		int arr[4] = {1, 3, 5, 7};
		iter(arr, 4, )
	}
	return (0);
}
