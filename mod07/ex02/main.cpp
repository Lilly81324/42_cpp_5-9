/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:24:44 by sikunne           #+#    #+#             */
/*   Updated: 2025/09/15 19:40:50 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

enum STATE
{
	ON,
	OFF,
	ERROR
};

template<typename T>
std::ostream &operator<<(std::ostream &out, Array<T> &arr)
{
	unsigned int i = 0;
	unsigned int limit;

	if (arr.content == NULL)
		limit = 0;
	else
		limit = arr.size();
	while (i < limit)
	{
		out << arr[i] << " ";
		i++;
	}
	return (out);
}

int main(void)
{
	{
		std::cout << "---===Default Constructor===---" << std::endl;
		Array<int> arr;
		// try
		// {
		// 	arr[3] = 0;
		// }
		// catch(const std::exception& e)
		// {
		// 	std::cerr << e.what() << '\n';
		// }
		std::cout << arr << std::endl;
	}
	{
		std::cout << "---===Different Constructors===---" << std::endl;
		Array<int> arr1(4);
		Array<int> arr2(0);
		Array<int> arr3(arr1);
		std::cout << "---===Integer Asignements===---" << std::endl;
		arr2[0] = 3;
		arr2[1] = 4;
		arr2[2] = 5;
		arr2[3] = 6;
		std::cout << "---===Outputting===---" << std::endl;
		std::cout << arr1 << std::endl;
		std::cout << arr2 << std::endl;
		std::cout << arr3 << std::endl;
	}
	{
		Array<std::string> arr(3);
		arr[0] = "Hello";
		arr[1] = "World";
		arr[2] = "!";
		std::cout << arr << std::endl;
		try
		{
			arr[100] = "No.";
		}
		catch(const Array<std::string>::IndexOutOfBounds& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	// {
	// 	Array<STATE> arr(3);
	// 	arr[0] = ERROR;
	// 	arr[1] = OFF;
	// 	arr[2] = ON;
	// 	std::cout << arr << std::endl;
	// }
	return (0);
}
