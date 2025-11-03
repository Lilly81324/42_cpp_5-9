#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <utility>
#include <deque>

class DequeSort
{
	private:
		// O(n)
		static void push_before(int pos, int to, std::deque<int> &list);

		static void	ft_swap(int &pos1, int &pos2);

		// O(n)
		static void insert(unsigned int pos, unsigned int from, unsigned int to, std::deque<int> &list);

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

