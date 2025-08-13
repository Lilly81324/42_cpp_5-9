/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntMath.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:43:29 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/13 18:01:25 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTMATH_HPP
# define INTMATH_HPP

# include <string>

# define CONVERSION_IMPOSSIBLE "impossible"
# ifndef MAX_INT
#  define MAX_INT 2147483647
# endif
# ifndef ABS_MIN_INT
#  define ABS_MIN_INT 2147483648
# endif

class IntMath
{
	public:
		/**
		 * @returns true if number is a digit from 0-9
		 * @returns false otherwise
		 */
		static bool	isdigit(char number);

		/**
		 * Convert String to Integer
		 * @param inp: Input string to convert
		 * @param output: Number to give out
		 * @returns Error message if failure, or "" if nominal
		 * [OPT:sign] [REQ:digit(s)] [OPT:dot[REQ:digit(s)][REQ:f or F]] [REQ:\0]
		 * Any misconfiguration results in CONVERSION_IMPOSSIBLE
		 */
		static std::string atoi(const std::string &inp, int &output);
};

#endif