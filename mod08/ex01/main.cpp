#include "Span.hpp"

#define SUBJECT_COUNT 10000

void fillSpan(Span &span, int count)
{
	for (int i = 0; i < count; i++)
	{
		span.addNumber(i);
	}
}

int main(void)
{
	{
		std::cout << std::endl << "--== Simple test (2, 5, 9, 10) ==--" << std::endl;
		Span span(4);
		span.addNumber(2);
		span.addNumber(5);
		span.addNumber(9);
		span.addNumber(10);
		std::cout << "Longest Range: " << span.longestSpan() << std::endl;
		std::cout << "Shortest Range: " << span.shortestSpan() << std::endl;
	}
	{
		std::cout << std::endl << "--== Very long list (" << 200 * SUBJECT_COUNT <<  ") ==--" << std::endl;
		Span span(200 * SUBJECT_COUNT);
		fillSpan(span, 200 * SUBJECT_COUNT);
		std::cout << "Longest Span: " << span.longestSpan() << std::endl;
		std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;
	}
	return (0);
}