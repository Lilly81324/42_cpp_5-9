/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:38:11 by sikunne           #+#    #+#             */
/*   Updated: 2025/11/05 18:39:46 by sikunne          ###   ########.fr       */
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

void VectorSort::sortPairs(std::vector<int> &list)
{
	unsigned int size = list.size();
	for (unsigned int i = 0; i + 1 < size; i += 2)
	{
		if (list[i] > list[i + 1])
			ft_swap(list[i], list[i + 1]);
	}
}

void ListSort::sortPairs(std::list<int> &list)
{
	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator next = list.begin();
	std::list<int>::iterator end = list.end();

	if (next != end)
		next++;
	while ( it != end && next != end)
	{

		if (*it > *next)
			ft_swap(*it, *next);
		next++;
		it = next;
		next++;
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

void ListSort::recur(std::list<int> &list, std::list<int> &cpy)
{
	std::list<int>::const_iterator it = list.begin();
	std::list<int>::const_iterator next = list.begin();
	std::list<int>::const_iterator end = list.end();

	if (next != end)
		next++;
	// Make list of every odd position
	while (it != end && next != end)
	{
		cpy.push_back(*next);
		next++;
		it = next;
		next++;
	}
	merge_sort(cpy);
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

// Sucks ass, because its O(n) unlike Random acces
void ListSort::insert(int num, std::list<int>::iterator to, std::list<int> &list)
{
	std::list<int>::iterator from = list.begin();
	if (num < *from)
	{
		list.push_front(num);
		return ;
	}
	else if (num > *to)
	{
		list.push_back(num);
		return ;
	}
	while (*from < num && *to > num)
	{
		from++;
		to--;
	}
	if (*from > num)
		list.insert(from, num);
	else // if (*to < num)
	{
		to++;
		list.insert(to, num);
	}
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

std::list<int>::iterator ListSort::pos_of(std::list<int> &list, int goal)
{
	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator next = list.begin();
	std::list<int>::iterator end = list.end();

	if (next != end)
		next++;
	// Check every odd position
	while (it != end && next != end)
	{
		if (*next == goal)
			return (it);
		next++;
		it = next;
		next++;
	}
	return (list.end());
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

// Instead of making a new list, readjust the old one?
// remove used elements from old list?
// This: Make new list, keep old elements
std::list<int> ListSort::readjust_list(std::list<int> &list, std::list<int> &sort)
{
	std::list<int> newer;
	std::list<int>::iterator lower;
	std::list<int>::iterator newer_pos;
	std::list<int>::iterator sort_pos;

	// First numer in sort -> Find it in list -> Find its child -> Add them to new
	sort_pos = sort.begin();
	lower = pos_of(list, *(sort_pos));
	newer.push_back(*lower);
	lower++;
	newer.push_back(*lower);
	sort_pos++;

	newer_pos = newer.end();
	newer_pos--;
	// Go through each number in sort, repeat the steps above with it
	for (; sort_pos != sort.end(); sort_pos++)
	{
		// Get the current number from sort and its position in list
		lower = pos_of(list, *(sort_pos));
		insert(*lower, newer_pos, newer);
 		lower++;
		newer.push_back(*lower);
		newer_pos = newer.end();
		newer_pos--;
	}

	// Insert the rest of the unsorted numbers
	if (newer.size() < list.size())
	{
		std::list<int>::iterator l_end = list.end();
		l_end--;
		insert(*l_end, newer_pos, newer);
	}
	return (newer);
}

void VectorSort::merge_sort(std::vector<int> &list)
{
	std::vector<int> sort;
	std::vector<std::pair<int, int> > pairs;

	sortPairs(list);
	if (list.size() <= 2)
		return ;
	for (int i = 0; i + 1 < (int)list.size(); i += 2)
		pairs.push_back(std::pair<int, int>(list[i], list[i + 1]));
	recur(list, sort);
	list = readjust_list(list, sort, pairs);
}

void ListSort::merge_sort(std::list<int> &list)
{
	std::list<int> sort;

	sortPairs(list);
	if (list.size() <= 2)
		return ;
	recur(list, sort);
	list = readjust_list(list, sort);
}
