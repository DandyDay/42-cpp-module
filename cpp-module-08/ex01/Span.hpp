#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

class Span
{
public:
	Span();
	Span(unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(int n);
	template <typename Iterator>
	void addNumbers(Iterator begin, Iterator end)
	{
		if (end - begin < 0)
			throw std::invalid_argument("invalid argument");
		else if (end - begin + v.size() > maxSize)
			throw std::length_error("max size exceeded!");
		else
			v.insert(v.begin(), begin, end);
	}

	unsigned int shortestSpan();
	unsigned int longestSpan();
private:
	std::vector<int> v;
	unsigned int maxSize;
};

#endif
