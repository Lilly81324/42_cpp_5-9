/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:21:25 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/14 16:43:23 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include "IntMath.hpp"
# include "FloatMath.hpp"


# define CHAR_NON_DISP "Non displayable"

class ScalarConverter
{
	private:
		int		_ival;
		char	_cval;
		float	_fval;
		double	_dval;
	public:
		static void convert(const std::string &input);
};

#endif