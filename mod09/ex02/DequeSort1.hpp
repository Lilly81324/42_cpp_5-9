#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <utility>
#include <deque>

/**
 * Stat sheet:
 * 4000		=	  .26s
 * 7800		=	 1.00s
 * 10000	=	 1.68s
 * 20000	=	 6.70s
 * 30000	=	15.11s
 * Result = wow, this is garbage
 */
class DequeSort
{
	private:
		// O(n)
		static void push_before(int pos, int to, std::deque<int> &list);

		static void	ft_swap(int &pos1, int &pos2);

		static void insert(int num, unsigned int from, unsigned int to, std::deque<int> &list);

		// O(n)
		static void sortPairs(std::deque<int> &list);


		static void recur(std::deque<int> &list, std::deque<int> &cpy);

		// O(n)
		static unsigned int pos_of(std::deque<int> &list, int goal);

		// likely closer to O(n^2), due to calling O(n) n times
		static std::deque<int> readjust_list(std::deque<int> &list, std::deque<int> &sort);

	public:
		static void merge_sort(std::deque<int> &list);

		static bool isSorted(const std::deque<int> &list);
};

#endif

