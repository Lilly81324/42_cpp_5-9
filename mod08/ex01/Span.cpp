/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:06:53 by sikunne           #+#    #+#             */
/*   Updated: 2025/10/29 18:19:24 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void Span::addRange(const std::vector<int> &range)
{
	std::vector<int>::const_iterator it = range.begin();
	std::vector<int>::const_iterator end = range.end();
	for (; it != end; it++)
		this->addNumber(*it);
}

void Span::addRange(int start, int end, int increase)
{	
	// No Direction
	if (increase == 0)
		return ;

	// Direction is positive, but increase is negative
	if (start < end && increase <= 0)
		return ;
	
	// Direction is negative, but increase is positive
	if (start > end && increase >= 0)
		return ;

	// Keep adding numbers
	while (start <= end)
	{
		this->addNumber(start);
		start += increase;
	}
}

unsigned int Span::shortestSpan()
{
	if (this->entries < 2)
		throw(SpanEntryException());
	
	std::multiset<int>::const_iterator end = arr.end();
	std::multiset<int>::const_iterator it = arr.begin();
	std::multiset<int>::const_iterator next = arr.begin();
	next++;

	unsigned int bestRange = *next - *it;
	unsigned int diff;
	for (; next != end; next++)
	{
		diff = (unsigned int)(*next) - (unsigned int)(*it);
		if (diff < bestRange)
			bestRange = diff;
		it = next;
	}
	return (bestRange);
}

unsigned int Span::longestSpan()
{
	if (this->entries < 2)
		throw(SpanEntryException());
	std::multiset<int>::const_iterator end = arr.end();
	end--;
	return (*end - *arr.begin());
}
