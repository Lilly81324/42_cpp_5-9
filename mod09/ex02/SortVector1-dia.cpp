
# include "SortVector1.hpp"
#include <sys/time.h>
#include <iostream>

void logTime(double *store)
{
	struct timeval present;
	gettimeofday(&present, 0);
	long s = present.tv_sec - g_last_stamp.tv_sec;
	long micros = present.tv_usec - g_last_stamp.tv_usec;
	
	if (micros < 0)
	{
		micros += 1000000;
		s -= 1;
	}
	
	*store += (double)s + ((double)micros / (double)1000000);
}

/**
 * @brief Puts the number from <pos> left, to <to>, shifting the rest right
 * @param pos Index of the number to move, last position to be shifted
 * @param to Index of the position to move <pos> to
 * @note If <position> is left of <to>, or exceeds list size, nothing happens
 */
void Sort::push_before(int pos, int to, std::vector<int> &list)
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

/**
 * Use swap(list[i], list[i + 1])
 */
void	Sort::ft_swap(int &pos1, int &pos2)
{
	gettimeofday(&g_last_stamp, 0);
	int temp;
	temp = pos1;
	pos1 = pos2;
	pos2 = temp;
	logTime(&g_swaptime);
}

/**
 * @brief Insert number from array into a sorted range
 * @param pos is the position of the number in the array, that you want to insert/move
 * @param from is the index of the start of the sorted range (inclusive)
 * @param to is the index of the end of the sorted range (inclusive)
 * @param list is the array/list to service
 * 
 * @warning <pos>, <to> and <from> have to be valid indices in list
 * @warning <pos> > to >= from
 */
void Sort::insert(unsigned int pos, unsigned int from, unsigned int to, std::vector<int> &list)
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

void Sort::sortPairs(std::vector<int> &list)
{
	unsigned int size = list.size();
	for (unsigned int i = 0; i + 1 < size; i += 2)
	{
		if (list[i] > list[i + 1])
			ft_swap(list[i], list[i + 1]);
	}
}

void Sort::recur(std::vector<int> &list, std::vector<int> &cpy)
{
	// Make list of every odd position
	unsigned int end = list.size();
	for (unsigned int i = 1; i < end; i += 2)
		cpy.push_back(list[i]);
	merge_sort(cpy);
}

bool Sort::isSorted(const std::vector<int> &list)
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

// This is the biggest issue and takes the 98.6% of the time
unsigned int Sort::pos_of(std::vector<int> &list, int goal)
{
	gettimeofday(&g_last_stamp, 0);
	unsigned int end = list.size();
	unsigned int i = 0;
	
	for (; i < end; i++)
	{
		if (list[i] == goal)
		{
			logTime(&g_searchtime);
			return (i);
		}
	}
	logTime(&g_searchtime);
	return (0);
}

std::vector<int> Sort::readjust_list(std::vector<int> &list, std::vector<int> &sort)
{
	std::vector<int> newer;
	newer.clear();
	newer.reserve(list.size());
	unsigned int index;

	// Go through all sorted numbers
	int end = sort.size();
	index = pos_of(list, sort[0]);
	gettimeofday(&g_last_stamp, 0);
		newer.push_back(list[index - 1]);
		newer.push_back(list[index]);
	logTime(&g_pbacktime);
	int i = 1;
	for (; i < end; i++)
	{
		// Get the current number from sort and its position in list
		index = pos_of(list, sort[i]);
		gettimeofday(&g_last_stamp, 0);
			newer.push_back(list[index - 1]);
		logTime(&g_pbacktime);
		gettimeofday(&g_last_stamp, 0);
			insert(newer.size() - 1, 0, newer.size() - 2, newer);
		logTime(&g_insertime);
		gettimeofday(&g_last_stamp, 0);
			newer.push_back(list[index]);
		logTime(&g_pbacktime);
	}
	i = newer.size();
	// Insert the rest of the unsorted numbers
	for (; i < (int)list.size(); i++)
	{
		gettimeofday(&g_last_stamp, 0);
			newer.push_back(list[i]);
		logTime(&g_pbacktime);
		gettimeofday(&g_last_stamp, 0);
			insert(newer.size() - 1, 0, newer.size() - 2, newer);
		logTime(&g_insertime);
	}
	return (newer);
}

void Sort::merge_sort(std::vector<int> &list)
{
	if (isSorted(list))
		return ;
	std::vector<int> sort;
	sortPairs(list);
	if (isSorted(list))
		return ;
	recur(list, sort);
	list = readjust_list(list, sort);
}

// Things we need to do:
// - Access elements as we move through
// - Delete elements

// Traits we are looking for:
// - Quick access of values (for comparisons)
// - Deletion of elements at any position (for removing used numbers from our unsorted list, when creating a new sorted list)
