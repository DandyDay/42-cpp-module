#include <iostream>
#include "easyfind.hpp"
#include <vector>
#include <queue>

int main( void )
{
	std::vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i*2 + 1);
	if (easyfind(v, 5) != v.end())
		std::cout << "Found 5 in vector" << std::endl;
	else
		std::cout << "Not found." << std::endl;

	std::deque<int> d;
	for (int i = 0; i < 10; i++)
		d.push_back(i*2);
	if (easyfind(d, 5) != d.end())
		std::cout << "Found 5 in deque" << std::endl;
	else
		std::cout << "Not found." << std::endl;


	return 0;
}
