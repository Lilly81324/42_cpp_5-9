
# include "PmergeMe.hpp"
#include <vector>

/**
 * @brief Puts the number from <pos> left, to <to>, shifting the rest right
 * @param pos Index of the number to move, last position to be shifted
 * @param to Index of the position to move <pos> to
 * @note If <position> is left of <to>, or exceeds list size, nothing happens
 */
void push_before(unsigned int pos, unsigned int to, std::vector<int> &list)
{
	// This code is redundant, because you should never call this with bad input!
	if (pos < to || pos > list.size() - 1)
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
void	ft_swap(int &pos1, int &pos2)
{
	int temp;
	temp = pos1;
	pos1 = pos2;
	pos2 = temp;
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
void insert(unsigned int pos, unsigned int from, unsigned int to, std::vector<int> &list)
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

void sortPairs(std::vector<int> &list)
{
	unsigned int size = list.size();
	for (unsigned int i = 0; i + 1 < size; i += 2)
	{
		if (list[i] > list[i + 1])
			ft_swap(list[i], list[i + 1]);
	}
}

/*
We take the element at UnIn + 2, and 
Check if its bigger then UnIn + 1
	Keep it where it is
Else
	Binary insert it between index 0 to UnIn-1
	Increase UnIn by 1 to keep it correct
Binary insert UnIn between index 0 to UnIn-1
 */
void cpy(std::vector<int> &list, std::vector<int> &cpy)
{
	// Make list of every odd position
	unsigned int end = list.size();
	for (unsigned int i = 1; i < end; i += 2)
		cpy.push_back(list[i]);
	merge_sort(cpy);
}

bool isSorted(const std::vector<int> &list)
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

void makePairs(std::vector<std::pair<int, int> > &pair, std::vector<int> &list)
{
	pair.clear();
	pair.reserve(list.size() / 2);
	unsigned int end = static_cast<unsigned int>(list.size());
	for (unsigned int i = 0; i + 1 < end; i += 2)
		pair.push_back(std::pair<int, int>(list[i], list[i + 1]));
}

std::pair<int, int> find_pair(int goal, std::vector<std::pair<int, int> > &pairs)
{
	std::vector<std::pair<int, int> >::iterator end = pairs.end();
	std::vector<std::pair<int, int> >::const_iterator it = pairs.begin();
	// Go through all pairs, and find this number
	for (; it != end; it++)
	{
		if (it->second == goal)
			return (std::pair<int, int>(it->first, it->second));
	}
	return (std::pair<int, int>(0, 0));
}

std::vector<int> readjust_list(std::vector<int> &list, std::vector<std::pair<int, int> > &pair, std::vector<int> &sort)
{
	unsigned int end = sort.size();
	// For all in pairs, except first one
	std::vector<int> newer;
	newer.clear();
	newer.reserve(list.size());
	unsigned int i = 1;
	for (; i < end; i++)
	{
		// Find the pairs for the sorted order
		std::pair<int, int> current;
		current = find_pair(sort[i], pair);
		// Add those back into the new array
		newer.push_back(current.first);
		newer.push_back(current.second);
	}
	// For the rest of the numbers
	i--;
	i *= 2;
	for (; i < (unsigned int)list.size(); i++)
	{
		newer.push_back(list[i]);
		insert(i, 0, newer.size() - 2, newer);
	}
	return (newer);
}

void merge_sort(std::vector<int> &list)
{
	unsigned int UnIn;
	unsigned int nextUnIn;

	if (isSorted(list))
		return ;
	std::vector<std::pair<int, int> > pairs;
	std::vector<int> sort;
	sortPairs(list);
	if (isSorted(list))
		return ;
	makePairs(pairs, list);
	cpy(list, sort);
	list = readjust_list(list, pairs, sort);

	// UnIn = 2;
	// while (list.size() >= UnIn + 3)
	// {
	// 	nextUnIn = UnIn + 4;
	// 	if (list[UnIn + 2] < list[UnIn + 1])
	// 	{
	// 		insert(UnIn + 2, 0, UnIn - 1, list);
	// 		UnIn++;
	// 	}
	// 	insert(UnIn, 0, UnIn - 1, list);
	// 	UnIn = nextUnIn;
	// }
}
