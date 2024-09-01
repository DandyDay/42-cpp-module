#include "PmergeMe.hpp"
#include <iostream>
#include <vector>


int main(int argc, char **argv)
{
	try
	{
		if (argc < 2)
		{
			std::cout << "usage: ./PmergeMe [list of numbers]" << std::endl;
			return 1;
		}
		PmergeMe pmergeMe(argc, argv);
		pmergeMe.analyze();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
