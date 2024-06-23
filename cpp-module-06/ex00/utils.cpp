#include <iomanip>
#include <iostream>

void printScalar(char c, bool possible)
{
	std::cout << "char: ";
	if (possible)
	{
		if (std::isprint(c))
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
}

void printScalar(int i, bool possible)
{
	std::cout << "int: ";
	if (possible)
		std::cout << i << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void printScalar(float f, bool possible)
{
	std::cout << "float: ";
	if (possible)
		std::cout << f << "f" << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void printScalar(double d, bool possible)
{
	std::cout << "double: ";
	if (possible)
		std::cout << d << std::endl;
	else
		std::cout << "impossible" << std::endl;
}
