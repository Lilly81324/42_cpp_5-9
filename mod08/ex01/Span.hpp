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
			{ return "Error: Cannot make span less then 2 entrie" ; }
};

class Span
{
	public:
		std::multiset<int> arr;
		Span(unsigned int size);
		~Span();
		void addNumber(int entry);
		unsigned int shortestSpan();
		unsigned int longestSpan();
	private:
		unsigned int limit;
		unsigned int entries;
};

#endif