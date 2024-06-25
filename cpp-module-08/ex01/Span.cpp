#include "Span.hpp"
Span::Span() : maxSize(0)
{
}

Span::Span(unsigned int N) : maxSize(N)
{
}

Span::Span(const Span &other) : maxSize(other.maxSize)
{
	for (unsigned int i = 0; i < other.maxSize; i++)
		v.push_back(other.v[i]);
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		v.clear();
		this->maxSize = other.maxSize;
		for (unsigned int i = 0; i < other.maxSize; i++)
			v.push_back(other.v[i]);
	}
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
	if (v.size() >= this->maxSize)
		throw std::length_error("max size exceeded!");
	else
		v.push_back(n);
}

unsigned int Span::shortestSpan()
{
	if (v.size() <= 1)
		throw std::length_error("too few arguemnts!");
	else
	{
		std::sort(v.begin(), v.end());
		int min = v[1] - v[0];
		for (unsigned int i = 0; i < v.size() - 1; i++)
		{
			if (min > v[i + 1] - v[i])
				min = v[i + 1] - v[i];
		}
		return min;
	}
}

unsigned int Span::longestSpan()
{
	if (v.size() <= 1)
		throw std::length_error("too few arguemnts!");
	else
	{
		std::sort(v.begin(), v.end());
		return v[v.size() - 1] - v[0];
	}
}
