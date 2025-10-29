/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:27:32 by sikunne           #+#    #+#             */
/*   Updated: 2025/10/29 18:41:13 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<typename T>
void testIterators(MutantStack<T> &a, const MutantStack<T> &const_a)
{
	std::cout << "\nIterate Front to back" << std::endl;
	typename MutantStack<T>::iterator end = a.end();
	typename MutantStack<T>::iterator it = a.begin();
	while (it != end)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	typename MutantStack<T>::const_iterator end2 = const_a.end();
	typename MutantStack<T>::const_iterator it2 = const_a.begin();
	while (it2 != end2)
	{
		std::cout << *it2 << " ";
		it2++;
	}
	(void)const_a;
	std::cout << "\n\nIterate Back to front" << std::endl;
	typename MutantStack<T>::reverse_iterator end3 = a.rend();
	typename MutantStack<T>::reverse_iterator it3 = a.rbegin();
	while (it3 != end3)
	{
		std::cout << *it3 << " ";
		it3++;
	}
	std::cout << std::endl;
	typename MutantStack<T>::const_reverse_iterator end4 = const_a.rend();
	typename MutantStack<T>::const_reverse_iterator it4 = const_a.rbegin();
	while (it4 != end4)
	{
		std::cout << *it4 << " ";
		it4++;
	}
	std::cout << std::endl;
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const MutantStack<T>& s)
{
	typename MutantStack<T>::const_iterator end = s.end();
	typename MutantStack<T>::const_iterator it = s.begin();
	while (it != end)
	{
		out << *it;
		it++;
		if (it != end)
			out << " ";
	}
	return (out);
}

int	testRelationalOperators(const MutantStack<int> &a, const MutantStack<int> &b)
{
	// Introduce our contestants
	std::cout << std::endl << "Testing: [" << a << "] against [" << b << "]" << std::endl;

	// Fill bitmask based on operations
	unsigned int result = 0;
	if (a == b)	result += 1 << 0;
	if (a != b)	result += 1 << 1;
	if (a <  b)	result += 1 << 2;
	if (a <= b)	result += 1 << 3;
	if (a >  b)	result += 1 << 4;
	if (a >= b)	result += 1 << 5;

	// Check bitmask for operations
	const std::string checks[6] = {"==", "!=", "< ", "<=", "> ", ">="};
	for (int i = 0; i < 6; i++)
	{
		std::cout << "[" << a << "] " << checks[i] << " [" << b << "] -> ";
		if (((result >> i) & 1) == 1)
			std::cout << "true" << std::endl;
		else
			std::cout << "false" << std::endl;
	}
	return (result);
}

// !! Important for Eval !!

// MutantStack	stack	list		vector		deque
// push			push	push_back	push_back	push_back
// top			top		back		back		back
// pop			pop		pop_back	pop_back	pop_back

// Stack takes only deque as Constructor, so another type needs to be specified like this:
// std::stack<int, std::list<int> > s(mstack);

int main()
{
	MutantStack<int> mstack;
	MutantStack<int> cpy;

	// push
	mstack.push(2);
	mstack.push(4);
	mstack.push(7);
	mstack.push(99);

	// empty()
	if (cpy.empty())
		std::cout << "Mutant Stack is empty" << std::endl;
	else
		std::cout << "Error!" << std::endl;

	// operator= and top()
	cpy = mstack;
	if (cpy.top() == mstack.top() && cpy.top() == 99)
		std::cout << "Copied MutantStack, " << cpy.top() << " at top" << std::endl;
	else
		std::cout << "Error!" << std::endl;

	// pop() and size
	mstack.pop();
	if (mstack.size() == 3 && cpy.size() == 4)
		std::cout << "MutantStack was popped" << std::endl;
	else
		std::cout << "Error!" << std::endl;

	// Iterators
	testIterators(cpy, cpy);

	// Relational Operators and std::swap
	testRelationalOperators(mstack, cpy);
	return (0);
}
