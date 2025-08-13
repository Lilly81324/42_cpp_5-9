/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloatMath.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:50:48 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/13 18:00:51 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOATMATH_HPP
# define FLOATMATH_HPP

# include <string>
# include "IntMath.hpp"

class FloatMath
{
	public:
		/** OUTDATED
		 * Convert String to Float
		 * @param inp: Input string to convert
		 * @param output: Number to give out
		 * @returns Error message if failure, or "" if nominal
		 * [OPT:sign] [REQ:digit(s)] [OPT:dot[REQ:digit(s)][REQ:f or F]] [REQ:\0]
		 * Any misconfiguration results in CONVERSION_IMPOSSIBLE
		 */
		static std::string atof(const std::string &inp, float &outf, double &outd);
};

#endif