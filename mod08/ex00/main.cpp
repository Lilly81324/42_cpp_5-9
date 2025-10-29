#include "easyfind.hpp"

template<typename T>
void look_for(T cont, int target)
{
	try
	{
		typename T::iterator it = easyfind(cont, target);
		if (*it == target)
			std::cout << "Value found";
		else
			std::cout << "Value NOT found";
	}
	catch (const CantFindException &e)
	{
		std::cout << e.what() << " (" << target << ')';
	}
}

// For push_back
template<typename T>
void test(T &v)
{
	std::cout << "  Empty Container" << std::endl;
	std::cout << "    ";
	look_for(v, 0);
	std::cout << std::endl;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	std::cout << "  Value in Container" << std::endl;
	std::cout << "    ";
	look_for(v, 2);
	std::cout << std::endl;
	std::cout << "  Value not in Container" << std::endl;
	std::cout << "    ";
	look_for(v, 4);
	std::cout << std::endl;
}

// For insert
template<typename T>
void test2(T &v)
{
	std::cout << "  Empty Container" << std::endl;
	std::cout << "    ";
	look_for(v, 0);
	std::cout << std::endl;
	v.insert(1);
	v.insert(2);
	v.insert(3);
	std::cout << "  Value in Container" << std::endl;
	std::cout << "    ";
	look_for(v, 2);
	std::cout << std::endl;
	std::cout << "  Value not in Container" << std::endl;
	std::cout << "    ";
	look_for(v, 4);
	std::cout << std::endl;
}

int main(void)
{
	{
		std::cout << '\n' << "Testing Vector ---------" << std::endl;
		std::vector<int> v;
		test(v);
	}
	{
		std::cout << '\n'  << "Testing Dequeue --------" << std::endl;
		std::deque<int> v;
		test(v);
	}
	{
		std::cout << '\n'  << "Testing List -----------" << std::endl;
		std::list<int> v;
		test(v);
	}
	{
		std::cout << '\n'  << "Testing Set ------------" << std::endl;
		std::set<int> v;
		test2(v);
	}
	{
		std::cout << '\n'  << "Testing Multiset ------------" << std::endl;
		std::multiset<int> v;
		test2(v);
	}
	// Arrays and forward_lists are C++11 and later :c
	// Maps are associative containers, which are mostly the same, but take lots of effort
	// Unsorted Containers are basically the same
	// Container Adapters just use the existing containers
	return (0);
}