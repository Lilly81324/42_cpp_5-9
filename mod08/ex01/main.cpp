/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:06:56 by sikunne           #+#    #+#             */
/*   Updated: 2025/10/28 16:06:57 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#define SUBJECT_COUNT 10000

void fillSpan(Span &span, int count)
{
	for (int i = 0; i < count; i++)
	{
		span.addNumber(i);
	}
}

bool tryShortest(Span &span, int target)
{
	try
	{
		int s = span.shortestSpan();
		std::cout << "Shortest Span: " << s  << " expected: " << target << std::endl;
		return (true);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (false);
	}
}

bool tryLongest(Span &span, int target)
{
	try
	{
		int s = span.longestSpan();
		std::cout << "Longest Span: " << s  << " expected: " << target << std::endl;
		return (true);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (false);
	}
}

bool tryAdd(Span &span, int target)
{
	try
	{
		span.addNumber(target);
		return (true);
	}
	catch(const std::exception& e)
	{
		return (false);
	}
}

bool tryAddRange(Span &span, int start, int end, int increase)
{
	try
	{
		span.addRange(start, end, increase);
		return (true);
	}
	catch(const std::exception& e)
	{
		return (false);
	}
}

bool tryAddVector(Span &span, const std::vector<int> &vec)
{
	try
	{
		span.addRange(vec);
		return (true);
	}
	catch(const std::exception& e)
	{
		return (false);
	}
}

int main(void)
{
	{ // from subject.pdf
		std::cout << std::endl << "--== Mandatory part (subject) ==--" << std::endl;
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	{ // Simple adding
		std::cout << std::endl << "--== Simple test (2, 5, 9, 10) ==--" << std::endl;
		Span span(4);
		span.addNumber(2);
		span.addNumber(5);
		span.addNumber(9);
		span.addNumber(10);
		std::cout << "Longest Range: " << span.longestSpan() << std::endl;
		std::cout << "Shortest Range: " << span.shortestSpan() << std::endl;
	}

	{ // Adding via Range
		std::cout << std::endl << "--== Adding numbers through ranges ==--" << std::endl;
		Span span(10);
		std::vector<int> vec;
		vec.push_back(2);
		vec.push_back(4);
		vec.push_back(6);
		vec.push_back(8);
		span.addRange(vec);
		// [2, 4, 6, 8]
		std::cout << "Longest Span: " << span.longestSpan() << std::endl;
		std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;
		span.addRange(0, 27, 9);
		// [0, 2, 4, 6, 8, 9, 18, 27]
		std::cout << "Longest Span: " << span.longestSpan() << std::endl;
		std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;
	}

	{ // Lots of adding
		// Can go up to 200 * SUBJECT_COUNT, but NOT with valgrind
		std::cout << std::endl << "--== Very long list (" << 20 * SUBJECT_COUNT <<  ") ==--" << std::endl;
		Span span(20 * SUBJECT_COUNT);
		span.addRange(1, 20 * SUBJECT_COUNT, 1);
		std::cout << "Longest Span: " << span.longestSpan() << std::endl;
		std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;
	}

	{ // shortest and longest Span Exceptions
		std::cout << std::endl << "--== shortestSpan and longestSpan ==--" << std::endl;
		bool success = false;
		Span span(3);
		success = success | tryShortest(span, 0);
		success = success | tryLongest(span, 0);
		span.addNumber(5);
		success = success | tryShortest(span, 0);
		success = success | tryLongest(span, 0);
		span.addNumber(10);
		span.addNumber(12);
		success = success | !tryShortest(span, 2);
		success = success | !tryLongest(span, 7);
		if (!success)
			std::cout << "All Operations done correctly" << std::endl;
		else
			std::cout << "Some Operation that shouldn't work, worked" << std::endl;
	}

	{ // Edge Case - Empty Span
		std::cout << std::endl << "--== Edge Case - Empty Span ==--" << std::endl;
		bool success = false;
		Span span(0);
		success = success | tryAdd(span, 0);
		success = success | tryAdd(span, 1);
		success = success | tryAddRange(span, 0, 1, 1);
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(3);
		success = success | tryAddVector(span, vec);
		if (!success)
			std::cout << "All Operations done correctly" << std::endl;
		else
			std::cout << "Some Operation that shouldn't work, worked" << std::endl;
	}

	{ // Edge Case - Small Span
		std::cout << std::endl << "--== Edge Case - Small Span ==--" << std::endl;
		bool success = false;
		Span span(1);
		span.addNumber(5);
		success = success | tryAdd(span, 0);
		success = success | tryAdd(span, 1);
		success = success | tryAddRange(span, 0, 1, 1);
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(3);
		success = success | tryAddVector(span, vec);
		if (!success)
			std::cout << "All Operations done correctly" << std::endl;
		else
			std::cout << "Some Operation that shouldn't work, worked" << std::endl;
	}

	{ // Edge Case - Wrong Order Range
		std::cout << std::endl << "--== Edge Case - Wrong Order Range ==--" << std::endl;
		Span span(3);
		span.addNumber(0);
		span.addNumber(10);
		// No increase -> No numbers
		span.addRange(1, 2, 0);
		// Increase will never reach end -> No numbers
		span.addRange(1, 2, -1);
		// Increase will never reach end -> No numbers
		span.addRange(2, 1, 1);
		// Check that nothing was added
		if ((span.shortestSpan() == 10) && (span.longestSpan() == 10))
			std::cout << "All Operations done correctly" << std::endl;
		else
			std::cout << "Some Operation that shouldn't work, worked" << std::endl;
	}

	return (0);
}
