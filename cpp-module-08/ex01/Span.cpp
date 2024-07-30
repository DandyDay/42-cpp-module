#include "Span.hpp"
Span::Span() : maxSize(0), s(std::set<int>())
{
}

Span::Span(unsigned int N) : maxSize(N), s(std::set<int>())
{
}

Span::Span(const Span &other)
	: maxSize(other.maxSize), s(std::set<int>(other.s))
{
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		s.clear();
		this->maxSize = other.maxSize;
		s = std::set<int>(other.s);
	}
	return *this;
}

Span::~Span()
{
	s.clear();
}

void Span::addNumber(int n)
{
	if (s.size() >= this->maxSize)
		throw std::length_error("max size exceeded!");
	else if (!s.insert(n).second)
		throw std::invalid_argument("duplicated element inserted!");
}

int Span::shortestSpan()
{
	if (s.size() <= 1)
		throw std::length_error("too few arguemnts!");
	else
	{
		int min = 2147483647;
		std::set<int>::iterator it = s.begin();
		int prevVal = *(it++);
		for (; it != s.end(); it++)
		{
			if (min > *it - prevVal)
				min = *it - prevVal;
			prevVal = *it;
		}
		return min;
	}
}

int Span::longestSpan()
{
	if (s.size() <= 1)
		throw std::length_error("too few arguemnts!");
	else
	{
		int maxVal = *(--s.end());
		int minVal = *s.begin();
		return maxVal - minVal;
	}
}
