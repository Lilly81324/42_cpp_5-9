#include "SortVector2.hpp"
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
	for (int i = 20000; i >= 0; i--)
		vec.push_back(i);
	gettimeofday(&past, 0);
	Sort::merge_sort(vec);
	if (!Sort::isSorted(vec))
		std::cout << "Not sorted! Failure!" << std::endl;
	test_result("DequeSort1", past);
	return 0;
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