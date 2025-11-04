#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <utility>
#include <deque>

extern double g_searchtime;
extern double g_insertime;
extern double g_pbacktime;
extern double g_swaptime;
extern struct timeval g_last_stamp;

/**
 * Stat sheet:
 * 20000	= 	  .26s
 * 40000	=	 1.00s
 * 80000	=	 4.09s
 * 100000	=	 6.32s
 * 150000	=	14.30s
 */
class Sort
{
	private:
		// O(n)
		static void push_before(int pos, int to, std::vector<int> &list);

		static void	ft_swap(int &pos1, int &pos2);

		// O(n)
		static void insert(unsigned int pos, unsigned int from, unsigned int to, std::vector<int> &list);

		// O(n)
		static void sortPairs(std::vector<int> &list);


		static void recur(std::vector<int> &list, std::vector<int> &cpy);

		// O(n)
		static unsigned int pos_of(std::vector<int> &list, int goal);

		// likely closer to O(n^2), due to calling O(n) n times
		static std::vector<int> readjust_list(std::vector<int> &list, std::vector<int> &sort);

	public:
		static void merge_sort(std::vector<int> &list);

		static bool isSorted(const std::vector<int> &list);
};

#endif

