/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharConverter.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:08:22 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/14 17:14:54 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARCONVERTER_HPP
 #define CHARCONVERTER_HPP

 #ifndef CONVERSION_IMPOSSIBLE
#  define CONVERSION_IMPOSSIBLE "impossible"
# endif

# include <string>

class CharConverter
{
	public:
		CharConverter(void);
		CharConverter(const std::string &input);
		CharConverter(const CharConverter &other);
		CharConverter &operator=(const CharConverter &other);
		~CharConverter(void);
		void	setInput(const std::string &input);
		std::string	asCharLiteral(void);
		void	convChar(void);
		char	getChar(void);
	private:
		std::string	_in;
	protected:
		char		_cval;
		std::string	_cerr;
};

#endif