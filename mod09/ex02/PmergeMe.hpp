/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:38:48 by sikunne           #+#    #+#             */
/*   Updated: 2025/11/07 18:15:47 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

// for main
#include <sys/time.h>
#include <iostream>
#include <iomanip>

// for containers needed
#include <vector>
#include <list>
#include <set>

void	ft_swap(int &pos1, int &pos2);

/**
 * Stat sheet: 
 * 3000		=	 0.01s
 * 10000	=	 0.10s
 * 20000	=	 0.39s
 * 40000	=	 1.45s
 * 80000	=	 5.95s
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
		 * @brief Binary insert number from array into a sorted range
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

		/**
		 * @brief Return the pair from the list of pairs with the specified larger element
		 * @param list vector of pairs, containing all elements
		 * @param goal Larger element to search for
		 * @returns Pair containing the specified larger element
		 */
		static int pos_of(std::vector<int> &list, int goal);

		/**
		 * @brief Create a new list based off the given pairs sorted by sort with the rest of list
		 * @param list List of all unsorted numbers
		 * @param sort List of the sorted higher elements of pairs
		 * @param pairs All full pairs of elements in unsorted numbers
		 * @returns a fully sorted vector of all that is inside list
		 */
		static std::vector<int> readjust_list(std::vector<int> &list, std::vector<int> &sort);

	public:
		/**
		 * @brief Merge-Insertion-Sort Algorithm using vectors
		 */
		static void merge_sort(std::vector<int> &list);
};

/**
 * Stat sheet:
 * 3000		=	 0.03s
 * 10000	=	 0.34s
 * 20000	=	 1.43s
 * 40000	=	 5.88s
 * 80000	=	24.85s
 */
class ListSort
{
	private:

		/**
		 * @brief Insert number from array into a sorted range
		 * @param num is the number to insert
		 * @param to is the index of the end of the sorted range (inclusive)
		 * @param list is the list to search through
		 * 
		 * @warning <to> has to be valid index in list
		 */
		static void insert(int num, std::list<int>::iterator to, std::list<int> &list);

		/**
		 * @brief Sorts list into ascending pairs
		 */
		static void sortPairs(std::list<int> &list);

		/**
		 * @brief Recursively call merge_sort on the larger elements
		 */
		static void recur(std::list<int> &list, std::list<int> &cpy);
		
		/**
		 * @brief Return the pair from the list of pairs with the specified larger element
		 * @param list list of all elements, arranged as pairs
		 * @param goal Larger element to search for
		 * @returns Iterator to the higher element
		 */
		static std::list<int>::iterator pos_of(std::list<int> &list, int goal);

		/**
		 * @brief Create a new list based off the given pairs in list sorted by sort
		 * @param list List of all unsorted numbers and pairs
		 * @param sort List of the sorted higher elements of pairs
		 * @returns a fully sorted list of all that is inside list
		 */
		static std::list<int> readjust_list(std::list<int> &list, std::list<int> &sort);

	public:
		/**
		 * @brief Merge-Insertion-Sort Algorithm using double linked lists
		 */
		static void merge_sort(std::list<int> &list);
};

#endif

