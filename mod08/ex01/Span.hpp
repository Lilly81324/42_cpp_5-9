#ifndef SPAN_HPP
# define SPAN_HPP

#include <exception>
#include <vector>
#include <iostream>
#include <sys/time.h>
#include <list>
#include <set>

class SpanLimitException: public std::exception
{
	public:
		const char *what() const throw() \
			{ return "Error: Insertion would exceed Span Limit" ; }
};

class SpanEntryException: public std::exception
{
	public:
		const char *what() const throw() \
			{ return "Error: Cannot get Span from less then 2 entries" ; }
};

class Span
{
	public:
		Span(unsigned int size);
		~Span();

		/**
		 * @brief Add number to Span
		 * @warning throws Exception when entry limit exceeded
		 * 
		 * Calling this function x times, takes y seconds
		 *     20.000 = .01s
		 *    200.000 = .1s
		 *  2.000.000 = 1s
		 * 20.000.000 = 13s
		 */
		void addNumber(int entry);

		/**
		 * @brief Adds numbers from vector to Span
		 * @warning May throw Exception when entry limit exceeded
		 */
		void addRange(const std::vector<int> &range);

		/**
		 * @brief Adds numbers in range to Span
		 * @param start Initial number
		 * @param end Last possible number (inclusive)
		 * @param increase Change between each numbers (1, 4, 7, 10 => increase = 3)
		 * @warning May throw Exception when entry limit exceeded
		 * 
		 * @example addrange(1, 13, 4) => [1, 5, 9, 13]
		 * @example addrange(-1, -6, -2) => [-1, -3, -5]
		 */
		void addRange(int start, int end, int increase);

		/**
		 * @brief Get smallest difference between numbers
		 * 
		 * Iterates over the sorted Array, 
		 * sorting assures the next number will be the next smallest number.
		 * Then check the current smallest difference against the current difference
		 * If the new one is smaller, store that as current smallest
		 * Calling with array of x elements, takes y seconds
		 *    400.000 = .01s
		 *  4.000.000 = .1s
		 * 40.000.000 = 1s
		 */
		unsigned int shortestSpan();

		/**
		 * @brief Get biggest difference between numbers
		 * @note arr.end() is just AFTER the last element, so has to be decreased
		 * 
		 * Since array is sorted, biggest number is at the end,
		 * and smallest is at the start, so just return their diff
		 */
		unsigned int longestSpan();
	private:
		unsigned int limit;
		unsigned int entries;
		std::multiset<int> arr;
};

#endif