/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:43:52 by sikunne           #+#    #+#             */
/*   Updated: 2025/09/03 13:12:03 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T1, typename T2>
void iter(T1 *array, T2 maxLength, void (*function)(T1))
{
	T2 length = 0;
	
	while (length < maxLength)
	{
		function(array[length]);
		length++;
	}
}

#endif