#include "Array.hpp"
#include <exception>
#include <iostream>

int main(void)
{
	Array<int> array(5);
	for (unsigned int i = 0; i < array.size(); i++)
		std::cout << "array[" << i << "]: " << array[i] << std::endl;

	std::cout << std::endl;
	array[1] = 1;
	array[3] = 3;
	Array<int> array2(array);
	array2[1] = 4;

	for (unsigned int i = 0; i < array.size(); i++)
		std::cout << "array[" << i << "]: " << array[i] << std::endl;
	for (unsigned int i = 0; i < array2.size(); i++)
		std::cout << "array2[" << i << "]: " << array2[i] << std::endl;

	try
	{
		std::cout << "array[" << 7 << "]: " << array[7] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
