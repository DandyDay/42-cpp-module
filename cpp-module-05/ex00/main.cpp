#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	// Test 1
	std::cout << "----------Test 1----------" << std::endl;
	try
	{
		Bureaucrat b1("bureaucrat 1", 1);
		Bureaucrat b2("bureaucrat 2", 75);
		Bureaucrat b3("bureaucrat 3", 150);

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << b3 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// Test 2
	std::cout << "----------Test 2----------" << std::endl;
	try
	{
		Bureaucrat b1("bureaucrat 1", 1);
		std::cout << b1 << std::endl;

		b1.incrementGrade();
		std::cout << b1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// Test 3
	std::cout << "----------Test 3----------" << std::endl;
	try
	{
		Bureaucrat b1("bureaucrat 1", 150);
		std::cout << b1 << std::endl;

		b1.decrementGrade();
		std::cout << b1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// Test 4
	std::cout << "----------Test 4----------" << std::endl;
	try
	{
		Bureaucrat b1("bureaucrat 1", 0);
		std::cout << b1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	// Test 5
	std::cout << "----------Test 5----------" << std::endl;
	try
	{
		Bureaucrat b1("bureaucrat 1", 151);
		std::cout << b1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
