#include <iostream>
#include <string>
#include "iter.hpp"

void printInt(int i)
{
	std::cout << "int: " << i << std::endl;
}

void printString(std::string s)
{
	std::cout << "string: " << s << std::endl;
}

int main( void )
{
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 42};
	iter(arr, 10, printInt);

	std::string arr2[3] = {"jinhchoi", "42seoul", "gaepodong-station"};
	iter(arr2, 3, printString);

	return 0;
}
