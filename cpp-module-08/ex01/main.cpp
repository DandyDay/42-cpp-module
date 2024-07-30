#include "Span.hpp"
#include <deque>
#include <iostream>
#include <string>

int main(void)
{
	{
		std::cout << "TEST 1 - basic test" << std::endl;
		Span sp = Span(5);
		sp.addNumber(-2147483648);
		sp.addNumber(2147483647);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "\nTEST 2 - addNumbers test" << std::endl;
		std::deque<int> d;
		d.push_back(17);
		d.push_back(6);
		d.push_back(3);
		Span sp = Span(5);
		sp.addNumbers(d.begin(), d.end());
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	try
	{
		std::cout << "\nTEST 3 - span overflow test" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(12);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "\nTEST 4 - few arguments test" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
