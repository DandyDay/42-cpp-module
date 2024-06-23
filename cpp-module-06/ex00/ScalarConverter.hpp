#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "Scalar.hpp"
#include <string>

class ScalarConverter
{
public:
	static void convert(std::string &literal);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();
};

#endif
