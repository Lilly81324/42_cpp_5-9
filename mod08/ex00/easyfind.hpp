#ifndef EASYFIND_HPP
# define EASYFIND_HPP

// For throwing std::exceptions
#include <exception>

// For the different containers
#include <vector>
#include <deque>
#include <list>
#include <set> 

// For writing to terminal
#include <iostream>

class CantFindException : public std::exception
{
	public:
		virtual const char *what() const throw()
			{ return ("Error: Could not find value"); }
};

template<typename T>
typename T::iterator easyfind(T &container, int target);

// Include Definition AFTER Declaration, but BEFORE Usage
#include "easyfind.tpp"

#endif