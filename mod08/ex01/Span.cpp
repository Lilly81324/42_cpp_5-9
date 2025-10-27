#include "Span.hpp"

Span::Span(unsigned int size)
{
	this->limit = size;
	this->entries = 0;
	try
	{
		// arr.reserve(size);
		arr.clear();
	}
	catch (const std::exception &e)
	{
		this->limit = 0;
	}
}

Span::~Span()
{
	if (this->limit > 0)
		arr.clear();
}

void Span::addNumber(int entry)
{
	// If adding would exceed limit, throw error
	if (this->entries + 1 > this->limit)
		throw (SpanLimitException());
	this->arr.insert(entry);
	this->entries++;
}

/**
 * @brief Get biggest difference between numbers
 * @note arr.end() is just AFTER the last element, so has to be decreased
 * 
 * Since array is sorted, biggest number is at the end,
 * and smallest is at the start, so just return their diff
 */
unsigned int Span::longestSpan()
{
	if (this->entries < 2)
		throw(SpanEntryException());
	std::multiset<int>::const_iterator end = arr.end();
	end--;
	return (*end - *arr.begin());
}

/**
 * @brief Get smallest difference between numbers
 * 
 * Iterates over the sorted Array, 
 * sorting assures the next number will be the next smallest number.
 * Then check the current smallest difference against the current difference
 * If the new one is smaller, store that as current smallest
 */
unsigned int Span::shortestSpan()
{
	if (this->entries < 2)
		throw(SpanEntryException());

	std::multiset<int>::const_iterator end = arr.end();
	std::multiset<int>::const_iterator it = arr.begin();
	std::multiset<int>::const_iterator next = arr.begin();
	next++;

	unsigned int bestRange = *next - *it;
	for (; next != end; next++)
	{
		if ((unsigned int)(*next) - (*it) < bestRange)
			bestRange = (*next) - (*it);
		it = next;
	}
	return (bestRange);
}