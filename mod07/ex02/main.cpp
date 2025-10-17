/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:24:44 by sikunne           #+#    #+#             */
/*   Updated: 2025/10/17 17:36:38 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// Simple printing helper function
template<typename T>
std::ostream &operator<<(std::ostream &out, Array<T> &arr)
{
	unsigned int i = 0;
	unsigned int limit;

	limit = arr.size();
	out << "[";
	while (i < limit)
	{
		if (i != 0)
			out << " ";
		out << arr[i];
		i++;
	}
	out << "]";
	return (out);
}

int main(void)
{
	{
		// Create default Array
		std::cout << "---===Default Constructor===---" << std::endl;
		Array<int> arr;
		std::cout << "Size: " << arr.size() << std::endl;
		std::cout << arr << std::endl;
	}


	{
		// Create Arrays with custom sizes
		// Print them to make sure they are initialised on Construction
		// Then assign them and print the changes
		std::cout << std::endl << "---===Parameterized Constructors===---" << std::endl;
		Array<int> arr1(4);
		Array<int> arr2(0);
		std::cout << arr1 << "-> ";
		arr1[0] = 3;
		arr1[1] = 4;
		arr1[2] = 5;
		arr1[3] = 6;
		std::cout << arr1 << std::endl;
		std::cout << arr1 << std::endl;
		std::cout << arr2 << std::endl;
	}


	{
		// Create Array based off other Array, midway through asignment of the first
		// Then finish off the first to show that it is a deep copy
		std::cout << std::endl << "---===Copy Constructors===---" << std::endl;
		Array<int> arr1(4);
		arr1[0] = 1;
		arr1[1] = 1;
		Array<int> arr2(arr1);
		arr1[2] = 2;
		arr1[3] = 2;
		std::cout << arr1 << std::endl;
		std::cout << arr2 << std::endl;
	}


	{
		// Asignement testing
		Array<char> arr1(3);
		std::cout << std::endl << "---===Asignement Operator===---" << std::endl;
		arr1[0] = 'X';
		arr1[1] = 'Y';
		arr1[2] = 'Z';

		std::cout << "Setting empty array to template:" << std::endl;
		Array<char> arr2;
		std::cout << arr2 << " -> ";
		arr2 = arr1;
		std::cout << arr2 << std::endl;

		std::cout << "Setting filled array to template:" << std::endl;
		Array<char> arr3 (2);
		arr3[0] = 'A';
		arr3[1] = 'B';
		std::cout << arr3 << " -> ";
		arr3 = arr1;
		std::cout << arr3 << std::endl;

		std::cout << "Setting array to itself:" << std::endl;
		std::cout << arr3 << " -> ";
		arr3 = arr3 = arr3 = arr3 = arr3;
		std::cout << arr3 << std::endl;
	}


	{
		// Subscript Operator []
		std::cout << std::endl << "---===Subscript Operator===---" << std::endl;
		std::cout << "Accessing empty Array:" << std::endl;
		Array<int> arr1;
		try
		{
			arr1[3] = 0;
			std::cout << arr1 << std::endl;
		}
		catch(const Array<int>::IndexOutOfBounds& e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << "Accessing data after Array:" << std::endl;
		Array<int> arr2(1);
		try
		{
			arr2[1] = 0;
			std::cout << arr2 << std::endl;
		}
		catch(const Array<int>::IndexOutOfBounds& e)
		{
			std::cerr << e.what() << '\n';
		}
	}


	{
		// Size
		std::cout << std::endl << "---===Size Function===---" << std::endl;
		Array<std::string> arr1;
		std::cout << "Empty Array: " << arr1.size() << std::endl;

		Array<std::string> arr2 (2);
		std::cout << "2 Element Array: " << arr2.size() << std::endl;
	}
	return (0);
}
