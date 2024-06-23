#include "ScalarConverter.hpp"
#include "utils.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>

void ScalarConverter::convert(std::string &literal)
{
	Scalar s(literal);
	int integer;
	std::cout << std::fixed << std::setprecision(1);
	switch (s.getType())
	{
	case CHAR:
		printScalar(s.getValue().c, true);
		printScalar(static_cast<int>(s.getValue().c), true);
		printScalar(static_cast<float>(s.getValue().c), true);
		printScalar(static_cast<double>(s.getValue().c), true);
		break;

	case INT:
		if (s.getValue().i > std::numeric_limits<char>::max() ||
			s.getValue().i < std::numeric_limits<char>::min())
			printScalar(static_cast<char>(s.getValue().i), false);
		else
			printScalar(static_cast<char>(s.getValue().i), true);
		printScalar(s.getValue().i, true);
		printScalar(static_cast<float>(s.getValue().i), true);
		printScalar(static_cast<double>(s.getValue().i), true);
		break;

	case FLOAT:
		integer = literal.size() - literal.rfind('.') - 2;
		if (integer > 0)
			std::cout << std::setprecision(integer);
		if (s.getValue().f > std::numeric_limits<char>::max() ||
			s.getValue().f < std::numeric_limits<char>::min())
			printScalar(static_cast<char>(s.getValue().f), false);
		else
			printScalar(static_cast<char>(s.getValue().f), true);
		if (s.getValue().f > std::numeric_limits<int>::max() ||
			s.getValue().f < std::numeric_limits<int>::min())
			printScalar(static_cast<int>(s.getValue().f), false);
		else
			printScalar(static_cast<int>(s.getValue().f), true);
		printScalar(s.getValue().f, true);
		printScalar(static_cast<double>(s.getValue().f), true);
		break;

	case DOUBLE:
		integer = literal.size() - literal.rfind('.') - 1;
		if (integer > 0)
			std::cout << std::setprecision(integer);
		if (s.getValue().d > std::numeric_limits<char>::max() ||
			s.getValue().d < std::numeric_limits<char>::min())
			printScalar(static_cast<char>(s.getValue().d), false);
		else
			printScalar(static_cast<char>(s.getValue().d), true);
		if (s.getValue().d > std::numeric_limits<int>::max() ||
			s.getValue().d < std::numeric_limits<int>::min())
			printScalar(static_cast<int>(s.getValue().d), false);
		else
			printScalar(static_cast<int>(s.getValue().d), true);
		if (s.getValue().d > std::numeric_limits<float>::max() ||
			s.getValue().d < std::numeric_limits<float>::min())
			printScalar(static_cast<float>(s.getValue().d), false);
		else
			printScalar(static_cast<float>(s.getValue().d), true);
		printScalar(s.getValue().d, true);
		break;

	default:
		std::cout << literal << ": not scalar" << std::endl;
		break;
	}
}

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}
