/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:38:48 by sikunne           #+#    #+#             */
/*   Updated: 2025/11/05 14:24:06 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <utility>
#include <list>

void ft_swap(int &pos1, int &pos2);

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
		/**
		 * @brief Puts the number from <pos> left, to <to>, shifting the rest right
		 * @param pos Index of the number to move, last position to be shifted
		 * @param to Index of the position to move <pos> to
		 * @note If <position> is left of <to>, or exceeds list size, nothing happens
		 */
		static void push_before(int pos, int to, std::vector<int> &list);

		/**
		 * @brief Insert number from array into a sorted range
		 * @param pos is the position of the number in the array, that you want to insert/move
		 * @param from is the index of the start of the sorted range (inclusive)
		 * @param to is the index of the end of the sorted range (inclusive)
		 * @param list is the array/list to service
		 * 
		 * @warning <pos>, <to> and <from> have to be valid indices in list
		 * @warning <pos> > to >= from
		 */
		static void insert(unsigned int pos, unsigned int from, unsigned int to, std::vector<int> &list);

		/**
		 * @brief Sorts list into ascending pairs
		 */
		static void sortPairs(std::vector<int> &list);

		/**
		 * @brief Recursively call merge_sort on the larger elements
		 */
		static void recur(std::vector<int> &list, std::vector<int> &cpy);

		// O(n)
		/**
		 * @brief Return the pair from the list of pairs with the specified larger element
		 * @param list vector of pairs, containing all elements
		 * @param goal Larger element to search for
		 * @returns Pair containing the specified larger element
		 */
		static std::pair<int, int> pos_of(std::vector<std::pair<int, int> > &list, int goal);

		// likely closer to O(n^2), due to calling O(n) n times
		static std::vector<int> readjust_list(std::vector<int> &list, std::vector<int> &sort, std::vector<std::pair<int, int> > &pairs);

	public:
		/**
		 * @brief Merge-Insertion-Sort Algorithm using vectors
		 */
		static void merge_sort(std::vector<int> &list);

		/**
		 * @brief Checks if List is sorted
		 */
		static bool isSorted(const std::vector<int> &list);
};

class ListSort
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

