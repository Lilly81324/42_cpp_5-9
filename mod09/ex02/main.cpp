#include "PmergeMe.hpp"

// Must use merge-insert algorythm to sort uints

// Handle at least 3000 elements

// Use 2 containers to sort the numbers

// Good Containers:
// multiset / set -> Does not use merge-insert sort?

#include <iostream>

int main(void)
{
	std::vector<int> vec;
	std::vector<int *> vec1;
	vec.push_back(9);
	vec.push_back(8);
	vec.push_back(7);
	vec.push_back(6);
	vec.push_back(5);
	vec.push_back(4);
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(1);
	for (int i = 0; i < 9; i++)
	vec1.push_back(&(vec[i]));
		merge_sort(vec1);
	std::cout << vec[0] << vec[1] << vec[2] << std::endl;
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