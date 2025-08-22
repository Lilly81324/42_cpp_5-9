/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConverterUtil.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:13:02 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/22 17:09:02 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTERUTIL_HPP
# define CONVERTERUTIL_HPP

# include <string>
# include <limits>
# include <iostream>

# ifndef CHAR_MAX
#  define CHAR_MAX 127
#endif
# ifndef CHAR_MIN
#  define CHAR_MIN 0
#endif
# ifndef INT_MAX
#  define INT_MAX 2147483647
#endif
# ifndef INT_MIN
#  define INT_MIN -2147483648
#endif

# define CHAR_NON_DISP "Non displayable"
# define CONVERSION_IMPOSSIBLE "impossible"

class ConverterUtil
{
	private:
		ConverterUtil(void);
		ConverterUtil(const ConverterUtil& other);
		~ConverterUtil(void);
		ConverterUtil &operator=(const ConverterUtil &other);
	public:
		static std::string strToChar(const std::string &input, char &result);
		static std::string strToInt(const std::string &input, int &result);
		static std::string strToFloat(const std::string &input, float &result);
		static std::string strToDouble(const std::string &input, double &result);
};

#endif