
# include "SortDeque.hpp"

/**
 * Use swap(list[i], list[i + 1])
 */
void	Sort::ft_swap(int &pos1, int &pos2)
{
	int temp;
	temp = pos1;
	pos1 = pos2;
	pos2 = temp;
}

/**
 * @brief Insert number from array into a sorted range
 * @param num is the number to add
 * @param from is the index of the start of the sorted range (inclusive)
 * @param to is the index of the end of the sorted range (inclusive)
 * @param list is the array/list to service
 * 
 * @warning <pos>, <to> and <from> have to be valid indices in list
 * @warning <pos> > to >= from
 */
void Sort::insert(int num, unsigned int from, unsigned int to, std::deque<int> &list)
{
	unsigned int mid = (from + to) / 2;
	// Position found
	if (to - from <= 1)
	{
		// if before start, push to start
		std::deque<int>::iterator it = list.begin();
		if (num < list[from])
			list.insert(it + from, num);
		// if before end, push to end
		else if (num < list[to])
			list.insert(it + to, num);
		// bigger then end, push just after end
		else
			list.insert(it + to + 1, num);
			// this could in theory exceed the limit, but in practice, should never
	}
	// Element has to go in left half
	else if (list[mid] > num)
		insert(num, from, mid, list);
	else
		insert(num, mid, to, list);
}

// O(n) unavoidable, unless different algorithm used
// Use merge_sort maybe?
void Sort::sortPairs(std::deque<int> &list)
{
	unsigned int size = list.size();
	for (unsigned int i = 0; i + 1 < size; i += 2)
	{
		if (list[i] > list[i + 1])
			ft_swap(list[i], list[i + 1]);
	}
}

void Sort::recur(std::deque<int> &list, std::deque<int> &cpy)
{
	// Make list of every odd position
	unsigned int end = list.size();
	for (unsigned int i = 1; i < end; i += 2)
		cpy.push_back(list[i]);
	merge_sort(cpy);
}

// O(n) minimize calling this!
bool Sort::isSorted(const std::deque<int> &list)
{
	std::deque<int>::const_iterator it = list.begin();
	std::deque<int>::const_iterator next = list.begin();
	std::deque<int>::const_iterator end = list.end();
	if (next != end)
		next++;

	for (; next != end; next++)
	{
		if (*it >= *next)
			return (false);
		it = next;
	}
	return (true);
}

unsigned int Sort::pos_of(std::deque<int> &list, int goal)
{
	unsigned int end = list.size();
	unsigned int i = 0;
	
	for (; i < end; i++)
	{
		if (list[i] == goal)
			return (i);
	}
	return (0);
}

std::deque<int> Sort::readjust_list(std::deque<int> &list, std::deque<int> &sort)
{
	std::deque<int> newer;
	newer.clear();
	unsigned int index;

	// Go through all sorted numbers
	int end = sort.size();
	index = pos_of(list, sort[0]);
	newer.push_back(list[index - 1]);
	newer.push_back(list[index]);
	int i = 1;
	for (; i < end; i++)
	{
		// Get the current number from sort and its position in list
		index = pos_of(list, sort[i]);
		insert(list[index - 1], 0, newer.size() - 1, newer);
		newer.push_back(list[index]);
	}
	i = newer.size();
	// Insert the rest of the unsorted numbers
	for (; i < (int)list.size(); i++)
	{
		insert(list[i], 0, newer.size() - 1, newer);
	}
	return (newer);
}

void Sort::merge_sort(std::deque<int> &list)
{
	if (list.size() <= 2)
		return (sortPairs(list));
	std::deque<int> sort;
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
