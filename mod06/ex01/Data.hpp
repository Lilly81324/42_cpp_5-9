/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:33:28 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/19 14:33:28 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data
{
	private:
		std::string name;
		int value;
		bool active;
	public:
		Data(void);
		Data(const std::string &name, int value, bool active);
		Data(const Data &other);
		~Data(void);
		Data &operator=(const Data &other);
		std::string getName(void) const;
		int getValue(void) const;
		bool getActive(void) const;
};

std::ostream &operator<<(std::ostream &out, const Data &target);

#endif