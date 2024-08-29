#include "PmergeMe.hpp"
#include <iostream>
#include <vector>

void leak()
{
	system("leaks PmergeMe");
}

int main(int argc, char **argv)
{
	atexit(leak);
	try
	{
		if (argc < 2)
		{
			std::cout << "usage: ./PmergeMe [list of numbers]" << std::endl;
			return 1;
		}
		PmergeMe pmergeMe(argc, argv);
		pmergeMe.printResult();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
