
# include "SortList1.hpp"

// Sucks ass, because its O(n) unlike Random access
void Sort::insert(int num, std::list<int>::iterator to, std::list<int> &list)
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

void Sort::sortPairs(std::list<int> &list)
{
	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator next = list.begin();
	std::list<int>::iterator end = list.end();
	int temp;

	if (next != end)
		next++;
	while ( it != end && next != end)
	{

		if (*it > *next)
		{
			temp = *it;
			*it = *next;
			*next = temp;
		}
		jump2(it);
		jump2(next);
	}
}

void Sort::recur(std::list<int> &list, std::list<int> &cpy)
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
		jump2(it);
		jump2(next);
	}
	merge_sort(cpy);
}

bool Sort::isSorted(const std::list<int> &list)
{
	std::list<int>::const_iterator it = list.begin();
	std::list<int>::const_iterator next = list.begin();
	std::list<int>::const_iterator end = list.end();
	if (next != end)
		next++;

	for (; next != end; next++)
	{
		if (*it > *next)
			return (false);
		it = next;
	}
	return (true);
}

// Get the index to the lowest number in our list, for the specified bigger element
std::list<int>::iterator Sort::pos_of(std::list<int> &list, int goal)
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
		jump2(it);
		jump2(next);
	}
	return (list.end());
}

// Instead of making a new list, readjust the old one?
// remove used elements from old list?
// This: Make new list, keep old elements
std::list<int> Sort::readjust_list(std::list<int> &list, std::list<int> &sort)
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
		newer_pos++;
		newer_pos++;
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

void Sort::merge_sort(std::list<int> &list)
{
	std::list<int> sort;

	if (isSorted(list))
		return ;
	sortPairs(list);
	if (isSorted(list))
		return ;
	recur(list, sort);
	list = readjust_list(list, sort);
}
