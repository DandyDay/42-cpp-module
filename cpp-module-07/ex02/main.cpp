#include <iostream>
#include <string>
#include <exception>
#include "Array.hpp"

int main( void )
{
	Array<int> array(5);
	for (unsigned int i = 0; i < array.size(); i++)
		std::cout << "array[" << i << "]: " << array[i] << std::endl;

	std::cout << std::endl;
	array[3] = 3;
	for (unsigned int i = 0; i < array.size(); i++)
		std::cout << "array[" << i << "]: " << array[i] << std::endl;

	try {
		std::cout << "array[" << 7 << "]: " << array[7] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
