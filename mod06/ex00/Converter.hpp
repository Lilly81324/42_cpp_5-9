/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:43:34 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/14 17:07:08 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
 #define CONVERTER_HPP

# include <string>

class Converter
{
	public:
		Converter(void);
		Converter(const std::string &input);
		Converter(const Converter &other);
		Converter &operator=(const Converter &other);
		~Converter(void);
		void	setInput(const std::string &input);
		void	Converter::convChar(void);
		void	convert(void);
	private:
		std::string	_in;
		char		_cval;
		std::string _cerr;
		int			_ival;
		std::string _ierr;
		float		_fval;
		std::string _ferr;
		double		_dval;
		std::string _derr;
};

#endif