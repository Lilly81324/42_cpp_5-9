/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloatMath.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:50:48 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/14 17:22:13 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOATMATH_HPP
# define FLOATMATH_HPP

# include <string>
# include "IntMath.hpp"

class FloatMath
{
	private:
		FloatMath(void);
		FloatMath(const FloatMath &other);
		FloatMath &operator=(const FloatMath &other);
		~FloatMath(void);
	public:
		static std::string atof(const std::string &inp, float &outf);
		static std::string atod(const std::string &inp, double &outd);
};

#endif