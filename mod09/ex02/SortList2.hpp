#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <list>
#include <utility>
#include <deque>
#include <list>

/**
 * Deletes used elements from unsorted list
 * Stat sheet:
 * minimally worse then version 1
 */
class Sort
{
	private:
		// O(n)
		static void push_before(int pos, int to, std::list<int> &list);

		static void	ft_swap(int &pos1, int &pos2);

		// O(n)
		static void insert(int num, std::list<int>::iterator to, std::list<int> &list);

		// O(n)
		static void sortPairs(std::list<int> &list);


		static void recur(std::list<int> &list, std::list<int> &cpy);

		// O(n)
		static std::list<int>::iterator pos_of(std::list<int> &list, int goal);

		// likely closer to O(n^2), due to calling O(n) n times
		static std::list<int> readjust_list(std::list<int> &list, std::list<int> &sort);

	public:
		static void merge_sort(std::list<int> &list);

		static bool isSorted(const std::list<int> &list);
};

#endif

