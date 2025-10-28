/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:27:47 by sikunne           #+#    #+#             */
/*   Updated: 2025/10/28 18:52:59 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename T>
class MutantStack: public std::stack<T>
{
	public:
		// Available in stack, redeclare here to preceed Templates
		typedef typename std::stack<T>::container_type		container_type;
		typedef typename std::stack<T>::value_type			value_type;
		typedef typename std::stack<T>::size_type			size_type;
		typedef typename std::stack<T>::reference			reference;
		typedef typename std::stack<T>::const_reference		const_reference;
		// Not available in stack, BUT available in stacks container
		typedef typename container_type::iterator			iterator;
		typedef typename container_type::const_iterator		const_iterator;

		iterator begin()
			{ return this->c.begin(); }
		iterator end()
			{ return this->c.end(); }
		const_iterator begin() const
			{ return this->c.begin(); }
		const_iterator end() const
			{ return this->c.end(); }
};

#endif 
