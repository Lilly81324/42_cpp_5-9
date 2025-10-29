/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:27:47 by sikunne           #+#    #+#             */
/*   Updated: 2025/10/29 17:46:02 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>
#include <vector>
#include <deque>

template<typename T>
class MutantStack: public std::stack<T>
{
	public:
		// Available in stack, redeclare here to preceed Templates
		typedef typename std::stack<T>::container_type			container_type;
		typedef typename std::stack<T>::value_type				value_type;
		typedef typename std::stack<T>::size_type				size_type;
		typedef typename std::stack<T>::reference				reference;
		typedef typename std::stack<T>::const_reference			const_reference;
		// Not available in stack, BUT available in stacks container
		typedef typename container_type::iterator				iterator;
		typedef typename container_type::const_iterator			const_iterator;
		typedef typename container_type::reverse_iterator		reverse_iterator;
		typedef typename container_type::const_reverse_iterator	const_reverse_iterator;

		iterator begin()
			{ return this->c.begin(); }
		iterator end()
			{ return this->c.end(); }

		const_iterator begin() const
			{ return this->c.begin(); }
		const_iterator end() const
			{ return this->c.end(); }

		reverse_iterator rbegin()
			{ return this->c.rbegin(); }
		reverse_iterator rend()
			{ return this->c.rend(); }

		const_reverse_iterator rbegin() const
			{ return this->c.rbegin(); }
		const_reverse_iterator rend() const
			{ return this->c.rend(); }
};

#endif 

// Notes:
// Relational Operators on containers
// == true,		if all elements equal AND equal size
// <  true,		if first unequal elements are <, OR all values are equal and a is smaller size
// >  true,		if first unequal elements are >, OR all values are equal and b is smaller size
// <= Negation of >
// >= Negation of <
// != Negation of ==