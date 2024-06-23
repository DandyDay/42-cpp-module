#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "usage: ./convert [literal]" << std::endl;
		return EXIT_FAILURE;
	}

	std::string literal(argv[1]);
	ScalarConverter::convert(literal);
	return EXIT_SUCCESS;
}
