#include "Span.hpp"

#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define SIZE 35000

/**
 * @brief Display duration between two timestamps
 * @note timestamps created with gettimeofday()
 */
void showTimestamp(const timeval &past, const timeval &present)
{
	long seconds;
	long microseconds;

	seconds = present.tv_sec - past.tv_sec;
	microseconds = present.tv_usec - past.tv_usec;

	if (microseconds < 0)
	{
		microseconds += 1000000;
		seconds -= 1;
	}

	std::cout << "Duration: " << seconds << " seconds and " << microseconds << " microseconds" << std::endl;
}

int main(void)
{
	struct timeval past;
	gettimeofday(&past, NULL);
	Span span(SIZE);
	for (int i = 0; i < SIZE; i++)
	{
		span.addNumber(i);
	}
	// span.addNumber(5);
	// span.addNumber(1);
	// span.addNumber(9);
	// span.addNumber(4);
	// span.addNumber(20);

	std::cout << "Shortest Range: " << span.shortestSpan() << std::endl;
	std::cout << "Longest Range: " << span.longestSpan() << std::endl;
	struct timeval present;
	gettimeofday(&present, NULL);
	showTimestamp(past, present);
	return (0);
}