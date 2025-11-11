/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:38:48 by sikunne           #+#    #+#             */
/*   Updated: 2025/11/11 14:29:49 by sikunne          ###   ########.fr       */
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
#include <utility>

// template<typename T>
// class CPair
// {
// 	public:
// 		T first;
// 		T second;

// 		CPair(T &a, T &b): first(a), second(b)
// 		{
// 			if (a > b)
// 			{
// 				first = b;
// 				second = a;
// 			}
// 		}

// 		bool operator<(const CPair &other)
// 		{
// 			return (this->second < other.second);
// 		}

// 		bool operator>(const CPair &other)
// 		{
// 			return (this->second > other.second);
// 		}
// };
#include <math.h>
class CPair
{
	public:
		int depth;
		int* a1;
		int* a2;
		int* b1;
		int* b2;


		CPair(int *first, int *second, int depth): depth(depth)
		{
			a1 = first - ((int)pow(2, depth) - 1);
			a2 = first;
			b1 = second - ((int)pow(2, depth) - 1);
			b2 = second;
			if (*a2 > *b2)
			{
				a1 = b1;
				a2 = b2;
				b1 = first - ((int)pow(2, depth) - 1);
				b2 = first;
			}
		}

		bool operator<(const CPair &other)
		{
			return (*(this->b2) < *(other.b2));
		}

		bool operator>(const CPair &other)
		{
			return (*(this->b2) > *(other.b2));
		}
};

/**
 * Stat sheet: 
 */
class VectorSort
{
	private:

	public:

		VectorSort(void);
		VectorSort(const VectorSort &other);
		~VectorSort(void);
		VectorSort &operator=(const VectorSort &other);

		/**
		 * @brief Merge-Insertion-Sort Algorithm using vectors
		 */
		static void merge_sort(std::vector<int> &list);
};

#endif

