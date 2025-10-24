#ifndef EASYFIND_TPP
# define EASYFIND_TPP

template<typename T>
typename T::iterator easyfind(T &container, int size)
{
	typename T::iterator it = container.begin();
	typename T::iterator end = container.end();
	while (it != end)
	{
		if (*it == size)
			return (it);
		it++;
	}
	throw (CantFindException());
}

#endif