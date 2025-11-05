#include "SortList1.hpp"
#include <sys/time.h>
#include <iostream>

// Must use merge-insert algorythm to sort uints

// Handle at least 3000 elements

// Use 2 containers to sort the numbers

// Good Containers:
// multiset / set -> Does not use merge-insert sort?

double g_searchtime = 0.0;
double g_insertime = 0.0;
double g_pbacktime = 0.0;
double g_swaptime = 0.0;
struct timeval g_last_stamp;

void print_duration(timeval present, timeval past)
{
	long s = present.tv_sec - past.tv_sec;
	long micros = present.tv_usec - past.tv_usec;

	if (micros < 0)
	{
		micros += 1000000;
		s -= 1;
	}

	std::cout << "Time passed: " << s << " seconds, " << micros << " microseconds (" \
		<< ((double)s + ((double)micros / (double)1000000)) << "s)" << std::endl;
}


void test_result(const std::string &line, const timeval &past)
{
	struct timeval present;
	gettimeofday(&present, 0);
	std::cout << line << std::endl;
	print_duration(present, past);
	std::cout << "Swapped for          " << g_swaptime << std::endl;
	std::cout << "Inserted for         " << g_insertime << std::endl;
	std::cout << "Pushed back for      " << g_pbacktime << std::endl;
	std::cout << "Searched pos_of for  " << g_searchtime << std::endl;
}

int main(void)
{
	struct timeval past;
	std::vector<int> vec;
	(void)g_searchtime;
	(void)g_insertime;
	(void)g_pbacktime;
	(void)g_swaptime;
	(void)g_last_stamp;
	for (int i = 40000; i >= 0; i--)
		vec.push_back(i);
	gettimeofday(&past, 0);
	VectorSort::merge_sort(vec);
	if (!Sort::isSorted(vec))
		std::cout << "Not sorted! Failure!" << std::endl;
	test_result("DequeSort1", past);
	return 0;
}


// Sucks ass, because its O(n) unlike Random access
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

void ListSort::sortPairs(std::list<int> &list)
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
		jump2(it);
		jump2(next);
	}
	merge_sort(cpy);
}

bool ListSort::isSorted(const std::list<int> &list)
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
		jump2(it);
		jump2(next);
	}
	return (list.end());
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

void ListSort::merge_sort(std::list<int> &list)
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


// Compare everything in pairs
// Swap, so larger is second
// Sort the larger elements

// 1 9 3 5 7 4
// 1 9 | 3 5 | 7 4
// 1 9 | 3 5 | 4 7
// 9 5 7
// 9 5 | 7
// 5 9 | 7
// 5 7 9
// 1  5  3  7  4  9
// b1 a1 b2 a2 b3 a3

// insert b3 in b1, a1,a2

// 1 5 7 insert 4
// 1 4 5 7

// insert b2 at left of a2

// 1 4 5 7 3 4 9
// 1 3 4 5 7 9


// If odd length, ignore last element until end
// 1) Compare and sort each pair (pos0 and pos1, pos2 and pos3, etc.)
// 2) Call Merge Insertion Sort on every second element (bigger one)
// The first two elements will now be sorted
// Create Variable UnEl = Index of the first unsorted element, which is now 2
// 3) Use *Insertion* to insert number in the elements before UnEl (0, 1, 2)
// This will move UnEl by 1
// 4) Insert UnEl + 2 in the chain before UnEl
// This will move Unel by 1 + 2
// Repeat once more
// 
// 5) Compare pos10 to pos4, then either pos2 or pos4, then either pos1, pos3 or pos5
// 6) Do the same for what used to be pos7
// 7) Insert any stragglers

// Insertion:
// Get middlemost position
// Compare current element to it
// "Cut" list in half, at the middle (inclusive)
// Repeat insertion in this new halfed list

// We have a sorted tail (left) of numbers
// This tail goes from the leftmost position (start)
// to the end of