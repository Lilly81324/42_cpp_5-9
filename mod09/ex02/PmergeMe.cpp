/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:38:11 by sikunne           #+#    #+#             */
/*   Updated: 2025/11/05 14:22:44 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	ft_swap(int &pos1, int &pos2)
{
	int temp;
	temp = pos1;
	pos1 = pos2;
	pos2 = temp;
}

void jump2(std::list<int>::const_iterator &it)
{
	it++;
	it++;
}

void jump2(std::list<int>::iterator &it)
{
	it++;
	it++;
}

void VectorSort::push_before(int pos, int to, std::vector<int> &list)
{
	// This code is redundant, because you should never call this with bad input!
	if (pos <= to || pos > (int)list.size() - 1)
		return ;
	// ---------------------
	int temp = list[pos];
	while (pos > to)
	{
		pos--;
		list[pos + 1] = list[pos];
	}
	list[pos] = temp;
}

void VectorSort::insert(unsigned int pos, unsigned int from, unsigned int to, std::vector<int> &list)
{
	unsigned int mid = (from + to) / 2;
	// Position found
	if (to - from <= 1)
	{
		// if before start, push to start
		if (list[pos] < list[from])
			push_before(pos, from, list);
		// if before end, push to end
		else if (list[pos] < list[to])
			push_before(pos, to, list);
		// bigger then end, push just after end
		else
			push_before(pos, to + 1, list);
			// this could in theory exceed the limit, but in practice, should never
	}
	// Element has to go in left half
	else if (list[mid] > list[pos])
		insert(pos, from, mid, list);
	else
		insert(pos, mid, to, list);
}

void VectorSort::sortPairs(std::vector<int> &list)
{
	unsigned int size = list.size();
	for (unsigned int i = 0; i + 1 < size; i += 2)
	{
		if (list[i] > list[i + 1])
			ft_swap(list[i], list[i + 1]);
	}
}

void VectorSort::recur(std::vector<int> &list, std::vector<int> &cpy)
{
	// Make list of every odd position
	unsigned int end = list.size();
	for (unsigned int i = 1; i < end; i += 2)
		cpy.push_back(list[i]);
	merge_sort(cpy);
}

bool VectorSort::isSorted(const std::vector<int> &list)
{
	std::vector<int>::const_iterator it = list.begin();
	std::vector<int>::const_iterator next = list.begin();
	std::vector<int>::const_iterator end = list.end();

	for (; next != end; next++)
	{
		if (*it > *next)
			return (false);
		it = next;
	}
	return (true);
}

// This is the biggest issue and takes the 98.6% of the time (outdated and cut in half)
std::pair<int, int> VectorSort::pos_of(std::vector<std::pair<int, int> > &list, int goal)
{
	unsigned int end = list.size();
	unsigned int i = 0;
	
	for (; i < end; i++)
	{
		if (list[i].second == goal)
			return (list[i]);
	}
	return (list[0]);
}

std::vector<int> VectorSort::readjust_list(std::vector<int> &list, std::vector<int> &sort, std::vector<std::pair<int, int> > &pairs)
{
	std::vector<int> newer;
	newer.reserve(list.size());
	std::pair<int, int> entry;

	// Go through all sorted numbers
	entry = pos_of(pairs, sort[0]);
	newer.push_back(entry.first);
	newer.push_back(entry.second);
	int i = 1;
	int end = sort.size();
	for (; i < end; i++)
	{
		// Get the current number from sort and its position in list
		entry = pos_of(pairs, sort[i]);
		newer.push_back(entry.first);
		insert(newer.size() - 1, 0, newer.size() - 2, newer);
		newer.push_back(entry.second);
	}
	i = newer.size();
	// Insert the rest of the unsorted numbers
	for (; i < (int)list.size(); i++)
	{
		newer.push_back(list[i]);
		insert(newer.size() - 1, 0, newer.size() - 2, newer);
	}
	return (newer);
}

void VectorSort::merge_sort(std::vector<int> &list)
{
	std::vector<int> sort;
	std::vector<std::pair<int, int> > pairs;

	sortPairs(list);
	if (isSorted(list))
		return ;
	for (int i = 0; i + 1 < (int)list.size(); i += 2)
	{
		pairs.push_back(std::pair<int, int>(list[i], list[i + 1]));
	}
	recur(list, sort);
	list = readjust_list(list, sort, pairs);
}