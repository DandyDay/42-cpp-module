#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& container, unsigned int val)
{
	return std::find(container.begin(), container.end(), val);
}

#endif
