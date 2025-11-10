/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:38:48 by sikunne           #+#    #+#             */
/*   Updated: 2025/11/10 18:41:32 by sikunne          ###   ########.fr       */
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

template<typename T>
class CPair
{
	public:
		T first;
		T second;

		CPair(T &a, T &b): first(a), second(b)
		{
			if (a > b)
			{
				first = b;
				second = a;
			}
		}

		bool operator<(const CPair &other)
		{
			return (this->second < other.second);
		}

		bool operator>(const CPair &other)
		{
			return (this->second > other.second);
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

