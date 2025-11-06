#include "RPN.hpp"

// Load given Argument into function
// Calculate result
// Return result or Error
// Stop

// Available:
// deque
// map
// multiset
// multimap
// stack
// queue
// priority_queue

// Good Containers:
// stack of deque
// Need to push to top, access top, pop top

// read characters until space or end
// number -> push
// operator -> top, top, pop, pop, push
// return top element of stack

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid Arg Count, only one please" << std::endl;
		return (0);
	}

	RpnCaller rpn;
	std::string error;
	int result;

	result = rpn.handle(argv[1]);
	error = rpn.getError();
	if (error.size() != 0)
		std::cout << error << std::endl;
	else
		std::cout << "Result: " << result << std::endl;
	return (0);
}