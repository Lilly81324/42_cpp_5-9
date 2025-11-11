/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:38:11 by sikunne           #+#    #+#             */
/*   Updated: 2025/11/11 14:24:53 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template<typename T>
void	ft_swap(T &pos1, T &pos2)
{
	T temp;
	temp = pos1;
	pos1 = pos2;
	pos2 = temp;
}

VectorSort::VectorSort(void)
{ }

VectorSort::VectorSort(const VectorSort &other)
{
	*this = other;
}

VectorSort::~VectorSort(void)
{ }

VectorSort &VectorSort::operator=(const VectorSort &other)
{
	if (this == &other)
		return (*this);
	// no members to copy
	return (*this);
}

void print_pair(const CPair &p)
{
	for (int i = 0; i <= p.depth; i++)
	{
		std::cout << *(p.a1 + i) << " ";
	}
	for (int i = 0; i <= p.depth; i++)
	{
		std::cout << *(p.b1 + i) << " ";
	}
}

// Gotta recursively call with pairs of pairs of ...
// t is a pair(1)
// template<typename T>
// typename std::vector<std::pair<T, T> >	step12(std::vector<T> &list)
// {
// 	std::vector<std::pair<T, T> > vec2;

// 	for (size_t i = 0; i + 1 < list.size(); i += 2)
// 	{
// 		// Compare second.second.second....
// 		if (list[i].second > list[i + 1].second)
// 			// Manually swap entries themself
// 			ft_swap(list[i], list[i + 1]);

// 		// Add Entries to new vector
// 		vec2.push_back(std::make_pair(list[i], list[i + 1]));
// 	}

// 	std::cout << "Sort the pairs 2" << std::endl;

// 	for (typename std::vector<std::pair<T, T> >::iterator it = vec2.begin();
// 		it != vec2.end(); it++)
// 	{
// 		// Call this on actual entry
// 		print_pair(it->first);
// 		print_pair(it->second);
// 		std::cout << "|";
// 	}
// 	std::cout << std::endl;
// 	return (vec2);
// }

std::vector<CPair>	step2(std::vector<CPair> &list)
{
	std::vector<CPair> vec2;

	if (list.size() < 2)
		return (vec2);

	for (size_t i = 0; i + 1 < list.size(); i += 2)
	{
		vec2.push_back(CPair(list[i].b2, list[i + 1].b2, list[i].depth + 1));
	}

	std::cout << "Sort the pairs 2" << std::endl;

	for (std::vector<CPair>::iterator it = vec2.begin();\
		it != vec2.end(); it++)
	{
		print_pair(*it);
		std::cout << "| ";
	}
	std::cout << std::endl;
	return (vec2);
}

// Gotta recursively call with pairs of pairs of ...
std::vector<CPair>	step1(std::vector<int> &list)
{
	std::vector<CPair> vec2;
	for (size_t i = 0; i + 1 < list.size(); i += 2)
	{
		vec2.push_back(CPair(&(list[i]), &(list[i + 1]), 0));
	}

	std::cout << "Sort the pairs" << std::endl;

	for (std::vector<CPair>::iterator it = vec2.begin();\
		it != vec2.end(); it++)
	{
		print_pair(*it);
		std::cout << "| ";
	}
	std::cout << std::endl;
	return (vec2);
}

void VectorSort::merge_sort(std::vector<int> &list)
{
	std::vector<CPair> list2;
	std::vector<CPair> list3;

	list2 = step1(list);
	list3 = step2(list2);
	// step12(step12(step12(list2)));
}