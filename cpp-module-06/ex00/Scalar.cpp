#include "Scalar.hpp"
#include <iostream>
#include <sstream>

Scalar::Scalar(std::string &literal)
{
	this->value.d = 0;
	this->type = UNDEFINED;
	if (parseChar(literal))
		return;
	if (parseInt(literal))
		return;
	if (parseFloat(literal))
		return;
	if (parseDouble(literal))
		return;
}

Scalar::Scalar()
{
}

Scalar::Scalar(const Scalar &other)
{
	this->value = other.value;
	this->type = other.type;
}

Scalar &Scalar::operator=(const Scalar &other)
{
	if (this != &other)
	{
		this->value = other.value;
		this->type = other.type;
	}
	return *this;
}

Scalar::~Scalar()
{
}

int Scalar::getType()
{
	return type;
}

union value Scalar::getValue()
{
	return value;
}

bool Scalar::parseChar(std::string &literal)
{
	if (literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'')
	{
		this->type = CHAR;
		this->value.c = literal[1];
		return true;
	}
	else
		return false;
}

bool Scalar::parseInt(std::string &literal)
{
	std::stringstream ss(literal);
	int i;
	ss >> i;
	if (ss.eof() && !ss.fail())
	{
		this->value.i = i;
		this->type = INT;
		return true;
	}
	else
		return false;
}

bool Scalar::parseFloat(std::string &literal)
{
	if (literal[literal.size() - 1] != 'f')
		return false;
	std::stringstream ss(literal.substr(0, literal.size() - 1));
	float f;
	ss >> f;
	if (ss.eof() && !ss.fail())
	{
		this->value.f = f;
		this->type = FLOAT;
		return true;
	}
	else
		return false;
}

bool Scalar::parseDouble(std::string &literal)
{
	std::stringstream ss(literal);
	double d;
	ss >> d;
	if (ss.eof() && !ss.fail())
	{
		this->value.d = d;
		this->type = DOUBLE;
		return true;
	}
	else
		return false;
}
