#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <utility>
#include <deque>

/**
 * Stat sheet:
 * 20000	= 	  .13s
 * 40000	=	  .50s
 * 80000	=	 2.05ss
 * 100000	=	 3.16s
 * 150000	=	 7.15s
 */
class VectorSort
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
		static std::pair<int, int> pos_of(std::vector<std::pair<int, int> > &list, int goal);

		// likely closer to O(n^2), due to calling O(n) n times
		static std::vector<int> readjust_list(std::vector<int> &list, std::vector<int> &sort, std::vector<std::pair<int, int> > &pairs);

	public:
		static void merge_sort(std::vector<int> &list);

		static bool isSorted(const std::vector<int> &list);
};

#endif

