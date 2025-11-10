/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:38:11 by sikunne           #+#    #+#             */
/*   Updated: 2025/11/10 18:49:54 by sikunne          ###   ########.fr       */
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

template<typename T>
void print_pair(const T &p)
{
	std::cout << p << " ";
}

template<typename T>
void print_pair(const CPair<T> &p)
{
	print_pair(p.first);
	print_pair(p.second);
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

template<typename T>
typename std::vector<CPair<T> >	step12(std::vector<T> &list)
{
	std::vector<CPair<T> > vec2;

	for (size_t i = 0; i + 1 < list.size(); i += 2)
	{
		vec2.push_back(CPair<T>(list[i], list[i + 1]));
	}

	std::cout << "Sort the pairs 2" << std::endl;

	for (typename std::vector<CPair<T> >::iterator it = vec2.begin();\
		it != vec2.end(); it++)
	{
		// Call this on actual entry
		print_pair(it->first);
		print_pair(it->second);
		std::cout << "|";
	}
	std::cout << std::endl;
	return (vec2);
}

// Gotta recursively call with pairs of pairs of ...
std::vector<CPair<int> >	step1(std::vector<int> &list)
{
	std::vector<CPair<int> > vec2;
	for (size_t i = 0; i + 1 < list.size(); i += 2)
	{
		if (list[i] > list[i + 1])
			ft_swap(list[i], list[i + 1]);
		vec2.push_back(CPair<int>(list[i], list[i + 1]));
	}

	std::cout << "Sort the pairs" << std::endl;

	for (std::vector<CPair<int> >::iterator it = vec2.begin();\
		it != vec2.end(); it++)
	{
		std::cout << it->first << " " << it->second << " ";
	}
	std::cout << std::endl;
	return (vec2);
}

void VectorSort::merge_sort(std::vector<int> &list)
{
	std::vector<CPair<int> > list2;
	std::vector<CPair<CPair<int> > > list3;

	list2 = step1(list);
	list3 = step12(list2);
	step12(list3);
}