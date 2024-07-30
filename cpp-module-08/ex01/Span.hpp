#ifndef SPAN_HPP
#define SPAN_HPP

#include <set>
#include <stdexcept>

class Span
{
public:
	Span(unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(int n);
	int shortestSpan();
	int longestSpan();

	template <typename Iterator> void addNumbers(Iterator begin, Iterator end)
	{
		if (end - begin < 0)
			throw std::invalid_argument("invalid argument");
		else if (end - begin + s.size() > maxSize)
			throw std::length_error("max size exceeded!");
		else
			s.insert(begin, end);
	}

private:
	Span();

	unsigned int maxSize;
	std::set<int> s;
};

#endif
