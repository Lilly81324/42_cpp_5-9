/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:15:35 by sikunne           #+#    #+#             */
/*   Updated: 2025/11/07 18:15:36 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Good Containers:
// vector	Great for binary insertion, due to random acces with subscript operator
// list		Insertion and Deletion of numbers in the middle without reallocation

// Used Containers:
// std::vector, std::list, std::set

void print_duration(const timeval &past, const timeval &present)
{
	long s = present.tv_sec - past.tv_sec;
	long micros = present.tv_usec - past.tv_usec;

	if (micros < 0)
	{
		micros += 1000000;
		s -= 1;
	}

	std::cout << std::fixed << std::setprecision(5) << std::setw(9) << ((double)s + ((double)micros / (double)1000000)) << "s (" << \
	s << " s, " << micros << " us)" << std::endl;
}

void test_result(int contSize, const std::string &contType, timeval &past, timeval &present)
{
	std::cout << "Time to process a range of " << std::setw(6) << contSize << " elements with ";
	std::cout << contType << " : ";
	print_duration(past, present);
}

template<typename T>
bool isSorted(T list)
{
	typename T::const_iterator it = list.begin();
	typename T::const_iterator next = list.begin();
	typename T::const_iterator end = list.end();
	if (next != end)
		next++;

	// if odd, next = end
	// if even, oob
	for (; next != end; next++)
	{
		if (*it > *next)
			return (false);
		it = next;
	}
	return (true);
}

template<typename T>
void printContainer(T list)
{
	typename T::const_iterator it = list.begin();
	typename T::const_iterator end = list.end();

	if (it != end)
	{
		std::cout << *it;
		it++;
	}
	for (; it != end; it++)
		std::cout << " " << *it;
}

bool addNumber(int &num, std::list<int> &lst, std::set<int> &unique)
{
	if (num == -1)
		return (true);
	if (unique.insert(num).second == false)
		return (false);
	lst.push_back(num);
	num = -1;
	return (true);
}

bool makeListPart(const char *input, std::list<int> &lst, std::set<int> &unique, std::string &errMsg)
{
	int curNum = -1;
	char cur;

	if (input == NULL)
		return (true);
	for (int i = 0; input[i] != '\0'; i++)
	{
		cur = input[i];
		// if digit, add it to current number
		if (isdigit(cur))
		{
			if (curNum == -1)
				curNum = 0;
			curNum *= 10;
			curNum += (cur - '0');
		}
		// If space and number exists, try to add it
		else if (isspace(cur))
		{
			// If number is not unique
			if (!addNumber(curNum, lst, unique))
			{
				errMsg = "Error: No duplicates allowed";
				return (false);
			}
		}
		// If other char, return error
		else
		{
			// Special case for neg numbers
			errMsg = "Error: Only numbers as argument, found ";
			errMsg += cur;
			if (cur == '-')
				errMsg = "Error: Only positive numbers";
			return (false);
		}
	}
	// If number is not unique
	if (!addNumber(curNum, lst, unique))
	{
		errMsg = "Error: No duplicates allowed";
		return (false);
	}
	return (true);
}

int main(int argc, char **argv)
{
	// Main Containers
	std::vector<int> vec;
	std::list<int> lst;

	// For verifying no doubles
	std::set<int> unique;

	// For copying the list into vector
	std::list<int>::iterator it;
	std::list<int>::iterator end;

	// For outputting
	std::string errMsg;
	struct timeval pastVec;
	struct timeval presentVec;
	struct timeval pastLst;
	struct timeval presentLst;


	// Argc check
	if (argc < 2)
	{
		std::cerr << "Error: No Arguments given" << std::endl;
		return (1);
	}

	// For all arguments
	for (int i = 1; i < argc; i++)
	{
		if (makeListPart(argv[i], lst, unique, errMsg) == false)
		{
			std::cerr << errMsg << std::endl;
			return (1);
		}
	}

	// Copy finished list into vector
	it = lst.begin();
	end = lst.end();
	for (; it != end; it++)
		vec.push_back(*it);

	// First line
	std::cout << "Before:            " ;
	printContainer(vec);
	std::cout << std::endl;

	// Sorting
	gettimeofday(&pastVec, 0);
	VectorSort::merge_sort(vec);
	gettimeofday(&presentVec, 0);	
	gettimeofday(&pastLst, 0);
	ListSort::merge_sort(lst);
	gettimeofday(&presentLst, 0);

	// Checking for sorted
	if (!isSorted(vec) || !isSorted(lst))
	{
		std::cerr << "Sorting failed. This is a failed Evaluation" << std::endl;
		return (1);
	}

	// Second line
	std::cout << "Afer:              " ;
	printContainer(vec);
	std::cout << std::endl;

	// Third line
	test_result(vec.size(), "std::vector<int>", pastVec, presentVec);

	// Fourth line
	test_result(lst.size(), "std::list<int>  ", pastLst, presentLst);

	return (0);
}