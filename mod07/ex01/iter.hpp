/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:43:52 by sikunne           #+#    #+#             */
/*   Updated: 2025/10/17 16:22:09 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

/**
 * @brief Iterates over array, applying a function on each element
 * @param array Array to iterate over, holds nodes to use function on
 * @param maxLength Amount of Elements to iterate on 
 * @param function Function to apply on each node of our array
 * @warning Amount of elements must be less or equal to size of array
 */
template <typename T1>
void iter(T1 *array, const int maxLength, void (*function)(T1 &))
{
	int length = 0;
	
	if (array == NULL || function == NULL)
		return ;
	while (length < maxLength)
	{
		function(array[length]);
		length++;
	}
}

#endif